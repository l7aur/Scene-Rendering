#pragma once

#include "Window.h"
#include "SceneRenderer.hpp"

extern SceneRenderer myScene;
extern float currentFrameTime;
extern float previousFrameTime;
extern float deltaTime;

namespace Util {
	void windowResizeCallback(GLFWwindow* window, int width, int height);
	void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
	void mouseCallback(GLFWwindow* window, double xPos, double yPos);
	void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);
	void initShader(gps::Shader& shader);
	GLenum glCheckError_(const char* file, int line);
	#define glCheckError() glCheckError_(__FILE__, __LINE__)
}