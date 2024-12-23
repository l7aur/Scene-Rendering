#include "SmallHouseA.hpp"

SmallHouseA::SmallHouseA(gps::Shader& myShader)
	: MinecraftBuilding(myShader)
{
	setup();
}

void SmallHouseA::setup() {
	const float xCorner = 0.0f;
	const float zCorner = -5.0f;

	const float xCoord[] = { xCorner, xCorner + Displacement::X, xCorner + 2 * Displacement::X, xCorner + 3 * Displacement::X, xCorner + 4 * Displacement::X };
	const float zCoord[] = { zCorner, zCorner + Displacement::Z, zCorner + 2 * Displacement::Z, zCorner + 3 * Displacement::Z, zCorner + 4 * Displacement::Z }; 
	buildFirstLevel(xCoord, buildingStartingHeight, zCoord);
	buildSecondLevel(xCoord, buildingStartingHeight + Displacement::Y, zCoord);
	buildThirdLevel(xCoord, buildingStartingHeight + Displacement::Y * 2, zCoord);
	buildFourthLevel(xCoord, buildingStartingHeight + Displacement::Y * 3, zCoord);
	buildFifthLevel(xCoord, buildingStartingHeight + Displacement::Y * 4, zCoord);
	buildSixthLevel(xCoord, buildingStartingHeight + Displacement::Y * 5, zCoord);
	buildSeventhLevel(xCoord, buildingStartingHeight + Displacement::Y * 6, zCoord);
}

void SmallHouseA::buildFirstLevel(const float* xCoord, const float& y, const float* zCoord) {
	addPillors(xCoord, y, zCoord);
	for (int i = 1; i < 4; i++) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[0] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[4] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[i] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[i] }, rotation, scale));
	}

	for (int i = 1; i < 4; i++)
		for (int j = 1; j < 4; j++)
			vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[j] }, rotation, scale));
}

void SmallHouseA::buildSecondLevel(const float* xCoord, const float& y, const float* zCoord) {
	addPillors(xCoord, y, zCoord);
	for (int i = 1; i < 4; i++) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[4] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[i] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[i] }, rotation, scale));
	}
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[1], y, zCoord[0] }, rotation, scale));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[3], y, zCoord[0] }, rotation, scale));
}

void SmallHouseA::buildThirdLevel(const float* xCoord, const float& y, const float* zCoord) {
	addPillors(xCoord, y, zCoord);
	glm::vec3 rotationLRWalls = rotation + glm::vec3{ 90.0f, 0.0f, 0.0f };
	glm::vec3 rotationFWalls = rotation + glm::vec3{ 0.0f, 90.0f, 0.0f };
	for (int i = 1; i < 4; i++) {
		if (i == 2)
			continue;
		vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[i], y, zCoord[4] }, rotationFWalls, scale));
		vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[0], y, zCoord[i] }, rotationLRWalls, scale));
		vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[4], y, zCoord[i] }, rotationLRWalls, scale));
	}
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[1], y, zCoord[0] }, rotation, scale));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[3], y, zCoord[0] }, rotation, scale));

	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[2], y, zCoord[4] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[0], y, zCoord[2] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[4], y, zCoord[2] }, rotation, scale));
}

void SmallHouseA::buildFourthLevel(const float* xCoord, const float& y, const float* zCoord) {
	addPillors(xCoord, y, zCoord);
	for (int i = 1; i < 4; i++) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[0] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[4] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[i] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[i] }, rotation, scale));
	}
}

void SmallHouseA::buildFifthLevel(const float* xCoord, const float& y, const float* zCoord) {
	for (int i = 0; i < 5; i++) {
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[0] }, rotation, scale));
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[4] }, rotation, scale));
	}
	for (int i = 1; i < 4; i++) {
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[0], y, zCoord[i] }, rotation, scale));
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[4], y, zCoord[i] }, rotation, scale));
	}
	for (int i = 0; i < 5; i++) {
		vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[0] - Displacement::X, y, zCoord[i] }, rotation, scale));
		vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[4] + Displacement::X, y, zCoord[i] }, rotation, scale));
	}
	for (int i = 0; i < 5; i++) {
		vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[i], y, zCoord[0] - Displacement::Z }, rotation, scale));
		vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[i], y, zCoord[4] + Displacement::Z}, rotation, scale));
	}
	vertices.push_back(Object(&minecraft.spruceStairsOutsideCorner, shader, { xCoord[0] - Displacement::X, y, zCoord[4] + Displacement::Z}, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceStairsOutsideCorner, shader, { xCoord[4] + Displacement::X, y, zCoord[4] + Displacement::Z}, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceStairsOutsideCorner, shader, { xCoord[0] - Displacement::X, y, zCoord[0] - Displacement::Z}, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceStairsOutsideCorner, shader, { xCoord[4] + Displacement::X, y, zCoord[0] - Displacement::Z}, rotation, scale));
}

void SmallHouseA::buildSixthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 1; i < 4; i++) {
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[3], y, zCoord[i] }, rotation, scale));
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[1], y, zCoord[i] }, rotation, scale));
	}
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[2], y, zCoord[3] }, rotation, scale));
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[2], y, zCoord[1] }, rotation, scale));
	for (int i = 0; i < 5; i++) {
		if (i == 0 || i == 4)
			continue;
		vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[0], y, zCoord[i] }, rotation, scale));
		vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[4], y, zCoord[i] }, rotation, scale));
	}
	for (int i = 0; i < 5; i++) {
		if (i == 0 || i == 4)
			continue;
		vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[i], y, zCoord[0] }, rotation, scale));
		vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[i], y, zCoord[4] }, rotation, scale));
	}
	vertices.push_back(Object(&minecraft.spruceStairsOutsideCorner, shader, { xCoord[0], y, zCoord[4] }, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceStairsOutsideCorner, shader, { xCoord[4], y, zCoord[4] }, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceStairsOutsideCorner, shader, { xCoord[0], y, zCoord[0] }, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceStairsOutsideCorner, shader, { xCoord[4], y, zCoord[0] }, rotation, scale));
}

void SmallHouseA::buildSeventhLevel(const float* xCoord, const float& y, const float* zCoord)
{
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[2], y, zCoord[2] }, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[1], y, zCoord[2] }, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[3], y, zCoord[2] }, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[2], y, zCoord[1] }, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[2], y, zCoord[3] }, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceStairsOutsideCorner, shader, { xCoord[1], y, zCoord[3] }, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceStairsOutsideCorner, shader, { xCoord[3], y, zCoord[3] }, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceStairsOutsideCorner, shader, { xCoord[1], y, zCoord[1] }, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceStairsOutsideCorner, shader, { xCoord[3], y, zCoord[1] }, rotation, scale));
}

void SmallHouseA::addPillors(const float* xCoord, const float& y, const float* zCoord) {
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[0], y, zCoord[0] }, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[4], y, zCoord[4] }, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[4], y, zCoord[0] }, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[0], y, zCoord[4] }, rotation, scale));
}
