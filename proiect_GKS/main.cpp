#include "./headers/Util.hpp"
#include "./headers/Light.hpp"

GLfloat angle{ 0.0f };
float currentFrameTime{ 0.0f };
float previousFrameTime{ 0.0f };
float deltaTime{ 0.0f };
SceneRenderer myScene{};
ModelContainer::Others otherModels;
ModelContainer::Minecraft minecraft;
bool automatedTourStarted{ false };

Light mainLight;

int main(int argc, const char* argv[]) {
	mainLight = Light(glm::vec3{ 1.0f, 1.0f, 1.0f }, 0.01f, glm::vec3{ 1.0f, -1.0f, 0.0f }, 0.01f);

	Util::Tour myAutomatedTour{};
	std::vector<std::pair<char, int>>::const_iterator tourIt = myAutomatedTour.directions.begin();
	int howManyTimes = (*tourIt).second;

	gps::Shader myBasicShader{};
	//Util::initShader(myBasicShader, "shaders/basic.vert", "shaders/basic.frag");
	Util::initShader(myBasicShader, "shaders/test.vert", "shaders/test.frag");

	myScene.setWindowCallbacks(
		Util::windowResizeCallback, Util::keyboardCallback, 
		Util::mouseCallback, Util::scrollCallback);
	
	Util::buildScene(myBasicShader);

	myScene.insertIntoScene(Object(&minecraft.torch, myBasicShader, { 0.0f, 1.0f, -5.0f }));

	std::vector<Object>::iterator transparentBlocksStart =  Util::separateTransparents();

	Util::glCheckError();
	while (!glfwWindowShouldClose(myScene.getMyWindow().getWindow())) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		currentFrameTime = static_cast<float>(glfwGetTime());
		deltaTime = currentFrameTime - previousFrameTime;

		myScene.updateShaderMatrices(myBasicShader);
		
		mainLight.useLight(myBasicShader.getAmbientIntensityUniform(), myBasicShader.getAmbientColourUniform(),
			myBasicShader.getDirectionUniform(), myBasicShader.getDiffuseIntensityUniform());

		Util::sortBlocks(transparentBlocksStart, myScene.getMyCamera()->getCameraFrontDir());

		myScene.renderObjects();
		
		/*if (automatedTourStarted) {
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
		else*/
			glfwPollEvents();
		previousFrameTime = currentFrameTime;

		glfwSwapBuffers(myScene.getMyWindow().getWindow());
		Util::glCheckError();
	}
	return EXIT_SUCCESS;
}