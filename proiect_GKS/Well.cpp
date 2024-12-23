#include "Well.hpp"

Well::Well(gps::Shader& myShader)
	: MinecraftBuilding(myShader)
{
	setup();
}

void Well::setup()
{
	const float xCorner = 20.0f;
	const float zCorner = 20.0f;
	const float xCoord[] = { xCorner, xCorner + Displacement::X, xCorner + 2 * Displacement::X, xCorner + 3 * Displacement::X, xCorner + 4 * Displacement::X, xCorner + 5 * Displacement::X, xCorner + 6 * Displacement::X };
	const float zCoord[] = { zCorner, zCorner + Displacement::Z, zCorner + 2 * Displacement::Z, zCorner + 3 * Displacement::Z, zCorner + 4 * Displacement::Z, zCorner + 5 * Displacement::Z, zCorner + 6 * Displacement::Z };
	buildFirstLevel(xCoord, buildingStartingHeight + Displacement::Y * 0, zCoord);
	buildSecondLevel(xCoord, buildingStartingHeight + Displacement::Y * 1, zCoord);
	buildThirdLevel(xCoord, buildingStartingHeight + Displacement::Y * 2, zCoord);
	buildFourthLevel(xCoord, buildingStartingHeight + Displacement::Y * 3, zCoord);
	buildFifthLevel(xCoord, buildingStartingHeight + Displacement::Y * 4, zCoord);
}

void Well::buildFirstLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for(int i = 0; i < 7; i++)
		for(int j = 0; j < 7; j++)
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[j] }, rotation, scale));
}

void Well::buildSecondLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 1; i <= 5; i++) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[1] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[5] }, rotation, scale));
	}
	for (int j = 2; j < 5; j++) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[1], y, zCoord[j] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[5], y, zCoord[j] }, rotation, scale));
	}
}

void Well::buildThirdLevel(const float* xCoord, const float& y, const float* zCoord)
{
	//add fencegates
	vertices.push_back(Object(&minecraft.fencePost, shader, { xCoord[1], y, zCoord[1] }, rotation, scale));
	vertices.push_back(Object(&minecraft.fencePost, shader, { xCoord[1], y, zCoord[5] }, rotation, scale));
	vertices.push_back(Object(&minecraft.fencePost, shader, { xCoord[5], y, zCoord[1] }, rotation, scale));
	vertices.push_back(Object(&minecraft.fencePost, shader, { xCoord[5], y, zCoord[5] }, rotation, scale));
	return;
}

void Well::buildFourthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	buildThirdLevel(xCoord, y, zCoord);
}

void Well::buildFifthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 1; i < 6; i++)
		for (int j = 1; j < 6; j++)
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[j] }, rotation, scale));
}
