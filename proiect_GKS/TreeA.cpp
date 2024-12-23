#include "TreeA.hpp"

TreeA::TreeA(gps::Shader& myShader)
	: MinecraftBuilding(myShader)
{
	setup();
}

void TreeA::setup()
{
	const float xCorner = -10.0f;
	const float zCorner = -10.0f;

	const float xCoord[] = { xCorner, xCorner + Displacement::X, xCorner + 2 * Displacement::X, xCorner + 3 * Displacement::X, xCorner + 4 * Displacement::X };
	const float zCoord[] = { zCorner, zCorner + Displacement::Z, zCorner + 2 * Displacement::Z, zCorner + 3 * Displacement::Z, zCorner + 4 * Displacement::Z };
	buildFirstLevel(xCoord, buildingStartingHeight + Displacement::Y * 0, zCoord);
	buildSecondLevel(xCoord, buildingStartingHeight + Displacement::Y * 1, zCoord);
	buildThirdLevel(xCoord, buildingStartingHeight + Displacement::Y * 2, zCoord);
	buildFourthLevel(xCoord, buildingStartingHeight + Displacement::Y * 3, zCoord);
	buildFifthLevel(xCoord, buildingStartingHeight + Displacement::Y * 4, zCoord);
	buildSixthLevel(xCoord, buildingStartingHeight + Displacement::Y * 5, zCoord);
	buildSeventhLevel(xCoord, buildingStartingHeight + Displacement::Y * 6, zCoord);
	buildEigthLevel(xCoord, buildingStartingHeight + Displacement::Y * 7, zCoord);
	buildNinthLevel(xCoord, buildingStartingHeight + Displacement::Y * 8, zCoord);
}

void TreeA::buildFirstLevel(const float* xCoord, const float& y, const float* zCoord)
{
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[2], y, zCoord[2] }, rotation, scale));
}

void TreeA::buildSecondLevel(const float* xCoord, const float& y, const float* zCoord)
{
	buildFirstLevel(xCoord, y, zCoord);
}

void TreeA::buildThirdLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			if (i == 2 && j == 2)
				continue;
			vertices.push_back(Object(&minecraft.leaves, shader, { xCoord[i], y, zCoord[j] }, rotation, scale));
		}
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[2], y, zCoord[2] }, rotation, scale));
}


void TreeA::buildFourthLevel(const float* xCoord, const float& y, const float* zCoord){
	for (int i = 1; i < 4; i++)
		for (int j = 1; j < 4; j++) {
			if (i == 2 && j == 2)
				continue;
			vertices.push_back(Object(&minecraft.leaves, shader, { xCoord[i], y, zCoord[j] }, rotation, scale));
		}
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[2], y, zCoord[2] }, rotation, scale));
}

void TreeA::buildFifthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	buildFirstLevel(xCoord, y, zCoord);
}

void TreeA::buildSixthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	buildFourthLevel(xCoord, y, zCoord);
}

void TreeA::buildSeventhLevel(const float* xCoord, const float& y, const float* zCoord)
{
	vertices.push_back(Object(&minecraft.leaves, shader, { xCoord[1], y, zCoord[2] }, rotation, scale));
	vertices.push_back(Object(&minecraft.leaves, shader, { xCoord[2], y, zCoord[1] }, rotation, scale));
	vertices.push_back(Object(&minecraft.leaves, shader, { xCoord[2], y, zCoord[3] }, rotation, scale));
	vertices.push_back(Object(&minecraft.leaves, shader, { xCoord[3], y, zCoord[2] }, rotation, scale));

	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[2], y, zCoord[2] }, rotation, scale));
}

void TreeA::buildEigthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	buildFirstLevel(xCoord, y, zCoord);
}

void TreeA::buildNinthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 1; i < 4; i++)
		vertices.push_back(Object(&minecraft.leaves, shader, { xCoord[i], y, zCoord[2] }, rotation, scale));
	vertices.push_back(Object(&minecraft.leaves, shader, { xCoord[2], y, zCoord[1] }, rotation, scale));
	vertices.push_back(Object(&minecraft.leaves, shader, { xCoord[2], y, zCoord[3] }, rotation, scale));
}
