#include "Util.hpp"

GLfloat angle{ 0.0f };
float currentFrameTime{ 0.0f };
float previousFrameTime{ 0.0f };
float deltaTime{ 0.0f };
SceneRenderer myScene{};
ModelContainer::Others otherModels;
ModelContainer::Minecraft minecraft;

int main(int argc, const char* argv[]) {
	/*gps::Shader myBasicShader{};
	Util::initShader(myBasicShader, "shaders/basic.vert", "shaders/basic.frag");
	myScene.initUniforms(myBasicShader);*/

	gps::Shader testShader{};
	Util::initShader(testShader, "shaders/test.vert", "shaders/test.frag");
	myScene.initUniforms(testShader);

	myScene.setWindowCallbacks(
		Util::windowResizeCallback, Util::keyboardCallback, 
		Util::mouseCallback, Util::scrollCallback);
	
	//Util::buildScene(myBasicShader);
	
	//BigHouseA h(myBasicShader, 2, -3);
	

	myScene.insertIntoScene(Object(&otherModels.grass, testShader));
	myScene.insertIntoScene(Object(&minecraft.glassBlock, testShader, {0.0f, 1.0f, -3.0f}));
	
	//Util::sortBlocks();

	Util::glCheckError();
	while (!glfwWindowShouldClose(myScene.getMyWindow().getWindow())) {
		currentFrameTime = static_cast<float>(glfwGetTime());
		deltaTime = currentFrameTime - previousFrameTime;

		myScene.updateShaderMatrices(testShader);
		myScene.renderObjects();

		glfwPollEvents();
		glfwSwapBuffers(myScene.getMyWindow().getWindow());
		Util::glCheckError();
		previousFrameTime = currentFrameTime;
	}
	return EXIT_SUCCESS;
}