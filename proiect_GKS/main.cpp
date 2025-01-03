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
	gps::Shader mainShader{};
	gps::Shader directionalShadowShader{};
	Util::initShader(mainShader, "shaders/test.vert", "shaders/test.frag");
	Util::initShader(directionalShadowShader, "shaders/directional_shadow_map.vert", "shaders/directional_shadow_map.frag");

	SnowController snowCtrl{50};
	snowCtrl.init();

	/*Main lighting*/
	DirectionalLight dirLight = DirectionalLight(1024, 768, glm::vec3{ 1.0f, 1.0f, 1.0f }, 0.4f, glm::vec3{ 0.0f, -15.0f, -10.0f }, 0.1f);
	
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
	Util::buildScene(mainShader, pointLights, pointLightsCount);

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
		glViewport(0, 0, dirLight.getShadowMap()->getShadowWidth(), dirLight.getShadowMap()->getShadowHeight());
		dirLight.getShadowMap()->write();
		glClear(GL_DEPTH_BUFFER_BIT);
		GLuint modelLocation = directionalShadowShader.getModelLocUniform();
		directionalShadowShader.sendDirectionalLightTransformUniform(dirLight.computeLightTransform());
		myScene.renderShadows(directionalShadowShader, modelLocation);

		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		mainShader.useShaderProgram();
		glViewport(0, 0, 1024, 768);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		mainShader.setDirectionalLight(&dirLight);
		mainShader.setPointLights(pointLights, pointLightsCount);
		mainShader.sendDirectionalLightTransformUniform(dirLight.computeLightTransform());
		dirLight.getShadowMap()->read(GL_TEXTURE1);
		mainShader.sendTextureUniform(0);
		mainShader.sendDirectionalShadowMap(1);
		myScene.updateShaderMatrices(mainShader);

		myScene.renderObjects();

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
