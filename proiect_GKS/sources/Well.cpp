#include "../headers/Well.hpp"

Well::Well(gps::Shader& myShader, const float myCornerX, const float myCornerZ)
	: MinecraftBuilding(myShader, myCornerX, myCornerZ)
{
	setup();
}

void Well::setup()
{
	const float xCorner = 20.0f;
	const float zCorner = 20.0f;
	const float xCoord[] = { cornerX, cornerX + Displacement::X, cornerX + 2 * Displacement::X, cornerX + 3 * Displacement::X, cornerX + 4 * Displacement::X, cornerX + 5 * Displacement::X, cornerX + 6 * Displacement::X };
	const float zCoord[] = { cornerZ, cornerZ + Displacement::Z, cornerZ + 2 * Displacement::Z, cornerZ + 3 * Displacement::Z, cornerZ + 4 * Displacement::Z, cornerZ + 5 * Displacement::Z, cornerZ + 6 * Displacement::Z };
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
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
}

void Well::buildSecondLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 1; i <= 5; i++) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[1] }, rotation, scale, MATERIAL_TYPE::STONE));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[5] }, rotation, scale, MATERIAL_TYPE::STONE));
	}
	for (int j = 2; j < 5; j++) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[1], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[5], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
	}
	for (int i = 2; i < 5; i++)
		for (int j = 2; j < 5; j++)
			vertices.push_back(Object(&minecraft.water, shader, { xCoord[i], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::WATER));
}

void Well::buildThirdLevel(const float* xCoord, const float& y, const float* zCoord)
{
	vertices.push_back(Object(&minecraft.fencePost, shader, { xCoord[1], y, zCoord[1] }, rotation, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.fencePost, shader, { xCoord[1], y, zCoord[5] }, rotation, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.fencePost, shader, { xCoord[5], y, zCoord[1] }, rotation, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.fencePost, shader, { xCoord[5], y, zCoord[5] }, rotation, scale, MATERIAL_TYPE::WOOD));
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
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
}
