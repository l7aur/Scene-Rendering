#pragma once

#include "glm/glm.hpp"
#include "GL/glew.h"

struct SnowFlake {
	glm::vec3 position{ 0.0f, 0.0f, 0.0f };
	float velocity{0.0f};
	float delay{ 0.0f };
};

class SnowController {
public:
	SnowController(int maxNumberOfSnowflakes);
	void init();
	void update(float deltaTime);
	void send();
	void draw();
private:
	GLuint VBO, VAO;
	SnowFlake generateFlake();
	std::vector<SnowFlake> flakes;
};