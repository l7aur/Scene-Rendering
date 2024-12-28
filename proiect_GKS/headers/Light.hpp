#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>

class Light {
public:
	Light();
	Light(glm::vec3 colour, GLfloat ambientI, glm::vec3 dir, GLfloat diffuseI);
	~Light();
	void useLight(GLuint ambienIntensityLocation, GLuint ambientColorLocation,
		GLuint directionLocation, GLuint diffuseIntensityLocation);
private:

	glm::vec3 ambientColour;
	GLfloat ambientIntensity;

	glm::vec3 direction;
	GLfloat diffuseIntensity;
};