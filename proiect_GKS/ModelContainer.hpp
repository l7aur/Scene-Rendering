#pragma once

#include "Model3D.hpp"

namespace ModelContainer {
	constexpr float yLevel = 1.0f;

	struct Minecraft {
		gps::Model3D spruceLog;
		gps::Model3D cobblestone;
		gps::Model3D sprucePlanks;
		gps::Model3D glassBlock;
		Minecraft() {
			spruceLog.LoadModel("models/spruce_log/spruce_log.obj");
			cobblestone.LoadModel("models/cobblestone/cobblestone.obj");
			glassBlock.LoadModel("models/glass_block/glass_block.obj");
			sprucePlanks.LoadModel("models/wooden_spruce_planks/wooden_spruce_planks.obj");
		}
	};

	struct Others {
		gps::Model3D grass;
		Others() {
			grass.LoadModel("models/others/grass/grass.obj");
		}
	};
}
