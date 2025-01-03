//
//  Shader.hpp
//  Lab3
//
//  Created by CGIS on 05/10/2016.
//  Copyright © 2016 CGIS. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#define GLEW_STATIC
#include <GL/glew.h>
#include "glm/gtc/type_ptr.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

#include "../CommonValues.hpp"
#include "DirectionalLight.hpp"
#include "PointLight.hpp"

namespace gps {

    class Shader {

    public:
        GLuint shaderProgram;
        void loadShader(std::string vertexShaderFileName, std::string fragmentShaderFileName);
        void useShaderProgram();

        GLuint getModelLocUniform() const { return this->uniformModelLoc; };
        GLuint getViewLocUniform() const { return this->uniformViewLoc; };
        GLuint getProjectionLocUniform() const { return this->uniformProjectionLoc; };
        GLuint getNormalMatrixLocUniform() const { return this->uniformNormalMatrixLoc; };
 
        GLuint getEyePositionUniform() const { return this->uniformEyePosition; };
        
        GLuint getSpecularIntensityUniform() const { return this->uniformSpecularIntensity; };
        GLuint getSpecularShininessUniform() const { return this->uniformSpecularShininess; };

        /*Directional lights*/
        void setDirectionalLight(DirectionalLight * light);
        GLuint getDirectionalLDirectionUniform() const { return this->uniformDirectionalLight.direction; };
        GLuint getDirectionalLDiffuseIntensityUniform() const { return this->uniformDirectionalLight.diffuseIntensityLoc; };
        GLuint getDirectionalLAmbientIntensityUniform() const { return this->uniformDirectionalLight.ambientIntensityLoc; };
        GLuint getDirectionalLAmbientColourUniform() const { return this->uniformDirectionalLight.ambientColourLoc; };

        /*Point lights*/
        void setPointLights(PointLight* lights, unsigned int count);
        GLuint getPointLDiffuseIntensityUniform(int index) const { return this->uniformPointLights[index].diffuseIntensityLoc; };
        GLuint getPointLAmbientIntensityUniform(int index) const { return this->uniformPointLights[index].ambientIntensityLoc; };
        GLuint getPointLAmbientColourUniform(int index) const { return this->uniformPointLights[index].ambientColourLoc; };
        GLuint getPointLLightPositionUniform(int index) const { return this->uniformPointLights[index].position; };
        GLuint getPointLDimmingCoefficientsUniform(int index) const { return this->uniformPointLights[index].dimmingCoefficients; };
        GLuint getPointLightCountUniform() const { return this->uniformPointLightCount; };

        GLuint getDirectionalLightTransformUniform() const { return this->uniformDirectionalLightTransform; };
        GLuint getDirectionalShadowMapUniform() const { return this->uniformDirectionalShadowMap; };

        void sendDirectionalLightTransformUniform(glm::mat4 lTransform) { glUniformMatrix4fv(uniformDirectionalLightTransform, 1, GL_FALSE, glm::value_ptr(lTransform)); };
        void sendDirectionalShadowMap(GLuint textureUnit) { glUniform1i(uniformDirectionalShadowMap, textureUnit); };
        void sendTextureUniform(GLuint textureUnit) { glUniform1i(uniformTexture, textureUnit); };

    private:
        struct {
            GLuint ambientIntensityLoc{};
            GLuint ambientColourLoc{};
            GLuint diffuseIntensityLoc{};

            GLuint direction{};
        } uniformDirectionalLight;
        struct {
            GLuint ambientIntensityLoc{};
            GLuint ambientColourLoc{};
            GLuint diffuseIntensityLoc{};

            GLuint position{};
            GLuint dimmingCoefficients{};
        } uniformPointLights[MAX_NUMBER_OF_POINT_LIGHTS];

        GLuint uniformModelLoc{};
        GLuint uniformViewLoc{};
        GLuint uniformProjectionLoc{};
        GLuint uniformNormalMatrixLoc{};
        GLuint uniformEyePosition{};
        GLuint uniformSpecularIntensity{};
        GLuint uniformSpecularShininess{};
        GLuint uniformPointLightCount{};
        GLuint uniformDirectionalLightTransform{};
        GLuint uniformDirectionalShadowMap{};
        GLuint uniformTexture;

        void initUniforms();
        std::string readShaderFile(std::string fileName);
        void shaderCompileLog(GLuint shaderId);
        void shaderLinkLog(GLuint shaderProgramId);
    };
}

#endif /* Shader_hpp */
