#include "Church.hpp"

Church::Church(gps::Shader& myShader)
	: MinecraftBuilding(myShader)
{
	setup();
}

void Church::setup() {
	const float xCorner = -20.0f;
	const float zCorner = -20.0f;
	const float xCoord[] = { xCorner, xCorner + Displacement::X, xCorner + 2 * Displacement::X, xCorner + 3 * Displacement::X, xCorner + 4 * Displacement::X };
	const float zCoord[] = { zCorner, zCorner + Displacement::Z, zCorner + 2 * Displacement::Z, zCorner + 3 * Displacement::Z, zCorner + 4 * Displacement::Z,
		zCorner + Displacement::Z * 5, zCorner + Displacement::Z * 6, zCorner + Displacement::Z * 7, zCorner + Displacement::Z * 8 };
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
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[8] }, rotation, scale));
	for (int i = 0; i < 5; i++)
		for (int j = 3; j < 8; j++)
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[j] }, rotation, scale));
	for (int i = 1; i < 4; i++)
		for (int j = 0; j < 3; j++)
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[j] }, rotation, scale));

}

void Church::buildSecondLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 1; i < 4; i++)
		for (int j = 7; j < 9; j++)
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[j] }, rotation, scale));
	for (int j = 7; j > 0; j--) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[j] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[j] }, rotation, scale));
	}
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[1], y, zCoord[0] }, rotation, scale));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[3], y, zCoord[0] }, rotation, scale));
}

void Church::buildThirdLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 1; i < 4; i++)
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[8] }, rotation, scale));
	for (int j = 7; j > 0; j--) {
		if (j == 2)
			continue;
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[j] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[j] }, rotation, scale));
	}
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[0], y, zCoord[2] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[4], y, zCoord[2] }, rotation, scale));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[1], y, zCoord[0] }, rotation, scale));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[3], y, zCoord[0] }, rotation, scale));
}

void Church::buildFourthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[1], y, zCoord[8] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[2], y, zCoord[8] }, rotation, scale));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[3], y, zCoord[8] }, rotation, scale));
	for (int j = 7; j > 0; j--) {
		if (j == 2 || j == 6)
			continue;
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[j] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[j] }, rotation, scale));
	}
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[0], y, zCoord[2] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[0], y, zCoord[6] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[4], y, zCoord[2] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[4], y, zCoord[6] }, rotation, scale));
	for (int i = 1; i < 4; i++)
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[0] }, rotation, scale));
}

void Church::buildFifthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 1; i < 4; i++)
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[0] }, rotation, scale));
	for (int j = 1; j < 9; j++) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[j] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[j] }, rotation, scale));
	}
	for (int i = 1; i < 4; i++)
		for (int j = 4; j < 9; j++) {
			if (i == 1 && j == 5)
				continue;
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[j] }, rotation, scale));
		}
}

void Church::buildSixthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 1; i < 4; i++)
		for (int j = 1; j < 5; j++)
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[j] }, rotation, scale));
	for (int j = 5; j < 8; j++) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[j] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[j] }, rotation, scale));
	}
	for(int i = 1; i < 4;i++)
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[8] }, rotation, scale));
}

void Church::buildSeventhLevel(const float* xCoord, const float& y, const float* zCoord)
{
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[1], y, zCoord[8] }, rotation, scale));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[3], y, zCoord[8] }, rotation, scale));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[1], y, zCoord[4] }, rotation, scale));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[3], y, zCoord[4] }, rotation, scale));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[7] }, rotation, scale));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[7] }, rotation, scale));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[5] }, rotation, scale));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[5] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[2], y, zCoord[8] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[0], y, zCoord[6] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[4], y, zCoord[6] }, rotation, scale));
	vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[2], y, zCoord[4] }, rotation, scale));
}

void Church::buildEigthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	buildSeventhLevel(xCoord, y, zCoord);
}

void Church::buildNinthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 1; i < 4; i++) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[8] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[4] }, rotation, scale));

	}
	for (int j = 5; j < 8; j++) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[j] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[j] }, rotation, scale));
	}
}

void Church::buildTenthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 0; i < 5; i++)
		for (int j = 4; j < 9; j++) {
			if (i == 1 && j == 5)
				continue;
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[j] }, rotation, scale));
		}
}

void Church::buildEleventhLevel(const float* xCoord, const float& y, const float* zCoord)
{
	buildNinthLevel(xCoord, y, zCoord);
}

void Church::buildTwelvthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[2], y, zCoord[8] }, rotation, scale));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[2], y, zCoord[4] }, rotation, scale));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[6] }, rotation, scale));
	vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[6] }, rotation, scale));

}
