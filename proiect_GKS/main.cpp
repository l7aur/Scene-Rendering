#include "Object.hpp"
#include "SceneRenderer.hpp"

const float ROTATION_FACTOR{ 400.0f };
const float CAMERA_SPEED{ 2.0f };
GLfloat angle{ 0.0f };
SceneRenderer myScene{};
float currentFrameTime{ 0.0f };
float previousFrameTime{ 0.0f };
float deltaTime{ 0.0f };

void windowResizeCallback(GLFWwindow* window, int width, int height) {
	fprintf(stdout, "Window resized! New width: %d , and height: %d\n", width, height);
	glViewport(0, 0, width, height);
}

void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	if (key == GLFW_KEY_E && (action == GLFW_PRESS || action == GLFW_REPEAT))
		angle += ROTATION_FACTOR * deltaTime;
	if (key == GLFW_KEY_Q && (action == GLFW_PRESS || action == GLFW_REPEAT))
		angle -= ROTATION_FACTOR * deltaTime;
	myScene.getMyCamera()->keyboardCallback(deltaTime, window, key, scancode, action, mode);
}

void mouseCallback(GLFWwindow* window, double xPos, double yPos) {
	myScene.getMyCamera()->mouseCallback(window, xPos, yPos);
}

void scrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
	myScene.getMyCamera()->scrollCallback(window, xOffset, yOffset);
}

static GLenum glCheckError_(const char* file, int line)
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
#define glCheckError() glCheckError_(__FILE__, __LINE__)

gps::Model3D grass; //test

/* 
* create a container class for all model3d and pass references in objects
* refactor camera to support rotation + move callbacks into a header file
*/

int main(int argc, const char* argv[]) {
	myScene.setWindowCallbacks(windowResizeCallback, keyboardCallback, mouseCallback, scrollCallback);
	
	grass.LoadModel("models/others/grass/grass.obj");

	myScene.insertIntoScene(Object(&grass, myScene.getBasicShader()));

	//initModels(); //separate
	glCheckError();
	// application loop
	while (!glfwWindowShouldClose(myScene.getMyWindow().getWindow())) {
		currentFrameTime = static_cast<float>(glfwGetTime());
		deltaTime = currentFrameTime - previousFrameTime;
		myScene.renderScene();

		glfwPollEvents();
		glfwSwapBuffers(myScene.getMyWindow().getWindow());
		glCheckError();
		previousFrameTime = currentFrameTime;
	}
	return EXIT_SUCCESS;
}