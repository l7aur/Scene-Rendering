#pragma once

#include "MinecraftBuilding.hpp"

class TreeB : public MinecraftBuilding {
public:
	TreeB(gps::Shader myShader);
private:
	virtual void setup() override;
	virtual void buildFirstLevel(const float* xCoord, const float& y, const float* zCoord) override;
	virtual void buildSecondLevel(const float* xCoord, const float& y, const float* zCoord) override;
	virtual void buildThirdLevel(const float* xCoord, const float& y, const float* zCoord) override;
	virtual void buildFourthLevel(const float* xCoord, const float& y, const float* zCoord) override;
	virtual void buildFifthLevel(const float* xCoord, const float& y, const float* zCoord) override;
	virtual void buildSixthLevel(const float* xCoord, const float& y, const float* zCoord) override;
	virtual void buildSeventhLevel(const float* xCoord, const float& y, const float* zCoord) override;
	virtual void buildEigthLevel(const float* xCoord, const float& y, const float* zCoord) override;
	virtual void buildNinthLevel(const float* xCoord, const float& y, const float* zCoord) override;
};