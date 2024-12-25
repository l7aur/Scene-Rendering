#include "Util.hpp"

void Util::windowResizeCallback(GLFWwindow* window, int width, int height) {
	fprintf(stdout, "Window resized! New width: %d , and height: %d\n", width, height);
	glViewport(0, 0, width, height);
}

void Util::keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	myScene.getMyCamera()->keyboardCallback(deltaTime, window, key, scancode, action, mode);
}

void Util::mouseCallback(GLFWwindow* window, double xPos, double yPos) {
	myScene.getMyCamera()->mouseCallback(window, xPos, yPos);
}

void Util::scrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
	myScene.getMyCamera()->scrollCallback(window, xOffset, yOffset);
}

void Util::initShader(gps::Shader& shader, const char* vertexShaderPath, const char* fragmentShaderPath)
{
	shader.loadShader(vertexShaderPath, fragmentShaderPath);
}

void Util::buildScene(gps::Shader& shader)
{
	myScene.insertIntoScene(Object(&otherModels.grass, shader));

	const float dx = std::abs(Displacement::X);
	const float dz = std::abs(Displacement::Z);

	Well well1(shader, 4 * dx, 6 * dz);

	TreeA treeA1(shader, -5 * dx, 1 * dz);
	TreeA treeA2(shader, 8 * dx, 16 * dz);
	TreeA treeA3(shader, 16 * dx, -16 * dz);
	TreeA treeA4(shader, -7 * dx, -16 * dz);
	
	TreeB treeB1(shader, 9 * dx, -8 * dz);
	TreeB treeB2(shader, -7 * dx, 18 * dz);
	TreeB treeB3(shader, 18 * dx, -4 * dz);
	TreeB treeB4(shader, -21 * dx, 6 * dz);
	
	Church church1(shader, -7 * dx, -8 * dz);

	BigHouseA bigHA1(shader, 2 * dx, -17 * dz);
	BigHouseA bigHA2(shader, 17 * dx, -2 * dz);
	BigHouseA bigHA3(shader, -10 * dx, 7 * dz);

	SmallHouseA smallHA1(shader, -19 * dx, 2 * dz);
	SmallHouseA smallHA2(shader, -1 * dx, 18 * dz);
	SmallHouseA smallHA3(shader, 22 * dx, 9 * dz);

	myScene.insertIntoScene(well1.getVertices());

	myScene.insertIntoScene(treeA1.getVertices());
	myScene.insertIntoScene(treeA2.getVertices());
	myScene.insertIntoScene(treeA3.getVertices());
	myScene.insertIntoScene(treeA4.getVertices());

	myScene.insertIntoScene(treeB1.getVertices());
	myScene.insertIntoScene(treeB2.getVertices());
	myScene.insertIntoScene(treeB3.getVertices());
	myScene.insertIntoScene(treeB4.getVertices());

	myScene.insertIntoScene(church1.getVertices());

	myScene.insertIntoScene(bigHA1.getVertices());
	myScene.insertIntoScene(bigHA2.getVertices());
	myScene.insertIntoScene(bigHA3.getVertices());

	myScene.insertIntoScene(smallHA1.getVertices());
	myScene.insertIntoScene(smallHA2.getVertices());
	myScene.insertIntoScene(smallHA3.getVertices());
}

void Util::sortBlocks()
{
	std::vector<Object> v = myScene.getObjects();
	auto i = v.begin();
	auto j = v.rbegin();
	for (int k = 0; k < v.size();) {
		bool iStopped = false;
		bool jStopped = false;
		if (i->mesh == &minecraft.door ||
			i->mesh == &minecraft.fencePost ||
			i->mesh == &minecraft.glassBlock ||
			i->mesh == &minecraft.leaves ||
			i->mesh == &minecraft.water)
			iStopped = true;
		else
			i++, k++;
		if (j->mesh == &minecraft.door ||
			j->mesh == &minecraft.fencePost ||
			j->mesh == &minecraft.glassBlock ||
			j->mesh == &minecraft.leaves ||
			j->mesh == &minecraft.water)
			j++, k++;
		else
			jStopped = true;
		if (iStopped && jStopped)
			std::swap(*i, *j), j++, i++, k += 2;
	}
	/*for (auto& i : v) {
		if (i.mesh == &minecraft.cobblestone)
			std::cout << "cobblestone\n";
		if(i.mesh==&minecraft.door)
			std::cout << "door\n";
		if(i.mesh==&minecraft.leaves)
			std::cout << "leaves\n";
		if(i.mesh==&minecraft.sprucePlanks)
			std::cout << "planks\n";
		if(i.mesh==&minecraft.spruceLog)
			std::cout << "log\n";
		if(i.mesh==&minecraft.fencePost)
			std::cout << "fence\n";
		if(i.mesh==&minecraft.glassBlock)
			std::cout << "glass\n";
		if(i.mesh==&minecraft.spruceStairsDefault)
			std::cout << "stairs\n";
		if(i.mesh==&minecraft.spruceStairsOutsideCorner)
			std::cout << "stairsC\n";
		if(i.mesh==&minecraft.water)
			std::cout << "water\n";
	}*/
}

GLenum Util::glCheckError_(const char* file, int line)
{
	GLenum errorCode;
	while ((errorCode = glGetError()) != GL_NO_ERROR) {
		std::string error;
		switch (errorCode) {
		case GL_INVALID_ENUM:
			error = "INVALID_ENUM";
			break;
		case GL_INVALID_VALUE:
			error = "INVALID_VALUE";
			break;
		case GL_INVALID_OPERATION:
			error = "INVALID_OPERATION";
			break;
		case GL_OUT_OF_MEMORY:
			error = "OUT_OF_MEMORY";
			break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			error = "INVALID_FRAMEBUFFER_OPERATION";
			break;
		}
		std::cout << error << " | " << file << " (" << line << ")" << std::endl;
	}
	return errorCode;
}