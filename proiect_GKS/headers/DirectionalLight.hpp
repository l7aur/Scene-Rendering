#pragma once

#include "Light.hpp"

class DirectionalLight : public Light {
public:
	DirectionalLight();
	DirectionalLight(glm::vec3 colour, GLfloat ambientI, glm::vec3 dir, GLfloat diffuseI);
	~DirectionalLight();
	void useLight(GLuint ambienIntensityLocation, GLuint ambientColorLocation,
		GLuint directionLocation, GLuint diffuseIntensityLocation);
private:
	glm::vec3 direction;
};