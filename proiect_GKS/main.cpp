#include "./headers/Util.hpp"
#include "./headers/DirectionalLight.hpp"
#include "./CommonValues.hpp"

GLfloat angle{ 0.0f };
float currentFrameTime{ 0.0f };
float previousFrameTime{ 0.0f };
float deltaTime{ 0.0f };
SceneRenderer myScene{};
ModelContainer::Others otherModels;
ModelContainer::Minecraft minecraft;
bool automatedTourStarted{ false };

int main(int argc, const char* argv[]) {
	/*Shader*/
	gps::Shader myBasicShader{};
	Util::initShader(myBasicShader, "shaders/test.vert", "shaders/test.frag");
	gps::Shader directionalShadowShader{};
	Util::initShader(directionalShadowShader, "shaders/directional_shadow_map.vert", "shaders/directional_shadow_map.frag");

	/*Main lighting*/
	DirectionalLight mainLight = DirectionalLight(10, 10, glm::vec3{ 1.0f, 1.0f, 1.0f }, 0.01f, glm::vec3{ 1.0f, -1.0f, 0.0f }, 0.01f);
	
	/*Point lighting*/
	int pointLightsCount = 0;
	PointLight pointLights[MAX_NUMBER_OF_POINT_LIGHTS];

	/*Automated tour*/
	Util::Tour myAutomatedTour{};
	std::vector<std::pair<char, int>>::const_iterator tourIt = myAutomatedTour.directions.begin();
	int howManyTimes = (*tourIt).second;

	/*Callbacks*/
	myScene.setWindowCallbacks(
		Util::windowResizeCallback, Util::keyboardCallback, 
		Util::mouseCallback, Util::scrollCallback);
	
	/*Create scene*/
	Util::buildScene(myBasicShader, pointLights, pointLightsCount);

	/*Separate for transparency sorting*/
	std::vector<Object>::iterator transparentBlocksStart =  Util::separateTransparents();

	Util::glCheckError();
	while (!glfwWindowShouldClose(myScene.getMyWindow().getWindow())) {
		/*Clear scene*/
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		/*Compute delta time*/
		currentFrameTime = static_cast<float>(glfwGetTime());
		deltaTime = currentFrameTime - previousFrameTime;

		/*Update shader*/
		myScene.updateShaderMatrices(myBasicShader);
		
		/*Use lighting*/
		myBasicShader.setDirectionalLight(&mainLight);
		myBasicShader.setPointLights(pointLights, pointLightsCount);
		
		
		/*Sort for transparency*/
		Util::sortBlocks(transparentBlocksStart, myScene.getMyCamera()->getCameraFrontDir());

		/*Render*/
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
			/*Handle input events*/
			glfwPollEvents();

		/*Update delta time past frame time*/
		previousFrameTime = currentFrameTime;

		/*Display scene*/
		glfwSwapBuffers(myScene.getMyWindow().getWindow());
		Util::glCheckError();
	}
	return EXIT_SUCCESS;
}