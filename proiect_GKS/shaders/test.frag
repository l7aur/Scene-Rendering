#version 410 core

in vec3 fPosition;
in vec3 fNormal;
in vec2 fTexCoords;

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
uniform DirectionalLight directionalLight;
uniform Material material;
uniform vec3 eyePosition;
uniform PointLight pointLights[MAX_NUMBER_OF_POINT_LIGHTS];
uniform int pointLightCount;

vec4 computeLightByDirection(Light light, vec3 dir) {
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
	return ambientColour + diffuseColour + specularColour;
}

vec4 computeDirectionalLight() {
	return computeLightByDirection(directionalLight.base, directionalLight.direction);
}

vec4 computePointLights() {
	vec4 totalColour = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	for(int i = 0; i < pointLightCount; i++) {
		vec3 direction = fPosition - pointLights[i].position;
		float d = length(direction);
		direction = normalize(direction);
		
		vec4 colour = computeLightByDirection(pointLights[i].base, direction);
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