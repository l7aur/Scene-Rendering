#pragma once

#include "Window.h"
#include "SceneRenderer.hpp"
#include "SmallHouseA.hpp"
#include "BigHouseA.hpp"
#include "Church.hpp"
#include "Well.hpp"
#include "TreeA.hpp"
#include "TreeB.hpp"
#include "Library.hpp"
#include <algorithm>

extern SceneRenderer myScene;
extern float currentFrameTime;
extern float previousFrameTime;
extern float deltaTime;
extern ModelContainer::Others otherModels;
extern ModelContainer::Minecraft minecraft;
extern bool automatedTourStarted;

namespace Util {
	struct Tour {
		const std::vector<std::pair<char, int>> directions;
		Tour();
	};
	void windowResizeCallback(GLFWwindow* window, int width, int height);
	void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
	void mouseCallback(GLFWwindow* window, double xPos, double yPos);
	void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);
	void initShader(gps::Shader& shader, const char* vertexShaderPath, const char* fragmentShaderPath);
	void buildScene(gps::Shader& shader, PointLight* pointLights, int& pointLightsCount);
	void addLightPole(gps::Shader& shader, PointLight* pointLights, int& pointLightsCount, glm::vec3 oPosition);
	const std::vector<Object>::iterator separateTransparents();
	void sortBlocksForTransparency(const std::vector<Object>::iterator& startingIt, const glm::vec3& frontDirection);
	GLenum glCheckError_(const char* file, int line);
	#define glCheckError() glCheckError_(__FILE__, __LINE__)
}