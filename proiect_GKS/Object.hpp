#pragma once

#include "Model3D.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> //glm extension for generating common transformation matrices
#include <glm/gtc/matrix_inverse.hpp> //glm extension for computing inverse matrices
#include <glm/gtc/type_ptr.hpp> //glm extension for accessing the internal data structure of glm types

struct Object {
    gps::Model3D* mesh;
    gps::Shader shader;
    glm::vec3 translation{ glm::vec3(0.0f) };
    glm::vec3 rotation{ glm::vec3(0.0f) };
    glm::vec3 scale{ glm::vec3(1.0f) };
    Object(gps::Model3D* m, gps::Shader& sh, glm::vec3 t, glm::vec3& r, glm::vec3& s) :
        mesh(m), shader(sh), translation(t), rotation(r), scale(s)
    {
    };
    Object(gps::Model3D* m, gps::Shader& sh, glm::vec3 t, glm::vec3& r) :
        mesh(m), shader(sh), translation(t), rotation(r)
    {
    };
    Object(gps::Model3D* m, gps::Shader& sh, glm::vec3 t) :
        mesh(m), shader(sh), translation(t)
    {
    };
    Object(gps::Model3D* m, gps::Shader& sh) :
        mesh(m), shader(sh)
    {
    };
    void render(GLint modelLoc, GLint normalMatrixLoc) {
        shader.useShaderProgram();
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, translation);
        model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, scale);
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glm::mat3 normalMatrix = glm::transpose(glm::inverse(glm::mat3(model)));
        glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
        mesh->Draw(shader);
    }
};
