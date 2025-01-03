#include "../headers/Church.hpp"

Church::Church(gps::Shader& myShader, const float myCornerX, const float myCornerZ)
	: MinecraftBuilding(myShader, myCornerX, myCornerX)
{
	setup();
}

void Church::setup() {
	const float xCoord[] = { cornerX, cornerX + Displacement::X, cornerX + 2 * Displacement::X, cornerX + 3 * Displacement::X, cornerX + 4 * Displacement::X };
	const float zCoord[] = { cornerZ, cornerZ + Displacement::Z, cornerZ + 2 * Displacement::Z, cornerZ + 3 * Displacement::Z, cornerZ + 4 * Displacement::Z,
		cornerZ + Displacement::Z * 5, cornerZ + Displacement::Z * 6, cornerZ + Displacement::Z * 7, cornerZ + Displacement::Z * 8 };
	buildFirstLevel(xCoord, buildingStartingHeight + Displacement::Y * 0, zCoord);
	buildSecondLevel(xCoord, buildingStartingHeight + Displacement::Y * 1, zCoord);
	buildThirdLevel(xCoord, buildingStartingHeight + Displacement::Y * 2, zCoord);
	buildFourthLevel(xCoord, buildingStartingHeight + Displacement::Y * 3, zCoord);
	buildFifthLevel(xCoord, buildingStartingHeight + Displacement::Y * 4, zCoord);
	buildSixthLevel(xCoord, buildingStartingHeight + Displacement::Y * 5, zCoord);
	buildSeventhLevel(xCoord, buildingStartingHeight + Displacement::Y * 6, zCoord);
	buildEigthLevel(xCoord, buildingStartingHeight + Displacement::Y * 7, zCoord);
	buildNinthLevel(xCoord, buildingStartingHeight + Displacement::Y * 8, zCoord);
	buildTenthLevel(xCoord, buildingStartingHeight + Displacement::Y * 9, zCoord);
	buildEleventhLevel(xCoord, buildingStartingHeight + Displacement::Y * 10, zCoord);
	buildTwelvthLevel(xCoord, buildingStartingHeight + Displacement::Y * 11, zCoord);
}

void Church::buildFirstLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 1; i < 4; i++)
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[8] }, rotation, scale, MATERIAL_TYPE::STONE));
	for (int i = 0; i < 5; i++)
		for (int j = 3; j < 8; j++)
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
	for (int i = 1; i < 4; i++)
		for (int j = 0; j < 3; j++)
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));

}

void Church::buildSecondLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 1; i < 4; i++)
		for (int j = 7; j < 9; j++)
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
	for (int j = 7; j > 0; j--) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
	}
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[1], y, zCoord[0] }, rotation, scale, MATERIAL_TYPE::STONE));
	vertices.push_back(Object(&minecraft.door, shader, { xCoord[2], y, zCoord[0] }, rotation, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[3], y, zCoord[0] }, rotation, scale, MATERIAL_TYPE::STONE));
}

void Church::buildThirdLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 1; i < 4; i++)
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[8] }, rotation, scale, MATERIAL_TYPE::STONE));
	for (int j = 7; j > 0; j--) {
		if (j == 2)
			continue;
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
	}
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[0], y, zCoord[2] }, windowR, scale, MATERIAL_TYPE::GLASS));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[4], y, zCoord[2] }, windowR, scale, MATERIAL_TYPE::GLASS));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[1], y, zCoord[0] }, windowR, scale, MATERIAL_TYPE::STONE));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[3], y, zCoord[0] }, windowR, scale, MATERIAL_TYPE::STONE));
}

void Church::buildFourthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[1], y, zCoord[8] }, rotation, scale, MATERIAL_TYPE::STONE));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[2], y, zCoord[8] }, rotation, scale, MATERIAL_TYPE::GLASS));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[3], y, zCoord[8] }, rotation, scale, MATERIAL_TYPE::STONE));
	for (int j = 7; j > 0; j--) {
		if (j == 2 || j == 6)
			continue;
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
	}
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[0], y, zCoord[2] }, windowR, scale, MATERIAL_TYPE::GLASS));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[0], y, zCoord[6] }, windowR, scale, MATERIAL_TYPE::GLASS));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[4], y, zCoord[2] }, windowR, scale, MATERIAL_TYPE::GLASS));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[4], y, zCoord[6] }, windowR, scale, MATERIAL_TYPE::GLASS));
	for (int i = 1; i < 4; i++)
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[0] }, rotation, scale, MATERIAL_TYPE::STONE));
}

void Church::buildFifthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 1; i < 4; i++)
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[0] }, rotation, scale, MATERIAL_TYPE::STONE));
	for (int j = 1; j < 9; j++) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
	}
	for (int i = 1; i < 4; i++)
		for (int j = 4; j < 9; j++) {
			if (i == 1 && j == 5)
				continue;
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
		}
}

void Church::buildSixthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 1; i < 4; i++)
		for (int j = 1; j < 5; j++)
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
	for (int j = 5; j < 8; j++) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
	}
	for(int i = 1; i < 4;i++)
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[8] }, rotation, scale, MATERIAL_TYPE::STONE));
}

void Church::buildSeventhLevel(const float* xCoord, const float& y, const float* zCoord)
{
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[1], y, zCoord[8] }, rotation, scale, MATERIAL_TYPE::STONE));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[3], y, zCoord[8] }, rotation, scale, MATERIAL_TYPE::STONE));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[1], y, zCoord[4] }, rotation, scale, MATERIAL_TYPE::STONE));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[3], y, zCoord[4] }, rotation, scale, MATERIAL_TYPE::STONE));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[7] }, rotation, scale, MATERIAL_TYPE::STONE));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[7] }, rotation, scale, MATERIAL_TYPE::STONE));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[5] }, rotation, scale, MATERIAL_TYPE::STONE));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[5] }, rotation, scale, MATERIAL_TYPE::STONE));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[2], y, zCoord[8] }, rotation, scale, MATERIAL_TYPE::GLASS));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[0], y, zCoord[6] }, windowR, scale, MATERIAL_TYPE::GLASS));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[4], y, zCoord[6] }, windowR, scale, MATERIAL_TYPE::GLASS));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[2], y, zCoord[4] }, rotation, scale, MATERIAL_TYPE::GLASS));
}

void Church::buildEigthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	buildSeventhLevel(xCoord, y, zCoord);
}

void Church::buildNinthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 1; i < 4; i++) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[8] }, rotation, scale, MATERIAL_TYPE::STONE));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[4] }, rotation, scale, MATERIAL_TYPE::STONE));

	}
	for (int j = 5; j < 8; j++) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
	}
}

void Church::buildTenthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 0; i < 5; i++)
		for (int j = 4; j < 9; j++) {
			if (i == 1 && j == 5)
				continue;
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
		}
}

void Church::buildEleventhLevel(const float* xCoord, const float& y, const float* zCoord)
{
	buildNinthLevel(xCoord, y, zCoord);
}

void Church::buildTwelvthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[2], y, zCoord[8] }, rotation, scale, MATERIAL_TYPE::STONE));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[2], y, zCoord[4] }, rotation, scale, MATERIAL_TYPE::STONE));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[6] }, rotation, scale, MATERIAL_TYPE::STONE));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[6] }, rotation, scale, MATERIAL_TYPE::STONE));

}
