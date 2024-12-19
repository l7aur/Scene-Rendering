#include "Object.hpp"
#include "ModelContainer.hpp"
#include "Util.hpp"
#include "SceneRenderer.hpp"

const float ROTATION_FACTOR{ 400.0f };
const float CAMERA_SPEED{ 2.0f };
GLfloat angle{ 0.0f };
SceneRenderer myScene{};
float currentFrameTime{ 0.0f };
float previousFrameTime{ 0.0f };
float deltaTime{ 0.0f };

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

int main(int argc, const char* argv[]) {
	myScene.setWindowCallbacks(
		Util::windowResizeCallback, 
		Util::keyboardCallback, 
		Util::mouseCallback, 
		Util::scrollCallback);
	
	ModelContainer::Others otherModels;
	myScene.insertIntoScene(Object(&otherModels.grass, myScene.getBasicShader()));

	glCheckError();
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