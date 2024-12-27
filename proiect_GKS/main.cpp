#include "headers/Util.hpp"

GLfloat angle{ 0.0f };
float currentFrameTime{ 0.0f };
float previousFrameTime{ 0.0f };
float deltaTime{ 0.0f };
SceneRenderer myScene{};
ModelContainer::Others otherModels;
ModelContainer::Minecraft minecraft;
bool automatedTourStarted{ false };

int main(int argc, const char* argv[]) {
	Util::Tour myAutomatedTour{};
	std::vector<std::pair<char, int>>::const_iterator tourIt = myAutomatedTour.directions.begin();
	int howManyTimes = (*tourIt).second;

	gps::Shader myBasicShader{};
	Util::initShader(myBasicShader, "shaders/basic.vert", "shaders/basic.frag");
	myScene.initUniforms(myBasicShader);

	myScene.setWindowCallbacks(
		Util::windowResizeCallback, Util::keyboardCallback, 
		Util::mouseCallback, Util::scrollCallback);
	
	Util::buildScene(myBasicShader);

	std::vector<Object>::iterator transparentStarts =  Util::separateTransparents();

	Util::glCheckError();
	while (!glfwWindowShouldClose(myScene.getMyWindow().getWindow())) {
		currentFrameTime = static_cast<float>(glfwGetTime());
		deltaTime = currentFrameTime - previousFrameTime;
		
		myScene.updateShaderMatrices(myBasicShader);

		Util::sortBlocks(transparentStarts, myScene.getMyCamera()->getCameraFrontDir());

		myScene.renderObjects();
		
		if (automatedTourStarted) {
			switch ((*tourIt).first) {
			case 'F':
				myScene.getMyCamera()->move(gps::MOVE_DIRECTION::MOVE_FORWARD, deltaTime);
				break;
			case 'B':
				myScene.getMyCamera()->move(gps::MOVE_DIRECTION::MOVE_BACKWARD, deltaTime);
				break;
			case 'R':
				myScene.getMyCamera()->move(gps::MOVE_DIRECTION::MOVE_RIGHT, deltaTime);
				break;
			case 'L':
				myScene.getMyCamera()->move(gps::MOVE_DIRECTION::MOVE_LEFT, deltaTime);
				break;
			default:
				std::cerr << "hellow?\n";
				break;
			}
			if (howManyTimes == 0) {
				tourIt++; 
				if (tourIt == myAutomatedTour.directions.end()) {
					tourIt = myAutomatedTour.directions.begin();
					howManyTimes = (*tourIt).second;
					automatedTourStarted = false;
				}
				else
					howManyTimes = (*tourIt).second;
			}
			else
				howManyTimes--;
		}
		else
			glfwPollEvents();

		glfwSwapBuffers(myScene.getMyWindow().getWindow());
		Util::glCheckError();
		previousFrameTime = currentFrameTime;
	}
	return EXIT_SUCCESS;
}