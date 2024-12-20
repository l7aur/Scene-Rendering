#include "Object.hpp"
#include "ModelContainer.hpp"
#include "Util.hpp"
#include "SceneRenderer.hpp"
#include "SmallHouse.hpp"

const float ROTATION_FACTOR{ 400.0f };
const float CAMERA_SPEED{ 2.0f };
GLfloat angle{ 0.0f };
float currentFrameTime{ 0.0f };
float previousFrameTime{ 0.0f };
float deltaTime{ 0.0f };
SceneRenderer myScene{};
ModelContainer::Others otherModels;
ModelContainer::Minecraft minecraft;

int main(int argc, const char* argv[]) {
	gps::Shader myBasicShader{};
	Util::initShader(myBasicShader);

	myScene.initUniforms(myBasicShader);
	myScene.setWindowCallbacks(
		Util::windowResizeCallback, 
		Util::keyboardCallback, 
		Util::mouseCallback, 
		Util::scrollCallback);
	
	myScene.insertIntoScene(Object(&otherModels.grass, myBasicShader));
	
	/*test*/
	SmallHouse h(myBasicShader);
	myScene.insertIntoScene(h.vertices);
	/*test*/
	
	Util::glCheckError();
	while (!glfwWindowShouldClose(myScene.getMyWindow().getWindow())) {
		currentFrameTime = static_cast<float>(glfwGetTime());
		deltaTime = currentFrameTime - previousFrameTime;
		myScene.renderScene(myBasicShader);

		glfwPollEvents();
		glfwSwapBuffers(myScene.getMyWindow().getWindow());
		Util::glCheckError();
		previousFrameTime = currentFrameTime;
	}
	return EXIT_SUCCESS;
}