#include "../headers/Light.hpp"

Light::Light()
	: ambientColour(glm::vec3{ 1.0f, 1.0f, 1.0f }), ambientIntensity(1.0f),
	direction(glm::vec3{ 0.0f, -1.0f, 0.0f }), diffuseIntensity(1.0f)
{
}

Light::Light(glm::vec3 colour, GLfloat ambientI, glm::vec3 dir, GLfloat diffuseI)
	: ambientColour(colour), ambientIntensity(ambientI),
	direction(dir), diffuseIntensity(diffuseI)
{
}

Light::~Light()
{
}

void Light::useLight(GLuint ambientIntensityLocation, GLuint ambientColourLocation,
	GLuint directionLocation, GLuint diffuseIntensityLocation)
{
	glUniform3f(ambientColourLocation, ambientColour.r, ambientColour.g, ambientColour.b);
	glUniform1f(ambientIntensityLocation, ambientIntensity);
	glUniform3f(directionLocation, direction.x, direction.y, direction.z);
	glUniform1f(diffuseIntensityLocation, diffuseIntensity);
}
