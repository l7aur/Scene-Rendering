#include "../headers/DirectionalLight.hpp"

DirectionalLight::DirectionalLight()
	: Light(), direction(glm::vec3{ 0.0f, -1.0f, 0.0f })
{
}

DirectionalLight::DirectionalLight(glm::vec3 colour, GLfloat ambientI, glm::vec3 dir, GLfloat diffuseI)
	: Light(colour, ambientI, diffuseI), direction(dir)
{
}

DirectionalLight::~DirectionalLight()
{
}

void DirectionalLight::useLight(GLuint ambientIntensityLocation, GLuint ambientColourLocation,
	GLuint directionLocation, GLuint diffuseIntensityLocation)
{
	Light::useLight(ambientIntensityLocation, ambientColourLocation, diffuseIntensityLocation);
	glUniform3f(directionLocation, direction.x, direction.y, direction.z);
}
