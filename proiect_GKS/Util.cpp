#include "Util.hpp"

void Util::windowResizeCallback(GLFWwindow* window, int width, int height) {
	fprintf(stdout, "Window resized! New width: %d , and height: %d\n", width, height);
	glViewport(0, 0, width, height);
}

void Util::keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	if (key == GLFW_KEY_E && (action == GLFW_PRESS || action == GLFW_REPEAT))
		angle += ROTATION_FACTOR * deltaTime;
	if (key == GLFW_KEY_Q && (action == GLFW_PRESS || action == GLFW_REPEAT))
		angle -= ROTATION_FACTOR * deltaTime;
	myScene.getMyCamera()->keyboardCallback(deltaTime, window, key, scancode, action, mode);
}

void Util::mouseCallback(GLFWwindow* window, double xPos, double yPos) {
	myScene.getMyCamera()->mouseCallback(window, xPos, yPos);
}

void Util::scrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
	myScene.getMyCamera()->scrollCallback(window, xOffset, yOffset);
}

void Util::initShader(gps::Shader& shader)
{
	shader.loadShader("shaders/basic.vert", "shaders/basic.frag");
}

GLenum Util::glCheckError_(const char* file, int line)
{
	GLenum errorCode;
	while ((errorCode = glGetError()) != GL_NO_ERROR) {
		std::string error;
		switch (errorCode) {
		case GL_INVALID_ENUM:
			error = "INVALID_ENUM";
			break;
		case GL_INVALID_VALUE:
			error = "INVALID_VALUE";
			break;
		case GL_INVALID_OPERATION:
			error = "INVALID_OPERATION";
			break;
		case GL_OUT_OF_MEMORY:
			error = "OUT_OF_MEMORY";
			break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			error = "INVALID_FRAMEBUFFER_OPERATION";
			break;
		}
		std::cout << error << " | " << file << " (" << line << ")" << std::endl;
	}
	return errorCode;
}
