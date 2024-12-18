#include "Inits.hpp"

void buildHouse()
{
	float yLevel = 1.0f;
	const float xArray[] = { 0.0f, 1.0f, 2.0f, 3.0f, 4.0f };
	const float zArray[] = { -10.0f, -9.0f, -8.0f, -7.0f, -6.0f };
	const glm::vec3 scale{ 0.5f,0.5f,0.5f };
	const glm::vec3 rotation{ 90.0f, 0.0f, 0.0f };

	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[2], yLevel, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[2], yLevel, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[2], yLevel, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[2], yLevel, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[2], yLevel, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel + 1, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel + 1, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel + 1, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel + 1, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel + 1, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel + 1, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel + 1, zArray[4] }, rotation, scale));
	//myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[2], yLevel + 1, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel + 1, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel + 1, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[2], yLevel + 1, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel + 1, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel + 2, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel + 2, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel + 2, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel + 2, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel + 2, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel + 2, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel + 2, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel + 2, zArray[4] }, rotation, scale));
	//myObjects.push_back(Object(&glassBlock, &myBasicShader, { xArray[2], yLevel + 2, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel + 3, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel + 3, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[4], yLevel + 3, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel + 3, zArray[1] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel + 3, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[0], yLevel + 3, zArray[3] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel + 3, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[2], yLevel + 3, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel + 3, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[1], yLevel + 3, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[2], yLevel + 3, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&cobblestoneBlock, &myBasicShader, { xArray[3], yLevel + 3, zArray[0] }, rotation, scale));

	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[0], yLevel, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[0], yLevel, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[0], yLevel + 1, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[4], yLevel, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[4], yLevel, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[0], yLevel + 1, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[4], yLevel + 1, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[4], yLevel + 1, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[4], yLevel + 2, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[4], yLevel + 2, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[0], yLevel + 2, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[0], yLevel + 2, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[4], yLevel + 3, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[0], yLevel + 3, zArray[4] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[0], yLevel + 3, zArray[0] }, rotation, scale));
	myObjects.push_back(Object(&spruceLog, &myBasicShader, { xArray[4], yLevel + 3, zArray[4] }, rotation, scale));

	myObjects.push_back(Object(&glassBlock, &myBasicShader, { xArray[4], yLevel + 2, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&glassBlock, &myBasicShader, { xArray[0], yLevel + 2, zArray[2] }, rotation, scale));
	myObjects.push_back(Object(&glassBlock, &myBasicShader, { xArray[2], yLevel + 2, zArray[0] }, rotation, scale));

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			myObjects.push_back(Object(&sprucePlanks, &myBasicShader, { xArray[i], yLevel + 4, zArray[j] }, rotation, scale));
}
