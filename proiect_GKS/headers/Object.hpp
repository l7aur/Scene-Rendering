#pragma once

#include "Model3D.hpp"
#include "Material.hpp"
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
    Material material{ MATERIAL_TYPE::NONE };
    Object(gps::Model3D* m, gps::Shader& sh, glm::vec3 t, glm::vec3& r, glm::vec3& s, MATERIAL_TYPE type = NONE) :
        mesh(m), shader(sh), translation(t), rotation(r), scale(s), material(type)
    {
    };
    Object(gps::Model3D* m, gps::Shader& sh, glm::vec3 t, glm::vec3& r, MATERIAL_TYPE type = NONE) :
        mesh(m), shader(sh), translation(t), rotation(r), material(type)
    {
    };
    Object(gps::Model3D* m, gps::Shader& sh, glm::vec3 t, MATERIAL_TYPE type = NONE) :
        mesh(m), shader(sh), translation(t), material(type)
    {
    };
    Object(gps::Model3D* m, gps::Shader& sh, MATERIAL_TYPE type = NONE) :
        mesh(m), shader(sh), material(type)
    {
    };
    void render(glm::vec3 eyePosition) {
        shader.useShaderProgram();
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, translation);
        model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, scale);
        glUniformMatrix4fv(shader.getModelLocUniform(), 1, GL_FALSE, glm::value_ptr(model));
        glm::mat3 normalMatrix = glm::transpose(glm::inverse(glm::mat3(model)));
        glUniformMatrix3fv(shader.getNormalMatrixLocUniform(), 1, GL_FALSE, glm::value_ptr(normalMatrix));

        glUniform3f(shader.getEyePositionUniform(), eyePosition.x, eyePosition.y, eyePosition.z);
        material.useMaterial(shader.getSpecularIntensityUniform(), shader.getSpecularShininessUniform());

        mesh->Draw(shader);
    };
};
