#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>

class Light {
protected:
	Light();
	Light(glm::vec3 colour, GLfloat ambientI, GLfloat diffuseI);
	~Light();
	void useLight(GLuint ambienIntensityLocation, GLuint ambientColorLocation,
		GLuint diffuseIntensityLocation);
	glm::vec3 ambientColour;
	GLfloat ambientIntensity;
	GLfloat diffuseIntensity;
};