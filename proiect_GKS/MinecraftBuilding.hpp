#pragma once

#include "ModelContainer.hpp"
#include "Object.hpp"
#include <glm/glm.hpp>
#include <vector>

namespace Displacement { // a default block is a 2x2x2 cube
	const float X = 2.0001f;
	const float Y = 2.0001f;
	const float Z = -2.0001f;
}

const float buildingStartingHeight = 1.05f;
extern ModelContainer::Minecraft minecraft;

class MinecraftBuilding {
public:
	MinecraftBuilding(gps::Shader& myShader, const float myCornerX, const float myCornerZ);
	const std::vector<Object>& getVertices() const { return this->vertices; };

protected:
	gps::Shader shader;
	std::vector<Object> vertices;
	glm::vec3 rotation{ 90.0f, 0.0f, 0.0f };
	glm::vec3 scale{ 1.0f, 1.0f, 1.0f };
	glm::vec3 windowR{ 0.0f, 0.0f, 90.0f };
	glm::vec3 rF = { 0.0f, 0.0f, 0.0f };
	glm::vec3 rB = { 0.0f, -180.0f, 0.0f };
	glm::vec3 rR = glm::vec3{ 0.0f, 90.0f, 0.0f };
	glm::vec3 rL = glm::vec3{ 0.0f, -90.0f, 0.0f };

	const float cornerX{}, cornerZ{};
	virtual void setup() = 0;
	virtual void buildFirstLevel(const float* xCoord, const float& yCoord, const float* zCoord) {};
	virtual void buildSecondLevel(const float* xCoord, const float& yCoord, const float* zCoord) {};
	virtual void buildThirdLevel(const float* xCoord, const float& yCoord, const float* zCoord) {};
	virtual void buildFourthLevel(const float* xCoord, const float& yCoord, const float* zCoord) {};
	virtual void buildFifthLevel(const float* xCoord, const float& yCoord, const float* zCoord) {};
	virtual void buildSixthLevel(const float* xCoord, const float& yCoord, const float* zCoord) {};
	virtual void buildSeventhLevel(const float* xCoord, const float& yCoord, const float* zCoord) {};
	virtual void buildEigthLevel(const float* xCoord, const float& yCoord, const float* zCoord) {};
	virtual void buildNinthLevel(const float* xCoord, const float& yCoord, const float* zCoord) {};
	virtual void buildTenthLevel(const float* xCoord, const float& yCoord, const float* zCoord) {};
	virtual void buildEleventhLevel(const float* xCoord, const float& yCoord, const float* zCoord) {};
	virtual void buildTwelvthLevel(const float* xCoord, const float& yCoord, const float* zCoord) {};
};