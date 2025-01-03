#include "./headers/Util.hpp"
#include "./headers/DirectionalLight.hpp"
#include "./CommonValues.hpp"
#include "./headers/SnowController.hpp"
#include "main.h"

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
	gps::Shader directionalShadowShader{};
	Util::initShader(myBasicShader, "shaders/test.vert", "shaders/test.frag");
	Util::initShader(directionalShadowShader, "shaders/directional_shadow_map.vert", "shaders/directional_shadow_map.frag");

	SnowController snowCtrl{50};
	snowCtrl.init();

	/*Main lighting*/
	DirectionalLight mainLight = DirectionalLight(1300, 980, glm::vec3{ 1.0f, 1.0f, 1.0f }, 0.4f, glm::vec3{ 0.0f, -15.0f, -10.0f }, 0.01f);
	
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
		computeDeltaTime();

		Util::sortBlocksForTransparency(transparentBlocksStart, myScene.getMyCamera()->getCameraFrontDir());

		(automatedTourStarted) 
			? handleAutomaticTour(tourIt, howManyTimes, myAutomatedTour)
			: glfwPollEvents();

		directionalShadowShader.useShaderProgram();
		glViewport(0, 0, mainLight.getShadowMap()->getShadowWidth(), mainLight.getShadowMap()->getShadowHeight());
		mainLight.getShadowMap()->write();
		glClear(GL_DEPTH_BUFFER_BIT);
		GLuint modelLocation = directionalShadowShader.getModelLocUniform();
		directionalShadowShader.sendDirectionalLightTransformUniform(mainLight.computeLightTransform());
		myScene.renderShadows(directionalShadowShader, modelLocation);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		myBasicShader.useShaderProgram();
		glViewport(0, 0, 1300, 980);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		myBasicShader.setDirectionalLight(&mainLight);
		myBasicShader.setPointLights(pointLights, pointLightsCount);
		myBasicShader.sendDirectionalLightTransformUniform(mainLight.computeLightTransform());
		mainLight.getShadowMap()->read(GL_TEXTURE1);
		myBasicShader.sendDirectionalShadowMap(1);
		myBasicShader.sendTextureUniform(0);
		myScene.updateShaderMatrices(myBasicShader);

		/*Render*/
		myScene.renderObjects();

		/*Display scene*/
		glfwSwapBuffers(myScene.getMyWindow().getWindow());
		Util::glCheckError();
	}
	return EXIT_SUCCESS;
}

void computeDeltaTime()
{
	currentFrameTime = static_cast<float>(glfwGetTime());
	deltaTime = currentFrameTime - previousFrameTime;
	previousFrameTime = currentFrameTime;
}

void handleAutomaticTour(std::vector<std::pair<char, int>>::const_iterator& tourIt, int& howManyTimes, Util::Tour& myAutomatedTour)
{
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
