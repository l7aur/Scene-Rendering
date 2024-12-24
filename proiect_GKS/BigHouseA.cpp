#include "BigHouseA.hpp"

BigHouseA::BigHouseA(gps::Shader myShader)
	: MinecraftBuilding(myShader)
{
	setup();
}

void BigHouseA::setup()
{
	const float xCorner = 0.0f;
	const float zCorner = -5.0f;

	const float xCoord[] = { xCorner, xCorner + Displacement::X, xCorner + 2 * Displacement::X, xCorner + 3 * Displacement::X, xCorner + 4 * Displacement::X,
		xCorner + 5 * Displacement::X, xCorner + 6 * Displacement::X, xCorner + 7 * Displacement::X, xCorner + 8 * Displacement::X};
	const float zCoord[] = { zCorner, zCorner + Displacement::Z, zCorner + 2 * Displacement::Z, zCorner + 3 * Displacement::Z, zCorner + 4 * Displacement::Z };
	buildFirstLevel(xCoord, buildingStartingHeight, zCoord);
	buildSecondLevel(xCoord, buildingStartingHeight + Displacement::Y, zCoord);
	buildThirdLevel(xCoord, buildingStartingHeight + Displacement::Y * 2, zCoord);
	buildFourthLevel(xCoord, buildingStartingHeight + Displacement::Y * 3, zCoord);
	buildFifthLevel(xCoord, buildingStartingHeight + Displacement::Y * 4, zCoord);
	buildSixthLevel(xCoord, buildingStartingHeight + Displacement::Y * 5, zCoord);
	buildSeventhLevel(xCoord, buildingStartingHeight + Displacement::Y * 6, zCoord);
	buildEigthLevel(xCoord, buildingStartingHeight + Displacement::Y * 7, zCoord);
	buildNinthLevel(xCoord, buildingStartingHeight + Displacement::Y * 8, zCoord);
	buildTenthLevel(xCoord, buildingStartingHeight + Displacement::Y * 9, zCoord);
	buildEleventhLevel(xCoord, buildingStartingHeight + Displacement::Y * 10, zCoord);
}

void BigHouseA::buildFirstLevel(const float* xCoord, const float& y, const float* zCoord)
{
	addPillors(xCoord, y, zCoord);
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 5; j++) {
			if (i == 0 && j == 0 ||
				i == 8 && j == 0 ||
				i == 0 && j == 4 ||
				i == 8 && j == 4)
				continue;
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[j] }, rotation, scale));
		}
}

void BigHouseA::buildSecondLevel(const float* xCoord, const float& y, const float* zCoord)
{
	addPillors(xCoord, y, zCoord);
	for (int i = 1; i < 8; i++) {
		if (i == 4)
			continue;
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[0] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[4] }, rotation, scale));
	}
	for (int j = 1; j < 4; j++) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[j] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[8], y, zCoord[j] }, rotation, scale));
	}
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[3], y, zCoord[3] }, rotation, scale));
	vertices.push_back(Object(&minecraft.door, shader, { xCoord[4], y + 1.0f, zCoord[0] }, rotation, scale));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[3] }, rotation, scale));
}

void BigHouseA::buildThirdLevel(const float* xCoord, const float& y, const float* zCoord)
{
	addPillors(xCoord, y, zCoord);
	for (int i = 1; i < 8; i++) {
		if (i == 4 || i == 2 || i == 6)
			continue;
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[0] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[4] }, rotation, scale));
	}
	for (int j = 1; j < 4; j++) {
		if (j == 2)
			continue;
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[j] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[8], y, zCoord[j] }, rotation, scale));
	}
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[3], y, zCoord[3] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[2], y, zCoord[0] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[2], y, zCoord[4] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[6], y, zCoord[0] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[6], y, zCoord[4] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[0], y, zCoord[2] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[8], y, zCoord[2] }, rotation, scale));
}

void BigHouseA::buildFourthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	addPillors(xCoord, y, zCoord);
	for (int i = 1; i < 8; i++) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[0] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[4] }, rotation, scale));
	}
	for (int j = 1; j < 4; j++) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[j] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[8], y, zCoord[j] }, rotation, scale));
	}
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[1], y, zCoord[3] }, rotation, scale));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[2], y, zCoord[3] }, rotation, scale));
}

