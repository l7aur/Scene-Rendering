#include "../headers/TreeB.hpp"

TreeB::TreeB(gps::Shader myShader, const float myCornerX, const float myCornerZ)
	: MinecraftBuilding(myShader, myCornerX, myCornerZ)
{
	setup();
}

void TreeB::setup()
{
	const float xCoord[] = { cornerX, cornerX+ Displacement::X, cornerX+ 2 * Displacement::X };
	const float zCoord[] = { cornerZ, cornerZ + Displacement::Z, cornerZ + 2 * Displacement::Z };
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

void TreeB::buildFirstLevel(const float* xCoord, const float& y, const float* zCoord)
{
	vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[1], y, zCoord[1] }, rotation, scale, MATERIAL_TYPE::LOG));
}

void TreeB::buildSecondLevel(const float* xCoord, const float& y, const float* zCoord)
{
	buildFirstLevel(xCoord, y, zCoord);
}

void TreeB::buildThirdLevel(const float* xCoord, const float& y, const float* zCoord)
{
	buildFirstLevel(xCoord, y, zCoord);
}

void TreeB::buildFourthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	buildFirstLevel(xCoord, y, zCoord);
}

void TreeB::buildFifthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	buildFirstLevel(xCoord, y, zCoord);
}

void TreeB::buildSixthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	buildFirstLevel(xCoord, y, zCoord);
}

void TreeB::buildSeventhLevel(const float* xCoord, const float& y, const float* zCoord)
{
	buildFirstLevel(xCoord, y, zCoord);
	vertices.push_back(Object(&minecraft.leaves, shader, { xCoord[0], y, zCoord[1] }, rotation, scale));
	vertices.push_back(Object(&minecraft.leaves, shader, { xCoord[1], y, zCoord[0] }, rotation, scale));
	vertices.push_back(Object(&minecraft.leaves, shader, { xCoord[2], y, zCoord[1] }, rotation, scale));
	vertices.push_back(Object(&minecraft.leaves, shader, { xCoord[1], y, zCoord[2] }, rotation, scale));
}

void TreeB::buildEigthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	buildSeventhLevel(xCoord, y, zCoord);
}

void TreeB::buildNinthLevel(const float* xCoord, const float& y, const float* zCoord)
{
	vertices.push_back(Object(&minecraft.leaves, shader, { xCoord[1], y, zCoord[1] }, rotation, scale));
}
