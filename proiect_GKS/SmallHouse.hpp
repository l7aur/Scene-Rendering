#pragma once

#include "ModelContainer.hpp"
#include "Object.hpp"
#include <glm/glm.hpp>
#include <vector>

extern ModelContainer::Minecraft minecraft;

struct SmallHouse {
	gps::Shader shader;
	std::vector<Object> vertices;
	glm::vec3 rotation{ 90.0f, 0.0f, 0.0f };
	glm::vec3 scale{ 1.0f, 1.0f, 1.0f };

	SmallHouse(gps::Shader& myShader)
		: shader(myShader)
	{
		setup();
	};
	void setup() {
		const float displacementX = 2.0f;
		const float displacementY = 2.0f;
		const float displacementZ = -2.0f;
		const float xCorner = 0.0f;
		const float zCorner = -5.0f;
		const float yCorner = 1.0f;
		const float xCoord[] = { xCorner, xCorner + displacementX, xCorner + 2 * displacementX, xCorner + 3 * displacementX, xCorner + 4 * displacementX };
		const float yCoord[] = { yCorner, yCorner + displacementY, yCorner + 2 * displacementY, yCorner + 3 * displacementY, yCorner + 4 * displacementY };
		const float zCoord[] = { zCorner, zCorner + displacementZ, zCorner + 2 * displacementZ, zCorner + 3 * displacementZ, zCorner + 4 * displacementZ };
		buildFirstLevel(xCoord, yCoord[0], zCoord);
		buildSecondLevel(xCoord, yCoord[1], zCoord);
		buildThirdLevel(xCoord, yCoord[2], zCoord);
		buildFourthLevel(xCoord, yCoord[3], zCoord);
		buildFifthLevel(xCoord, yCoord[4], zCoord);
	}

	void buildFirstLevel(const float* xCoord, const float& y, const float* zCoord) {
		addPillors(xCoord, y, zCoord);
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++) {
				if (i == 0 && j == 0 ||
					i == 4 && j == 4 ||
					i == 4 && j == 0 ||
					i == 4 && j == 4)
					continue;
				vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[j] }, rotation, scale));
			}
	}

	void buildSecondLevel(const float* xCoord, const float& y, const float* zCoord) {
		addPillors(xCoord, y, zCoord);
		for (int i = 1; i < 4; i++) {
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[4] }, rotation, scale));
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[i] }, rotation, scale));
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[i] }, rotation, scale));
		}
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[1], y, zCoord[0] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[3], y, zCoord[0] }, rotation, scale));
	}

	void buildThirdLevel(const float* xCoord, const float& y, const float* zCoord) {
		addPillors(xCoord, y, zCoord);
		for (int i = 1; i < 4; i++) {
			if (i == 2)
				continue;
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[4] }, rotation, scale));
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[i] }, rotation, scale));
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[i] }, rotation, scale));
		}
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[1], y, zCoord[0] }, rotation, scale));
		vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[3], y, zCoord[0] }, rotation, scale));

		vertices.push_back(Object(&minecraft.glassBlock , shader, { xCoord[2], y, zCoord[4] }, rotation, scale));
		vertices.push_back(Object(&minecraft.glassBlock , shader, { xCoord[0], y, zCoord[2] }, rotation, scale));
		vertices.push_back(Object(&minecraft.glassBlock , shader, { xCoord[4], y, zCoord[2] }, rotation, scale));
	}
	
	void buildFourthLevel(const float* xCoord, const float& y, const float* zCoord) {
		addPillors(xCoord, y, zCoord);
		for (int i = 1; i < 4; i++) {
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[0] }, rotation, scale));
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[i], y, zCoord[4] }, rotation, scale));
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[0], y, zCoord[i] }, rotation, scale));
			vertices.push_back(Object(&minecraft.cobblestone, shader, { xCoord[4], y, zCoord[i] }, rotation, scale));
		}
	}
	
	void buildFifthLevel(const float* xCoord, const float& y, const float* zCoord) {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				vertices.push_back(Object(&minecraft.sprucePlanks, shader, { xCoord[i], y, zCoord[j] }, rotation, scale));
	}
	
	void addPillors(const float* xCoord, const float& y, const float* zCoord) {
		vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[0], y, zCoord[0] }, rotation, scale));
		vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[4], y, zCoord[4] }, rotation, scale));
		vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[4], y, zCoord[0] }, rotation, scale));
		vertices.push_back(Object(&minecraft.spruceLog, shader, { xCoord[0], y, zCoord[4] }, rotation, scale));
	}
};