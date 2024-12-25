#pragma once

#include "Window.h"
#include "SceneRenderer.hpp"
#include "SmallHouseA.hpp"
#include "BigHouseA.hpp"
#include "Church.hpp"
#include "Well.hpp"
#include "TreeA.hpp"
#include "TreeB.hpp"
#include <algorithm>

extern SceneRenderer myScene;
extern float currentFrameTime;
extern float previousFrameTime;
extern float deltaTime;
extern ModelContainer::Others otherModels;
extern ModelContainer::Minecraft minecraft;

namespace Util {
	void windowResizeCallback(GLFWwindow* window, int width, int height);
	void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
	void mouseCallback(GLFWwindow* window, double xPos, double yPos);
	void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);
	void initShader(gps::Shader& shader, const char* vertexShaderPath, const char* fragmentShaderPath);
	void buildScene(gps::Shader& shader);
	void sortBlocks();
	GLenum glCheckError_(const char* file, int line);
	#define glCheckError() glCheckError_(__FILE__, __LINE__)
}