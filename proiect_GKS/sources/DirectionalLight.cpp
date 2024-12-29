#include "../headers/DirectionalLight.hpp"

DirectionalLight::DirectionalLight()
	: Light(), direction(glm::vec3{ 0.0f, -1.0f, 0.0f })
{
	lightProj = glm::ortho(-5.0f, 5.0f, -5.0f, 5.0f, 0.1f, 20.0f);
}

DirectionalLight::DirectionalLight(GLint shadowWidth, GLint shadowHeight, glm::vec3 colour, GLfloat ambientI, glm::vec3 dir, GLfloat diffuseI)
	: Light(shadowWidth, shadowHeight, colour, ambientI, diffuseI), direction(dir)
{
	lightProj = glm::ortho(-5.0f, 5.0f, -5.0f, 5.0f, 0.1f, 20.0f);
}

DirectionalLight::~DirectionalLight()
{
}

void DirectionalLight::useLight(GLuint ambientIntensityLocation, GLuint ambientColourLocation, GLuint directionLocation, GLuint diffuseIntensityLocation)
{
	Light::useLight(ambientIntensityLocation, ambientColourLocation, diffuseIntensityLocation);
	glUniform3f(directionLocation, direction.x, direction.y, direction.z);
}

glm::mat4 DirectionalLight::computeLightTransform()
{
	return lightProj * glm::lookAt(-direction, glm::vec3{ 0.0f, 0.0f, 0.0f }, glm::vec3{0.0f, 1.0f, 0.0f});
}
