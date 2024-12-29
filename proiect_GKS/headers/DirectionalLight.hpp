#pragma once

#include "Light.hpp"
#include "glm/gtc/matrix_transform.hpp"

class DirectionalLight : public Light {
public:
	DirectionalLight();
	DirectionalLight(GLint shadowWidth, GLint shadowHeight, glm::vec3 colour, GLfloat ambientI, glm::vec3 dir, GLfloat diffuseI);
	~DirectionalLight();
	void useLight(GLuint ambienIntensityLocation, GLuint ambientColorLocation, GLuint directionLocation, GLuint diffuseIntensityLocation);
	glm::mat4 computeLightTransform();
private:
	glm::vec3 direction;
};