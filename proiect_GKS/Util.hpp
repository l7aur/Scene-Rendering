#pragma once

#include "Window.h"
#include "SceneRenderer.hpp"

extern const float ROTATION_FACTOR;
extern const float CAMERA_SPEED;
extern GLfloat angle;
extern SceneRenderer myScene;
extern float currentFrameTime;
extern float previousFrameTime;
extern float deltaTime;

namespace Util {

	void windowResizeCallback(GLFWwindow* window, int width, int height);

	void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

	void mouseCallback(GLFWwindow* window, double xPos, double yPos);

	void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);
}