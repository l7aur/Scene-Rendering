#include "../headers/Library.hpp"

Library::Library(gps::Shader& myShader, const float myCornerX, const float myCornerZ)
	: MinecraftBuilding(myShader, myCornerX, myCornerZ)
{
	setup();
}

void Library::setup()
{
	const float xCoord[] = { cornerX, cornerX + Displacement::X, cornerX + 2 * Displacement::X, cornerX + 3 * Displacement::X, cornerX + 4 * Displacement::X,
		cornerX + 5 * Displacement::X, cornerX + 6 * Displacement::X, cornerX + 7 * Displacement::X, cornerX + 8 * Displacement::X };
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
}

void Library::buildFirstLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int i = 1; i < 8; i++)
		for (int j = 2; j < 8; j++)
			vertices.push_back(Object(&minecraft.stoneBricks, shader, { xCoord[i], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
	for (int i = 2; i < 7; i++) {
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[0] }, rotation, scale, MATERIAL_TYPE::STONE));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[1] }, rotation, scale, MATERIAL_TYPE::STONE));
	}
}

void Library::buildSecondLevel(const float* xCoord, const float& y, const float* zCoord)
{
	addPillors(xCoord, y, zCoord);
	for (int i = 2; i < 7; i++) {
		vertices.push_back(Object(&minecraft.stoneBricks, shader, { xCoord[i], y, zCoord[7] }, rotation, scale, MATERIAL_TYPE::STONE));
		if (i == 3 || i == 5)
		{
			vertices.push_back(Object(&minecraft.door, shader, { xCoord[i], y, zCoord[2] }, rotation, scale, MATERIAL_TYPE::WOOD));
			continue;
		}
		vertices.push_back(Object(&minecraft.stoneBricks, shader, { xCoord[i], y, zCoord[2] }, rotation, scale, MATERIAL_TYPE::STONE));
	}
	for (int j = 3; j < 7; j++) {
		vertices.push_back(Object(&minecraft.stoneBricks, shader, { xCoord[1], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
		vertices.push_back(Object(&minecraft.stoneBricks, shader, { xCoord[7], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
	}
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[4], y, zCoord[6] }, rotation, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[5], y, zCoord[6] }, rotateY90, scale, MATERIAL_TYPE::WOOD));

	addBalconyPillors(xCoord, y, zCoord);
}

void Library::buildThirdLevel(const float* xCoord, const float& y, const float* zCoord)
{
	addPillors(xCoord, y, zCoord); 
	for (int i = 2; i < 7; i++) {
		if (i == 3 || i == 5)
		{
			vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[i], y, zCoord[7] }, rotation, scale, MATERIAL_TYPE::GLASS));
			continue;
		}
		vertices.push_back(Object(&minecraft.stoneBricks, shader, { xCoord[i], y, zCoord[7] }, rotation, scale, MATERIAL_TYPE::STONE));
		vertices.push_back(Object(&minecraft.stoneBricks, shader, { xCoord[i], y, zCoord[2] }, rotation, scale, MATERIAL_TYPE::STONE));
	}
	for (int j = 3; j < 7; j++) {
		if (j == 4 || j == 5) {
			vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[1], y, zCoord[j] }, windowR, scale, MATERIAL_TYPE::GLASS));
			vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[7], y, zCoord[j] }, windowR, scale, MATERIAL_TYPE::GLASS));
			continue;
		}
		vertices.push_back(Object(&minecraft.stoneBricks, shader, { xCoord[1], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
		vertices.push_back(Object(&minecraft.stoneBricks, shader, { xCoord[7], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
	}
	vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[4], y, zCoord[6] }, rotateY90, scale, MATERIAL_TYPE::WOOD));
	addBalconyPillors(xCoord, y, zCoord);
}

void Library::buildFourthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	addPillors(xCoord, y, zCoord);
	for (int i = 2; i < 7; i++) {
		vertices.push_back(Object(&minecraft.stoneBricks, shader, { xCoord[i], y, zCoord[2] }, rotation, scale, MATERIAL_TYPE::STONE));
		vertices.push_back(Object(&minecraft.stoneBricks, shader, { xCoord[i], y, zCoord[7] }, rotation, scale, MATERIAL_TYPE::STONE));
	}
	for (int j = 3; j < 7; j++) {
		vertices.push_back(Object(&minecraft.stoneBricks, shader, { xCoord[1], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
		vertices.push_back(Object(&minecraft.stoneBricks, shader, { xCoord[7], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::STONE));
	}
	vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[3], y, zCoord[6] }, rotateY90, scale, MATERIAL_TYPE::WOOD));
	addBalconyPillors(xCoord, y, zCoord);
}

void Library::buildFifthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[2], y, zCoord[6] }, rotateY90, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[6], y, zCoord[6] }, rotation, scale, MATERIAL_TYPE::WOOD));
	for (int i = 2; i < 7; i++)
		for (int j = 2; j < 7; j++) {
			if (j == 3) {
				vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[i], y, zCoord[7] }, rotateY90, scale, MATERIAL_TYPE::LOG));
				vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[i], y, zCoord[3] }, rotateY90, scale, MATERIAL_TYPE::LOG));
				vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[i], y, zCoord[1] }, rotateY90, scale, MATERIAL_TYPE::LOG));
				vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[i], y, zCoord[0] }, rotateY90, scale, MATERIAL_TYPE::LOG));
				continue;
			}
			if (j == 6)
				continue;
			vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::WOOD));
		}
		vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[1], y, zCoord[3] }, rotateY90, scale, MATERIAL_TYPE::LOG));
		vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[7], y, zCoord[3] }, rotateY90, scale, MATERIAL_TYPE::LOG));
		vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[1], y, zCoord[7] }, rotateY90, scale, MATERIAL_TYPE::LOG));
		vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[7], y, zCoord[7] }, rotateY90, scale, MATERIAL_TYPE::LOG));
		for (int j = 2; j < 7; j++) {
			if (j == 3)
				continue;
			vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[1], y, zCoord[j] }, noRotation, scale, MATERIAL_TYPE::LOG));
			vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[7], y, zCoord[j] }, noRotation, scale, MATERIAL_TYPE::LOG));
		}
}

