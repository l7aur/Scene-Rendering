#include "../headers/Light.hpp"

Light::Light()
	: ambientColour(glm::vec3{ 1.0f, 1.0f, 1.0f }), ambientIntensity(1.0f), diffuseIntensity(1.0f)
{
}

Light::Light(GLint shadowWidth, GLint shadowHeight, glm::vec3 colour, GLfloat ambientI, GLfloat diffuseI)
	: ambientColour(colour), ambientIntensity(ambientI), diffuseIntensity(diffuseI)
{
	shadowMap = new ShadowMap();
	shadowMap->init(shadowWidth, shadowHeight);
}

Light::~Light()
{
	//delete shadowMap;
}

void Light::useLight(GLuint ambientIntensityLocation, GLuint ambientColourLocation,
	GLuint diffuseIntensityLocation)
{
	glUniform1f(ambientIntensityLocation, ambientIntensity);
	glUniform3f(ambientColourLocation, ambientColour.r, ambientColour.g, ambientColour.b);
	glUniform1f(diffuseIntensityLocation, diffuseIntensity);
}
