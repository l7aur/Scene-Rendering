#pragma once

#include "Window.h"
#include "Shader.hpp"
#include "Camera.hpp"
#include <iostream>
#include "Object.hpp"
#include "tiny_obj_loader.h"
#include <glm/gtc/matrix_transform.hpp> //glm extension for generating common transformation matrices
#include <glm/gtc/matrix_inverse.hpp> //glm extension for computing inverse matrices
#include <glm/gtc/type_ptr.hpp> //glm extension for accessing the internal data structure of glm types

class SceneRenderer {
public:
	SceneRenderer();
	~SceneRenderer();
	void initUniforms(gps::Shader& shader);
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
	const std::vector<Object> getObjects() const { return myObjects; };
	void renderObjects();
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
	GLint modelLoc;
	GLint viewLoc;
	GLint projectionLoc;
	GLint normalMatrixLoc;
	GLint lightDirLoc;
	GLint lightColorLoc;
	gps::Camera* myCamera;
	std::vector<Object> myObjects;
};