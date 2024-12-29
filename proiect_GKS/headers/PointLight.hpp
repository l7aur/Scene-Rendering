#pragma once

#include "Light.hpp"

class PointLight : public Light
{
public:
	enum LIGHT_RANGE {
		RANGE_7,
		RANGE_13,
		RANGE_20,
		RANGE_32,
		RANGE_50,
		RANGE_65,
		RANGE_100,
		CUSTOM
	};
	  
	PointLight();
	PointLight(glm::vec3 colour, GLfloat ambientI, glm::vec3 pos, GLfloat diffuseI, LIGHT_RANGE x);
	~PointLight();
	void useLight(GLuint ambienIntensityLocation, GLuint ambientColorLocation, GLuint positionLocation, GLuint diffuseIntensityLocation, GLuint dimmingCoefficientsLocation);
private:
	glm::vec3 position;
	// constant, linear, quadratic
	glm::vec3 dimmingCoefficients;
	glm::vec3 getCoefficients(LIGHT_RANGE x);
};