void Library::buildSixthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	addPillors(xCoord, y, zCoord);
	addBalconyPillors(xCoord, y, zCoord);
	glm::vec3 widen{ 1.0f, 1.0f, 2.0f };
	vertices.push_back(Object(&minecraft.fencePost, shader, { xCoord[3], y, zCoord[0] }, rotateY90, widen, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.fencePost, shader, { xCoord[5], y, zCoord[0] }, rotateY90, widen, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.fencePost, shader, { xCoord[2], y, zCoord[1] }, noRotation, widen, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.fencePost, shader, { xCoord[6], y, zCoord[1] }, noRotation, widen, MATERIAL_TYPE::WOOD));
	for (int i = 2; i < 7; i++) {
		if (i == 4) {
			vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[i], y, zCoord[2] }, rotation, scale, MATERIAL_TYPE::LOG));
			vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[i], y, zCoord[7] }, rotation, scale, MATERIAL_TYPE::LOG));
			continue;
		}
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[7] }, rotation, scale, MATERIAL_TYPE::WOOD));
		if (i == 3 || i == 5) {
			vertices.push_back(Object(&minecraft.door, shader, { xCoord[i], y, zCoord[2] }, rotation, scale, MATERIAL_TYPE::WOOD));
			continue;
		}
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[2] }, rotation, scale, MATERIAL_TYPE::WOOD));
	}
	for (int j = 3; j < 7; j++) {
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[1], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::WOOD));
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[7], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::WOOD));
	}
}

void Library::buildSeventhLevel(const float* xCoord, const float& y, const float* zCoord)
{
	addPillors(xCoord, y, zCoord); 
	for (int i = 2; i < 7; i++) {
		if (i == 3 || i == 5)
		{
			vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[i], y, zCoord[7] }, rotation, scale, MATERIAL_TYPE::GLASS));
			continue;
		}
		if (i == 4) {
			vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[i], y, zCoord[2] }, rotation, scale, MATERIAL_TYPE::LOG));
			vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[i], y, zCoord[7] }, rotation, scale, MATERIAL_TYPE::LOG));
			continue;
		}
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[7] }, rotation, scale, MATERIAL_TYPE::WOOD));
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[2] }, rotation, scale, MATERIAL_TYPE::WOOD));
	}
	for (int j = 3; j < 7; j++) {
		if (j == 4 || j == 5) {
			vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[1], y, zCoord[j] }, windowR, scale, MATERIAL_TYPE::GLASS));
			vertices.push_back(Object(&minecraft.glassBlock, shader, { xCoord[7], y, zCoord[j] }, windowR, scale, MATERIAL_TYPE::GLASS));
			continue;
		}
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[1], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::WOOD));
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[7], y, zCoord[j] }, rotation, scale, MATERIAL_TYPE::WOOD));
	}
	vertices.push_back(Object(&minecraft.spruceStairsOutsideCorner, shader, { xCoord[0], y, zCoord[1] }, rotateYminus90, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[1], y, zCoord[1] }, noRotation, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[7], y, zCoord[1] }, noRotation, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.spruceStairsOutsideCorner, shader, { xCoord[8], y, zCoord[1] }, noRotation, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[0], y, zCoord[2] }, rotateYminus90, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[0], y, zCoord[3] }, rotateYminus90, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[8], y, zCoord[2] }, rotateY90, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[8], y, zCoord[3] }, rotateY90, scale, MATERIAL_TYPE::WOOD));

	vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[0], y, zCoord[6] }, rotateYminus90, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[0], y, zCoord[7] }, rotateYminus90, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[8], y, zCoord[6] }, rotateY90, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[8], y, zCoord[7] }, rotateY90, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.spruceStairsOutsideCorner, shader, { xCoord[0], y, zCoord[8] }, rotateY180, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[1], y, zCoord[8] }, rotateY180, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[7], y, zCoord[8] }, rotateY180, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.spruceStairsOutsideCorner, shader, { xCoord[8], y, zCoord[8] }, rotateY90, scale, MATERIAL_TYPE::WOOD));

}

