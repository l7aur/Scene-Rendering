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
        void setModelLocUniform(GLuint loc) { this->uniformModelLoc = loc; };

        GLuint getViewLocUniform() const { return this->uniformViewLoc; };
        void setViewLocUniform(GLuint loc) { this->uniformViewLoc = loc; };
        
        GLuint getProjectionLocUniform() const { return this->uniformProjectionLoc; };
        void setProjectionLocUniform(GLuint loc) { this->uniformProjectionLoc = loc; };
        
        GLuint getNormalMatrixLocUniform() const { return this->uniformNormalMatrixLoc; };
        void setNormalMatrixLocUniform(GLuint loc) { this->uniformNormalMatrixLoc = loc; };
 
        GLuint getEyePositionUniform() const { return this->uniformEyePosition; };
        void setEyePositionUniform(GLuint loc) { this->uniformEyePosition = loc; };
        
        GLuint getSpecularIntensityUniform() const { return this->uniformSpecularIntensity; };
        void setSpecularIntensityUniform(GLuint loc) { this->uniformSpecularIntensity = loc; };
        
        GLuint getSpecularShininessUniform() const { return this->uniformSpecularShininess; };
        void setSpecularShininessUniform(GLuint loc) { this->uniformSpecularShininess = loc; };

        /*Directional lights*/
        void setDirectionalLight(DirectionalLight * light);
        GLuint getDirectionalLDirectionUniform() const { return this->uniformDirectionalLight.direction; };
        void setDirectionalLDirectionUniform(GLuint loc) { this->uniformDirectionalLight.direction = loc; };
        GLuint getDirectionalLDiffuseIntensityUniform() const { return this->uniformDirectionalLight.diffuseIntensityLoc; };
        void setDirectionalLDiffuseIntensityUniform(GLuint loc) { this->uniformDirectionalLight.diffuseIntensityLoc = loc; };
        GLuint getDirectionalLAmbientIntensityUniform() const { return this->uniformDirectionalLight.ambientIntensityLoc; };
        void setDirectionalLAmbientIntensityUniform(GLuint loc) { this->uniformDirectionalLight.ambientIntensityLoc = loc; };
        GLuint getDirectionalLAmbientColourUniform() const { return this->uniformDirectionalLight.ambientColourLoc; };
        void setDirectionalLAmbientColourUniform(GLuint loc) { this->uniformDirectionalLight.ambientColourLoc = loc; };

        /*Point lights*/
        void setPointLights(PointLight* lights, unsigned int count);
        GLuint getPointLDiffuseIntensityUniform(int index) const { return this->uniformPointLights[index].diffuseIntensityLoc; };
        void setPointLDiffuseIntensityUniform(int index, GLuint loc) { this->uniformPointLights[index].diffuseIntensityLoc = loc; };
        GLuint getPointLAmbientIntensityUniform(int index) const { return this->uniformPointLights[index].ambientIntensityLoc; };
        void setPointLAmbientIntensityUniform(int index, GLuint loc) { this->uniformPointLights[index].ambientIntensityLoc = loc; };
        GLuint getPointLAmbientColourUniform(int index) const { return this->uniformPointLights[index].ambientColourLoc; };
        void setPointLAmbientColourUniform(int index, GLuint loc) { this->uniformPointLights[index].ambientColourLoc = loc; };
        GLuint getPointLLightPositionUniform(int index) const { return this->uniformPointLights[index].position; };
        void setPointLLightPositionUniform(int index, GLuint loc) { this->uniformPointLights[index].position = loc; };
        GLuint getPointLDimmingCoefficientsUniform(int index) const { return this->uniformPointLights[index].dimmingCoefficients; };
        void setPointLDimmingCoefficientsUniform(int index, GLuint loc) { this->uniformPointLights[index].dimmingCoefficients = loc; };
        GLuint getPointLightCountUniform() const { return this->pointLightCount; };
        void setPointLightCountUniform(GLuint loc) { this->pointLightCount = loc; };

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
        GLuint pointLightCount;

        void initUniforms();
        std::string readShaderFile(std::string fileName);
        void shaderCompileLog(GLuint shaderId);
        void shaderLinkLog(GLuint shaderProgramId);
    };
}

#endif /* Shader_hpp */
