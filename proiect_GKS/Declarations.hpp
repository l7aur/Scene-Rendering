#pragma once

#if defined (__APPLE__)
    #define GLFW_INCLUDE_GLCOREARB
    #define GL_SILENCE_DEPRECATION
#else
    #define GLEW_STATIC
    #include <GL/glew.h>
#endif

#include <GLFW/glfw3.h>

#include <glm/glm.hpp> //core glm functionality
#include <glm/gtc/matrix_transform.hpp> //glm extension for generating common transformation matrices
#include <glm/gtc/matrix_inverse.hpp> //glm extension for computing inverse matrices
#include <glm/gtc/type_ptr.hpp> //glm extension for accessing the internal data structure of glm types
#include "Window.h"
#include "Shader.hpp"
#include "Camera.hpp"
#include "Model3D.hpp"
#include <iostream>


struct Object {
    gps::Model3D* mesh;
    gps::Shader* shader;
    glm::vec3 translation{ glm::vec3(0.0f) };
    glm::vec3 rotation{ glm::vec3(0.0f) };
    glm::vec3 scale{ glm::vec3(1.0f) };
    Object(gps::Model3D* m, gps::Shader* sh, glm::vec3 t, glm::vec3 r, glm::vec3 s) :
        mesh(m), shader(sh), translation(t), rotation(r), scale(s)
    {
    };
    Object(gps::Model3D* m, gps::Shader* sh, glm::vec3 t, glm::vec3 r):
        mesh(m), shader(sh), translation(t), rotation(r)
    {
    };
    Object(gps::Model3D* m, gps::Shader* sh, glm::vec3 t) :
        mesh(m), shader(sh), translation(t)
    {
    };
    Object(gps::Model3D* m, gps::Shader* sh) :
        mesh(m), shader(sh)
    {
    };
};

// window
gps::Window myWindow;

// matrices
glm::mat4 model;
glm::mat4 view;
glm::mat4 projection;
glm::mat3 normalMatrix;

// light parameters
glm::vec3 lightDir;
glm::vec3 lightColor;

// shader uniform locations
GLint modelLoc;
GLint viewLoc;
GLint projectionLoc;
GLint normalMatrixLoc;
GLint lightDirLoc;
GLint lightColorLoc;

// camera
gps::Camera myCamera(
    glm::vec3(0.0f, 5.0f, 3.0f),
    glm::vec3(0.0f, 5.0f, -10.0f),
    glm::vec3(0.0f, 1.0f, 0.0f),
    0.1f,
    1000.0f
);

// models
std::vector<Object> myObjects;
gps::Model3D castle;
gps::Model3D watchHouse;
gps::Model3D tv;
gps::Model3D grass;


gps::Model3D spruceLog, sprucePlanks, glassBlock, cobblestoneBlock;


GLfloat angle{ 0.0f };

// shaders
gps::Shader myBasicShader;

// other
float currentFrameTime{ 0.0f };
float previousFrameTime{ 0.0f };
float deltaTime{ 0.0f };
const float ROTATION_FACTOR{ 400.0f };
const float CAMERA_SPEED{ 2.0f };