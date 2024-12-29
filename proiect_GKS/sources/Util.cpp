#include "../headers/Util.hpp"

void Util::windowResizeCallback(GLFWwindow* window, int width, int height) {
	fprintf(stdout, "Window resized! New width: %d , and height: %d\n", width, height);
	glViewport(0, 0, width, height);
}

void Util::keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	myScene.getMyCamera()->keyboardCallback(deltaTime, window, key, scancode, action, mode);
	if (key == GLFW_KEY_1 && action == GLFW_PRESS)
		automatedTourStarted = !automatedTourStarted;
}

void Util::mouseCallback(GLFWwindow* window, double xPos, double yPos) {
	myScene.getMyCamera()->mouseCallback(window, xPos, yPos);
}

void Util::scrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
	myScene.getMyCamera()->scrollCallback(window, xOffset, yOffset);
}

void Util::initShader(gps::Shader& shader, const char* vertexShaderPath, const char* fragmentShaderPath)
{
	shader.loadShader(vertexShaderPath, fragmentShaderPath);
}

void Util::buildScene(gps::Shader& shader, PointLight * pointLights, int& pointLightsCount)
{
	/*Objects without lighting*/
	myScene.insertIntoScene(Object(&otherModels.grass, shader));
	const float dx = std::abs(Displacement::X);
	const float dz = std::abs(Displacement::Z);

	Well well1(shader, 4 * dx, 6 * dz);

	TreeA treeA1(shader, -5 * dx, 1 * dz);
	TreeA treeA2(shader, 8 * dx, 16 * dz);
	TreeA treeA3(shader, 16 * dx, -16 * dz);
	TreeA treeA4(shader, -7 * dx, -16 * dz);
	TreeA treeA5(shader, 30 * dx, -1 * dz);
	
	TreeB treeB1(shader, 9 * dx, -8 * dz);
	TreeB treeB2(shader, -7 * dx, 18 * dz);
	TreeB treeB3(shader, 18 * dx, -10 * dz);
	TreeB treeB4(shader, -21 * dx, 6 * dz);
	
	Church church1(shader, -7 * dx, -8 * dz);

	BigHouseA bigHA1(shader, 2 * dx, -17 * dz);
	BigHouseA bigHA2(shader, 17 * dx, -2 * dz);
	BigHouseA bigHA3(shader, -10 * dx, 7 * dz);

	SmallHouseA smallHA1(shader, -19 * dx, 2 * dz);
	SmallHouseA smallHA2(shader, -1 * dx, 18 * dz);
	SmallHouseA smallHA3(shader, 22 * dx, 9 * dz);

	Library library1(shader, 25 * dx, -10 * dz);

	myScene.insertIntoScene(well1.getVertices());

	myScene.insertIntoScene(treeA1.getVertices());
	myScene.insertIntoScene(treeA2.getVertices());
	myScene.insertIntoScene(treeA3.getVertices());
	myScene.insertIntoScene(treeA4.getVertices());
	myScene.insertIntoScene(treeA5.getVertices());

	myScene.insertIntoScene(treeB1.getVertices());
	myScene.insertIntoScene(treeB2.getVertices());
	myScene.insertIntoScene(treeB3.getVertices());
	myScene.insertIntoScene(treeB4.getVertices());

	myScene.insertIntoScene(church1.getVertices());

	myScene.insertIntoScene(bigHA1.getVertices());
	myScene.insertIntoScene(bigHA2.getVertices());
	myScene.insertIntoScene(bigHA3.getVertices());

	myScene.insertIntoScene(smallHA1.getVertices());
	myScene.insertIntoScene(smallHA2.getVertices());
	myScene.insertIntoScene(smallHA3.getVertices());

	myScene.insertIntoScene(library1.getVertices());

	/*Objects with lighing*/
	addLightPole(shader, pointLights, pointLightsCount, glm::vec3{ 4.0f, buildingStartingHeight, -5.0f });
	addLightPole(shader, pointLights, pointLightsCount, glm::vec3{ 24.0f, buildingStartingHeight, -30.0f });
	addLightPole(shader, pointLights, pointLightsCount, glm::vec3{ 24.0f, buildingStartingHeight, 20.0f });
	addLightPole(shader, pointLights, pointLightsCount, glm::vec3{ -22.0f, buildingStartingHeight, -25.0f });
	addLightPole(shader, pointLights, pointLightsCount, glm::vec3{ 50.0f, buildingStartingHeight, 5.0f });
	addLightPole(shader, pointLights, pointLightsCount, glm::vec3{ -30.0f, buildingStartingHeight, 25.0f });
	addLightPole(shader, pointLights, pointLightsCount, glm::vec3{ 65.0f, buildingStartingHeight, -20.0f });
	addLightPole(shader, pointLights, pointLightsCount, glm::vec3{ -10.0f, 20.0f + buildingStartingHeight, -26.0f });
	addLightPole(shader, pointLights, pointLightsCount, glm::vec3{ 12.0f, buildingStartingHeight, 50.0f });
	addLightPole(shader, pointLights, pointLightsCount, glm::vec3{ -3.0f, buildingStartingHeight, -32.0f });
}

