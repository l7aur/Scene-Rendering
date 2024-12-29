#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>

#include "ShadowMap.hpp"

class Light {
public:
	ShadowMap* getShadowMap() { return shadowMap; };
protected:
	Light();
	Light(GLint shadowWidth, GLint shadowHeight, glm::vec3 colour, GLfloat ambientI, GLfloat diffuseI);
	~Light();
	void useLight(GLuint ambienIntensityLocation, GLuint ambientColorLocation,
		GLuint diffuseIntensityLocation);
	glm::vec3 ambientColour;
	GLfloat ambientIntensity;
	GLfloat diffuseIntensity;
	glm::mat4 lightProj;
	ShadowMap* shadowMap;
};