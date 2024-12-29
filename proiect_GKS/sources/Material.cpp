#include "../headers/Material.hpp"

Material::Material(MATERIAL_TYPE type) {
    switch (type)
    {
    case WOOD:
        specularIntensity = 0.1f; shininess = 1.0f;
        break;
    case LOG:
        specularIntensity = 0.08f; shininess = 1.0f;
        break;
    case STONE:
        specularIntensity = 0.06f; shininess = 1.0f;
        break;
    case GLASS:
        specularIntensity = 0.7f; shininess = 1.0f;
        break;
    case WATER:
        specularIntensity = 0.5f; shininess = 1.0f;
        break;
    case LIGHT:
        specularIntensity = 1.0f; shininess = 1.0f;
        break;
    default:
        specularIntensity = 0.0f; shininess = 0.0f;
        break;
    }
}

void Material::useMaterial(GLuint specularIntensityLocation, GLuint shininessLocation)
{
    glUniform1f(specularIntensityLocation, specularIntensity);
    glUniform1f(shininessLocation, shininess);
}
