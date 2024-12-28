#pragma once 

#include "GL/glew.h"

enum MATERIAL_TYPE {
    NONE,
    WOOD,
    LOG,
    STONE,
    GLASS,
    WATER
};

class Material {
public:
    Material(MATERIAL_TYPE type);
    void useMaterial(GLuint specularIntensityLocation, GLuint shininessLocation);
private:
    GLfloat specularIntensity{};
    GLfloat shininess{};
};