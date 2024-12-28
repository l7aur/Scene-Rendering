#version 410 core

in vec3 fPosition;
in vec3 fNormal;
in vec2 fTexCoords;

out vec4 fColor;

struct DirectionalLight {
	vec3 direction;
	vec3 colour;
	float ambientIntensity;
	float diffuseIntensity;
};

struct Material {
	float specularIntensity;
	float shininess;
};

uniform sampler2D diffuseTexture;
uniform DirectionalLight directionalLight;
uniform Material material;
uniform vec3 eyePosition;

void main() {
	vec4 ambientColour = vec4(directionalLight.colour * directionalLight.ambientIntensity, 1.0f);

	float diffuseFactor = max(dot(normalize(fNormal), normalize(directionalLight.direction)), 0.0f);
	vec4 diffuseColour = vec4((directionalLight.colour * directionalLight.diffuseIntensity * diffuseFactor), 1.0f);

	vec4 specularColour  = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	if(diffuseFactor > 0.0f) {
		vec3 fragToEye = normalize(eyePosition - fPosition);
		vec3 reflectedVertex = normalize(reflect(directionalLight.direction, normalize(fNormal)));
		float specularFactor = dot(fragToEye, reflectedVertex);
		if(specularFactor > 0.0f) {
			specularFactor = pow(specularFactor, material.shininess);
			specularColour = vec4(directionalLight.colour * material.specularIntensity * specularFactor, 1.0f);
		}
	}

	fColor = texture(diffuseTexture, fTexCoords) * (ambientColour + diffuseColour + specularColour);
}