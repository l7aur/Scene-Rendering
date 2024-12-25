#pragma once

#include "MinecraftBuilding.hpp"

class SmallHouseA : public MinecraftBuilding {
public:
	SmallHouseA(gps::Shader& myShader, const float myCornerX, const float myCornerZ);
private:
	virtual void setup() override;
	virtual void buildFirstLevel(const float* xCoord, const float& y, const float* zCoord) override;
	virtual void buildSecondLevel(const float* xCoord, const float& y, const float* zCoord) override;
	virtual void buildThirdLevel(const float* xCoord, const float& y, const float* zCoord) override;
	virtual void buildFourthLevel(const float* xCoord, const float& y, const float* zCoord) override;
	virtual void buildFifthLevel(const float* xCoord, const float& y, const float* zCoord) override;
	virtual void buildSixthLevel(const float* xCoord, const float& y, const float* zCoord) override;
	virtual void buildSeventhLevel(const float* xCoord, const float& y, const float* zCoord) override;
	void addPillors(const float* xCoord, const float& y, const float* zCoord);

	glm::vec3 rF = {0.0f, 0.0f, 0.0f};
	glm::vec3 rB = {0.0f, -180.0f, 0.0f};
	glm::vec3 rR = glm::vec3{ 0.0f, 90.0f, 0.0f };
	glm::vec3 rL = glm::vec3{ 0.0f, -90.0f, 0.0f };

	glm::vec3 rCRB = glm::vec3{ 0.0, 90.0f, 0.0f };
	glm::vec3 rCLB = glm::vec3{ 0.0, 180.0f, 0.0f };
	glm::vec3 rCLF = glm::vec3{ 0.0, -90.0f, 0.0f };
	glm::vec3 rCRF = glm::vec3{ 0.0, 0.0f, 0.0f };
};