void BigHouseA::buildFifthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	addPillors(xCoord, y, zCoord);
	glm::vec3 rotation1 = rotation + glm::vec3{ 0.0f, 90.0f, 0.0f };
	glm::vec3 rotation2 = rotation + glm::vec3{ 90.0f, 0.0f, 0.0f };
	for (int i = 1; i < 8; i++)
		vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[i], y, zCoord[4] }, rotation, scale));
	for (int i = 1; i < 8; i++)
		vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[i], y, zCoord[0] }, rotation1, scale));
	for (int j = 1; j < 4; j++)
		vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[0], y, zCoord[j] }, rotation, scale));
	for (int j = 1; j < 4; j++)
		vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[8], y, zCoord[j] }, rotation2, scale));
	for (int i = 1; i < 8; i++)
		for (int j = 1; j < 4; j++) {
			if (j == 3 && i > 1 && i < 6)
				continue;
			vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[j] }, rotation, scale));
		}
}

void BigHouseA::buildSixthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	addPillors(xCoord, y, zCoord);
	for (int i = 1; i < 8; i++) {
		if (i == 4)
			continue;
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[0] }, rotation, scale));
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[4] }, rotation, scale));
	}
	for (int j = 1; j < 4; j++) {
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[0], y, zCoord[j] }, rotation, scale));
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[8], y, zCoord[j] }, rotation, scale));
	}
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[4], y, zCoord[0] }, rotation, scale));
}

void BigHouseA::buildSeventhLevel(const float* xCoord, const float& y, const float* zCoord)
{
	addPillors(xCoord, y, zCoord);
	for (int i = 1; i < 8; i++) {
		if (i == 2 || i == 4 || i == 6)
			continue;
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[0] }, rotation, scale));
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[4] }, rotation, scale));
	}
	for (int j = 1; j < 4; j++) {
		if (j == 2)
			continue;
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[0], y, zCoord[j] }, rotation, scale));
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[8], y, zCoord[j] }, rotation, scale));
	}
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[4], y, zCoord[0] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[2], y, zCoord[0] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[4], y, zCoord[0] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[6], y, zCoord[0] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[2], y, zCoord[4] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[4], y, zCoord[4] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[6], y, zCoord[4] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[0], y, zCoord[2] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[8], y, zCoord[2] }, rotation, scale));
}

void BigHouseA::buildEigthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	buildSixthLevel(xCoord, y, zCoord);
	for (int i = 0; i < 9; i++) {
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[0] - Displacement::Z }, rotation, scale));
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[4] + Displacement::Z }, rotation, scale));
	}
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[0] - Displacement::X, y, zCoord[4] + Displacement::Z }, rotation, scale));
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[8] + Displacement::X, y, zCoord[4] + Displacement::Z }, rotation, scale));
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[0] - Displacement::X, y, zCoord[0] - Displacement::Z }, rotation, scale));
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[8] + Displacement::X, y, zCoord[0] - Displacement::Z }, rotation, scale));
}

void BigHouseA::buildNinthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 0; i < 9; i++) {
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[0] }, rotation, scale));
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[4] }, rotation, scale));
	}
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[0] - Displacement::X, y, zCoord[4] }, rotation, scale));
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[8] + Displacement::X, y, zCoord[4] }, rotation, scale));
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[0] - Displacement::X, y, zCoord[0] }, rotation, scale));
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[8] + Displacement::X, y, zCoord[0] }, rotation, scale));
	for (int j = 1; j < 4; j++) {
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[0], y, zCoord[j] }, rotation, scale));
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[8], y, zCoord[j] }, rotation, scale));
	}
}

void BigHouseA::buildTenthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 0; i < 9; i++) {
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[1] }, rotation, scale));
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[3] }, rotation, scale));
	}
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[0] - Displacement::X, y, zCoord[3] }, rotation, scale));
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[8] + Displacement::X, y, zCoord[3] }, rotation, scale));
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[0] - Displacement::X, y, zCoord[1] }, rotation, scale));
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[8] + Displacement::X, y, zCoord[1] }, rotation, scale));
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[0], y, zCoord[2] }, rotation, scale));
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[8], y, zCoord[2] }, rotation, scale));
}

void BigHouseA::buildEleventhLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 0; i < 9; i++)
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[2] }, rotation, scale));
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[0] - Displacement::X, y, zCoord[2] }, rotation, scale));
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[8] + Displacement::X, y, zCoord[2] }, rotation, scale));
}

void BigHouseA::addPillors(const float* xCoord, const float& y, const float* zCoord)
{
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[0], y, zCoord[0] }, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[0], y, zCoord[4] }, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[4], y, zCoord[4] }, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[8], y, zCoord[4] }, rotation, scale));
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[8], y, zCoord[0] }, rotation, scale));
}
