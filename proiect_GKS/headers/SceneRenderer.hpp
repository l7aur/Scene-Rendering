#pragma once

#include "Window.h"
#include "Shader.hpp"
#include "Camera.hpp"
#include "Object.hpp"
#include "tiny_obj_loader.h"
#include <glm/gtc/matrix_transform.hpp> //glm extension for generating common transformation matrices
#include <glm/gtc/matrix_inverse.hpp> //glm extension for computing inverse matrices
#include <glm/gtc/type_ptr.hpp> //glm extension for accessing the internal data structure of glm types

class SceneRenderer {
public:
	SceneRenderer();
	~SceneRenderer();
	void updateShaderMatrices(gps::Shader& shader);
	void setWindowCallbacks(
		void (*resizeCallback)(GLFWwindow*, int, int), 
		void (*keyboardCallback)(GLFWwindow*, int, int, int, int), 
		void (*mouseCallback)(GLFWwindow*, double, double),
		void (*scrollCallback)(GLFWwindow*, double, double));
	void insertIntoScene(const Object& object);
	void insertIntoScene(const std::vector<Object>& objects);
	gps::Window getMyWindow() const { return myWindow; };
	gps::Camera* getMyCamera() const { return myCamera; };
	std::vector<Object>& getObjects() { return myObjects; };
	void renderObjects();
	void renderShadows(gps::Shader& shader, GLuint modelLoc);
private:
	void initOpenGLWindow();
	void initOpenGLState();	

	gps::Window myWindow;
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
	glm::mat3 normalMatrix;
	glm::vec3 lightDir;
	glm::vec3 lightColor;
	gps::Camera* myCamera;
	std::vector<Object> myObjects;
};