void Util::addLightPole(gps::Shader& shader, PointLight* pointLights, int& pointLightsCount, glm::vec3 position) {
	glm::vec3 rotateXminus90 = glm::vec3{ -90.0f, 0.0f, 0.0f };
	glm::vec3 scale = glm::vec3{ 0.5f, 0.5f, 0.5f };
	myScene.insertIntoScene(Object(&minecraft.fencePost, shader, position, rotateXminus90, MATERIAL_TYPE::WOOD));
	position += glm::vec3{ 0.0f, 2.0f, 0.0f };
	myScene.insertIntoScene(Object(&minecraft.fencePost, shader, position, rotateXminus90, MATERIAL_TYPE::WOOD));
	position += glm::vec3{ 0.0f, 2.0f, 0.0f };
	glm::vec3 oPosition = position + glm::vec3{ 0.0f, 2.0f, 0.0f };
	glm::vec3 lPosition = oPosition - glm::vec3{ 0.5f, -0.2f, 0.5f };
	myScene.insertIntoScene(Object(&minecraft.fencePost, shader, position, rotateXminus90, MATERIAL_TYPE::WOOD));
	myScene.insertIntoScene(Object(&minecraft.torch, shader, oPosition, rotateXminus90, scale, MATERIAL_TYPE::NONE));
	pointLights[pointLightsCount++] = PointLight({ 1.0f, 1.0f, 1.0f }, 1.0f, lPosition, 0.8f, PointLight::LIGHT_RANGE::RANGE_13);

}

const std::vector<Object>::iterator Util::separateTransparents()
{
	std::vector<Object>& v = myScene.getObjects();
	auto i = v.begin();
	auto j = v.rbegin();
	for (int k = 0; k < v.size();) {
		bool iStopped = false;
		bool jStopped = false;
		if (i->mesh == &minecraft.door ||
			i->mesh == &minecraft.fencePost ||
			i->mesh == &minecraft.glassBlock ||
			i->mesh == &minecraft.leaves ||
			i->mesh == &minecraft.water)
			iStopped = true;
		else
			i++, k++;
		if (j->mesh == &minecraft.door ||
			j->mesh == &minecraft.fencePost ||
			j->mesh == &minecraft.glassBlock ||
			j->mesh == &minecraft.leaves ||
			j->mesh == &minecraft.water)
			j++, k++;
		else
			jStopped = true;
		if (iStopped && jStopped) {
			std::swap(*i, *j); 
			j++; 
			i++; 
			k += 2;
		}
	}
	return i;
}

void Util::sortBlocks(const std::vector<Object>::iterator& startingIt, const glm::vec3& frontDirection)
{
	char dominantAxis =
		(std::abs(frontDirection.x) > std::abs(frontDirection.y) && std::abs(frontDirection.x) > std::abs(frontDirection.z)) ?
		((frontDirection.x < 0) ? 'x' : 'X') :
		(std::abs(frontDirection.y) > std::abs(frontDirection.x) && std::abs(frontDirection.y) > std::abs(frontDirection.z)) ?
		((frontDirection.y < 0) ? 'y' : 'Y') :
		((frontDirection.z < 0) ? 'z' : 'Z');
	std::sort(startingIt, myScene.getObjects().end(),
		[dominantAxis](const Object& x, const Object& y)
		{
			switch (dominantAxis)
			{
			case 'x':
				return x.translation.x < y.translation.x;
			case 'y':
				return x.translation.y < y.translation.y;
			case 'z':
				return x.translation.z < y.translation.z;
			case 'X':
				return x.translation.x > y.translation.x;
			case 'Y':
				return x.translation.y > y.translation.y;
			case 'Z':
				return x.translation.z > y.translation.z;
			default:
				return false;
			}
		});
}

GLenum Util::glCheckError_(const char* file, int line)
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

Util::Tour::Tour()
	: directions{
		{'F', 10}, // forward
		{'L', 10}, // left
		{'B', 10}, // backward
		{'R', 10}  // right
	}
{
}