void Library::buildEigthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int j = 1; j < 9; j++) {
		vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[1], y, zCoord[j] }, rotateYminus90, scale, MATERIAL_TYPE::WOOD));
		vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[7], y, zCoord[j] }, rotateY90, scale, MATERIAL_TYPE::WOOD));
	}
	for (int i = 2; i < 7; i++) {
		if (i == 4) {
			vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[i], y, zCoord[2] }, rotation, scale, MATERIAL_TYPE::LOG));
			vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[i], y, zCoord[7] }, rotation, scale, MATERIAL_TYPE::LOG));
			continue;
		}
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[2] }, rotation, scale, MATERIAL_TYPE::WOOD));
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[7] }, rotation, scale, MATERIAL_TYPE::WOOD));
	}
}

void Library::buildNinthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int j = 1; j < 9; j++) {
		vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[2], y, zCoord[j] }, rotateYminus90, scale, MATERIAL_TYPE::WOOD));
		vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[6], y, zCoord[j] }, rotateY90, scale, MATERIAL_TYPE::WOOD));
	}
	for (int i = 3; i < 6; i++) {
		if (i == 4) {
			vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[i], y, zCoord[2] }, rotation, scale, MATERIAL_TYPE::LOG));
			vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[i], y, zCoord[7] }, rotation, scale, MATERIAL_TYPE::LOG));
			continue;
		}
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[2] }, rotation, scale, MATERIAL_TYPE::WOOD));
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[7] }, rotation, scale, MATERIAL_TYPE::WOOD));
	}
}

void Library::buildTenthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	for (int j = 1; j < 9; j++) {
		vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[3], y, zCoord[j] }, rotateYminus90, scale, MATERIAL_TYPE::WOOD));
		vertices.push_back(Object(&minecraft.spruceStairsDefault, shader, { xCoord[5], y, zCoord[j] }, rotateY90, scale, MATERIAL_TYPE::WOOD));
	}
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[4], y, zCoord[2] }, rotation, scale, MATERIAL_TYPE::LOG));
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[4], y, zCoord[7] }, rotation, scale, MATERIAL_TYPE::LOG));
}

void Library::buildEleventhLevel(const float* xCoord, const float& y, const float* zCoord)
{
	glm::vec3 scale{ 1.0f, 0.5f, 1.0f };
	for (int j = 1; j < 9; j++) {
		vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[4], y - Displacement::Y / 4.0f, zCoord[j] }, rotateYminus90, scale, MATERIAL_TYPE::WOOD));
	}
}

void Library::addPillors(const float* xCoord, const float& y, const float* zCoord) {
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[1], y, zCoord[2] }, rotation, scale, MATERIAL_TYPE::LOG));
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[1], y, zCoord[7] }, rotation, scale, MATERIAL_TYPE::LOG));
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[7], y, zCoord[2] }, rotation, scale, MATERIAL_TYPE::LOG));
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[7], y, zCoord[7] }, rotation, scale, MATERIAL_TYPE::LOG));
}

void Library::addBalconyPillors(const float* xCoord, const float& y, const float* zCoord)
{
	vertices.push_back(Object(&minecraft.fencePost, shader, { xCoord[2], y, zCoord[0] }, rotation, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.fencePost, shader, { xCoord[4], y, zCoord[0] }, rotation, scale, MATERIAL_TYPE::WOOD));
	vertices.push_back(Object(&minecraft.fencePost, shader, { xCoord[6], y, zCoord[0] }, rotation, scale, MATERIAL_TYPE::WOOD));
}