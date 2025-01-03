#version 410 core

in vec3 fPosition;
in vec3 fNormal;
in vec2 fTexCoords;
in vec4 directionalLightSpacePosition;

out vec4 fColor;

const int MAX_NUMBER_OF_POINT_LIGHTS = 10;

struct Light{
	vec3 colour;
	float ambientIntensity;
	float diffuseIntensity;
};

struct DirectionalLight {
	vec3 direction;
	Light base;
};

struct PointLight {
	vec3 position;
	vec3 dimmingCoeffs;
	Light base;
};

struct Material {
	float specularIntensity;
	float shininess;
};

uniform sampler2D diffuseTexture;
uniform sampler2D directionalShadowMap;

uniform DirectionalLight directionalLight;
uniform Material material;
uniform PointLight pointLights[MAX_NUMBER_OF_POINT_LIGHTS];
uniform vec3 eyePosition;
uniform int pointLightCount;

float computeDirectionalShadowFactor(DirectionalLight light) {
	vec3 projCoords = directionalLightSpacePosition.xyz / directionalLightSpacePosition.w;
	projCoords = (projCoords * 0.5) + 0.5;
	float currentDepth = projCoords.z;

	vec3 normal = normalize(fNormal);
	vec3 lightDir = normalize(light.direction);
	float bias = max(0.05 * (1 - dot(normal, lightDir)), 0.05);

	float shadow = 0.0f;

	vec2 texelSize = 1.0f / textureSize(directionalShadowMap, 0);
	for(int x = -1; x <= 1; x++)
		for(int y = -1; y <= 1; y++) {
			float pcfDepth = texture(directionalShadowMap, projCoords.xy + vec2(x, y) * texelSize).r;
			shadow +=  (currentDepth - bias > pcfDepth) ? 1.0f : 0.0f;
	}
	shadow /= 9.0f; //divide by number of pixels used in pcf 

	if(projCoords.z > 1.0f)
		shadow = 0.0f;

	return shadow;
}

vec4 computeLightByDirection(Light light, vec3 dir, float shadowFactor) {
	vec4 ambientColour = vec4(light.colour * light.ambientIntensity, 1.0f);

	float diffuseFactor = max(dot(normalize(fNormal), normalize(dir)), 0.0f);
	vec4 diffuseColour = vec4((light.colour * light.diffuseIntensity * diffuseFactor), 1.0f);

	vec4 specularColour  = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	if(diffuseFactor > 0.0f) {
		vec3 fragToEye = normalize(eyePosition - fPosition);
		vec3 reflectedVertex = normalize(reflect(dir, normalize(fNormal)));
		float specularFactor = dot(fragToEye, reflectedVertex);
		if(specularFactor > 0.0f) {
			specularFactor = pow(specularFactor, material.shininess);
			specularColour = vec4(light.colour * material.specularIntensity * specularFactor, 1.0f);
		}
	}
	return ambientColour + (1.0f - shadowFactor) * (diffuseColour + specularColour);
}

vec4 computeDirectionalLight() {
	float shadowFactor = computeDirectionalShadowFactor(directionalLight);
	return computeLightByDirection(directionalLight.base, directionalLight.direction, shadowFactor);
}

vec4 computePointLights() {
	vec4 totalColour = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	for(int i = 0; i < pointLightCount; i++) {
		vec3 direction = fPosition - pointLights[i].position;
		float d = length(direction);
		direction = normalize(direction);
		
		vec4 colour = computeLightByDirection(pointLights[i].base, direction, 0.0f);
		float attentuation = pointLights[i].dimmingCoeffs.z * d * d +
								pointLights[i].dimmingCoeffs.y * d +
								pointLights[i].dimmingCoeffs.x;
		totalColour += (colour / attentuation);
	}
	return totalColour;
}

void main() {

	vec4 finalColour = computeDirectionalLight() + computePointLights();
	fColor = texture(diffuseTexture, fTexCoords) * finalColour;
}