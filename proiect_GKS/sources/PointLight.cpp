#include "../headers/PointLight.hpp"

PointLight::PointLight()
	: Light(), position({ 0.0f, 2.0f, 0.0f }), dimmingCoefficients(getCoefficients(RANGE_20))
{
}

PointLight::PointLight(glm::vec3 colour, GLfloat ambientI, glm::vec3 pos, GLfloat diffuseI, LIGHT_RANGE x)
	: Light(colour, ambientI, diffuseI), position(pos), dimmingCoefficients(getCoefficients(x))
{
}

PointLight::~PointLight()
{
}

void PointLight::useLight(GLuint ambientIntensityLocation, GLuint ambientColourLocation,
	GLuint positionLocation, GLuint diffuseIntensityLocation, GLuint dimmingCoefficientsLocation)
{
	glUniform3f(positionLocation, position.x, position.y, position.z);
	glUniform3f(dimmingCoefficientsLocation, dimmingCoefficients.x, dimmingCoefficients.y, dimmingCoefficients.z);
	Light::useLight(ambientIntensityLocation, ambientColourLocation, diffuseIntensityLocation);
}

glm::vec3 PointLight::getCoefficients(LIGHT_RANGE x)
{
	switch (x)
	{
	case LIGHT_RANGE::RANGE_7:
		return glm::vec3{ 1.0f, 0.7f, 1.8f };
	case LIGHT_RANGE::RANGE_13:
		return glm::vec3{ 1.0f, 0.35f, 0.44f };
	case LIGHT_RANGE::RANGE_20:
		return glm::vec3{ 1.0f, 0.22f, 0.2f };
	case LIGHT_RANGE::RANGE_32:
		return glm::vec3{ 1.0f, 0.14f, 0.07f };
	case LIGHT_RANGE::RANGE_50:
		return glm::vec3{ 1.0f, 0.09f, 0.032f };
	case LIGHT_RANGE::RANGE_65:
		return glm::vec3{ 1.0f, 0.07f, 0.017f };
	case LIGHT_RANGE::RANGE_100:
		return glm::vec3{ 1.0f, 0.045f, 0.0075f };
	default:
		return glm::vec3{ 1.0f, 0.0f, 0.0f };
	}
}
