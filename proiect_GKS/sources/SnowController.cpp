#include "../headers/SnowController.hpp"

SnowController::SnowController(int maxNumberOfSnowflakes)
{
	for (int i = 0; i < maxNumberOfSnowflakes; ++i)
		flakes.push_back(generateFlake());
}

void SnowController::init()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, 2 * flakes.size() * sizeof(glm::vec3), nullptr, GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, NULL, NULL);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

void SnowController::update(float deltaTime)
{
    for (auto& f : flakes)
        if (f.delay > 0)
            f.delay -= deltaTime;
        else {
            f.position += glm::normalize(glm::vec3{ rand() * 2, rand() * 3, rand() * 5 }) * deltaTime;
            if (f.position.y < -50.0f)
                f = generateFlake();

        }
}

void SnowController::send()
{
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferSubData(GL_ARRAY_BUFFER, 0, flakes.size() * sizeof(glm::vec3), flakes.data());

    glBindVertexArray(0);
}

void SnowController::draw()
{
    glBindVertexArray(VAO);
    glDrawArrays(GL_POINTS, 0, 2 * flakes.size());
    glBindVertexArray(0);
}

SnowFlake SnowController::generateFlake()
{
	SnowFlake sf;
	sf.position = glm::vec3{ rand() * 119 % 100, 50 + rand() * 101 % 13, rand() * 119 % 100 };
	sf.velocity = rand() * 97 % 7 + 1;
    sf.delay = rand() * 103 % 79;
	return sf;
}
