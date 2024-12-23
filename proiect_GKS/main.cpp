#include "Util.hpp"
#include "SmallHouseA.hpp"
#include "BigHouseA.hpp"
#include "Church.hpp"
#include "Well.hpp"
#include "TreeA.hpp"
#include "TreeB.hpp"

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
	SmallHouseA h(myBasicShader);
	myScene.insertIntoScene(h.getVertices());
	//Church c(myBasicShader);
	//myScene.insertIntoScene(c.getVertices());
	//Well well(myBasicShader);
	//myScene.insertIntoScene(well.getVertices());
	//BigHouseA t(myBasicShader);
	//TreeA t(myBasicShader);
	//myScene.insertIntoScene(t.getVertices());
	//myScene.insertIntoScene(t.getVertices());
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