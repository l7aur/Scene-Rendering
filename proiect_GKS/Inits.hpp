#pragma once

#include "Declarations.hpp"

static void initOpenGLWindow() {
	myWindow.Create(1024, 768, "GKS PROJECT");
}

static void initOpenGLState() {
	glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
	glViewport(0, 0, myWindow.getWindowDimensions().width, myWindow.getWindowDimensions().height);
	glEnable(GL_FRAMEBUFFER_SRGB);
	glEnable(GL_DEPTH_TEST); // enable depth-testing
	glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"
	//glEnable(GL_CULL_FACE); // cull face
	//glCullFace(GL_BACK); // cull back face
	//glFrontFace(GL_CCW); // GL_CCW for counter clock-wise
}

/*
0 |
1 v
2
3
4      <-
  0 1 2 3 4
*/

void static buildHouse() {
	float yLevel = 1.0f;
	const float xArray[] = { 0.0f, 1.0f, 2.0f, 3.0f, 4.0f };
	const float zArray[] = { -10.0f, -9.0f, -8.0f, -7.0f, -6.0f };
	const glm::vec3 scale{ 0.5f,0.5f,0.5f };
	const glm::vec3 rotation{ 90.0f, 0.0f, 0.0f };

	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[2], yLevel, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[2], yLevel, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[2], yLevel, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[2], yLevel, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[2], yLevel, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel + 1, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel + 1, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel + 1, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel + 1, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel + 1, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel + 1, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel + 1, zArray[4] }, rotation, scale));
	//myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[2], yLevel + 1, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel + 1, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel + 1, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[2], yLevel + 1, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel + 1, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel + 2, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel + 2, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel + 2, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel + 2, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel + 2, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel + 2, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel + 2, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel + 2, zArray[4] }, rotation, scale));
	//myObjects.push_back(Object(&glassBlock, &myBasicShader, { xArray[2], yLevel + 2, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel + 3, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel + 3, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel + 3, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel + 3, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel + 3, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel + 3, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel + 3, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[2], yLevel + 3, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel + 3, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel + 3, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[2], yLevel + 3, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel + 3, zArray[0] }, rotation, scale));

	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[0], yLevel, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[0], yLevel, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[0], yLevel + 1, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[4], yLevel, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[4], yLevel, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[0], yLevel + 1, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[4], yLevel + 1, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[4], yLevel + 1, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[4], yLevel + 2, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[4], yLevel + 2, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[0], yLevel + 2, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[0], yLevel + 2, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[4], yLevel + 3, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[0], yLevel + 3, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[0], yLevel + 3, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[4], yLevel + 3, zArray[4] }, rotation, scale));

	myObjects.push_back(Object(&glassBlock, &myBasicShader, { xArray[4], yLevel + 2, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&glassBlock, &myBasicShader, { xArray[0], yLevel + 2, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&glassBlock, &myBasicShader, { xArray[2], yLevel + 2, zArray[0] }, rotation, scale));

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			myObjects.push_back(Object(&sprucePlanks, &myBasicShader, { xArray[i], yLevel + 4, zArray[j] }, rotation, scale));
}

void static initModels() {
	grass.LoadModel("models/others/grass/grass.obj");
	/*watchHouse.LoadModel("models/watchtower/wooden_watch_tower2.obj");
	castle.LoadModel("models/castle/test.obj");
	tv.LoadModel("models/tv/tv.obj");*/
	spruceLog.LoadModel("models/spruce_log/spruce_log.obj");
	cobblestoneBlock.LoadModel("models/cobblestone/cobblestone.obj");
	sprucePlanks.LoadModel("models/wooden_spruce_planks/wooden_spruce_planks.obj");
	glassBlock.LoadModel("models/glass_block/glass_block.obj");

	myObjects.push_back(Object(&grass, &myBasicShader));
	/*myObjects.push_back(Object(&watchHouse, &myBasicShader, { 17, 0, 25 }));
	myObjects.push_back(Object(&castle, &myBasicShader));
	myObjects.push_back(Object(&tv, &myBasicShader, {17, 7, 24.5}));*/
	buildHouse();
}

void static initShaders() {
	myBasicShader.loadShader(
		"shaders/basic.vert",
		"shaders/basic.frag");
}

void static initUniforms() {
	myBasicShader.useShaderProgram();

	// create model matrix for teapot
	model = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
	modelLoc = glGetUniformLocation(myBasicShader.shaderProgram, "model");

	// get view matrix for current camera
	view = myCamera.getViewMatrix();
	viewLoc = glGetUniformLocation(myBasicShader.shaderProgram, "view");
	// send view matrix to shader
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	// compute normal matrix for teapot
	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	normalMatrixLoc = glGetUniformLocation(myBasicShader.shaderProgram, "normalMatrix");

	// create projection matrix
	float aspectRatio = static_cast<float>(myWindow.getWindowDimensions().width) / static_cast<float>(myWindow.getWindowDimensions().height);
	projection = myCamera.getProjectionMatrix(aspectRatio);
	projectionLoc = glGetUniformLocation(myBasicShader.shaderProgram, "projection");
	// send projection matrix to shader
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

	//set the light direction (direction towards the light)
	lightDir = glm::vec3(0.0f, 1.0f, 1.0f);
	lightDirLoc = glGetUniformLocation(myBasicShader.shaderProgram, "lightDir");
	// send light dir to shader
	glUniform3fv(lightDirLoc, 1, glm::value_ptr(lightDir));

	//set light color
	lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //white light
	lightColorLoc = glGetUniformLocation(myBasicShader.shaderProgram, "lightColor");
	// send light color to shader
	glUniform3fv(lightColorLoc, 1, glm::value_ptr(lightColor));
}