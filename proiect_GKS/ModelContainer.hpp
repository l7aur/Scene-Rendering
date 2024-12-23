#pragma once

#include "Model3D.hpp"

namespace ModelContainer {
	constexpr float yLevel = 1.0f;

	struct Minecraft {
		gps::Model3D spruceLog;
		gps::Model3D cobblestone;
		gps::Model3D sprucePlanks;
		gps::Model3D glassBlock;
		gps::Model3D fencePost;
		gps::Model3D water;
		gps::Model3D spruceStairsDefault;
		gps::Model3D spruceStairsOutsideCorner;
		gps::Model3D leaves;
		Minecraft() {
			spruceLog.LoadModel("models/spruce_log/spruce_log.obj");
			cobblestone.LoadModel("models/cobblestone/cobblestone.obj");
			glassBlock.LoadModel("models/glass_block/glass_block.obj");
			sprucePlanks.LoadModel("models/wooden_spruce_planks/wooden_spruce_planks.obj");
			/*DEBUG*/ fencePost = water = spruceStairsDefault = spruceStairsOutsideCorner = spruceLog;
			/*DEBUG*/ leaves = cobblestone;
			
			// to be added
			// fencePost.LoadModel("models/fence_post/fence_post.obj");
			// spruceStairs.LoadModel("models/spruce_stairs/spruce_stairs.obj");
			// water.LoadModel("models/water/water.obj");
		}
	};

	struct Others {
		gps::Model3D grass;
		Others() {
			grass.LoadModel("models/others/grass/grass.obj");
		}
	};
}
