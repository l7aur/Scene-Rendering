//
//  Shader.cpp
//  Lab3
//
//  Created by CGIS on 05/10/2016.
//  Copyright © 2016 CGIS. All rights reserved.
//

#include "../headers/Shader.hpp"

namespace gps {
    std::string Shader::readShaderFile(std::string fileName) {

        std::ifstream shaderFile;
        std::string shaderString;
        
        //open shader file
        shaderFile.open(fileName);
        
        std::stringstream shaderStringStream;
        
        //read shader content into stream
        shaderStringStream << shaderFile.rdbuf();
        
        //close shader file
        shaderFile.close();
        
        //convert stream into GLchar array
        shaderString = shaderStringStream.str();
        return shaderString;
    }
    
    void Shader::shaderCompileLog(GLuint shaderId) {

        GLint success;
        GLchar infoLog[512];
        
        //check compilation info
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

        if(!success) {

            glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
            std::cout << "Shader compilation error\n" << infoLog << std::endl;
        }
    }
    
    void Shader::shaderLinkLog(GLuint shaderProgramId) {

        GLint success;
        GLchar infoLog[512];
        
        //check linking info
        glGetProgramiv(shaderProgramId, GL_LINK_STATUS, &success);
        if(!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "Shader linking error\n" << infoLog << std::endl;
        }
    }
    
    void Shader::loadShader(std::string vertexShaderFileName, std::string fragmentShaderFileName) {

        //read, parse and compile the vertex shader
        std::string v = readShaderFile(vertexShaderFileName);
        const GLchar* vertexShaderString = v.c_str();
        GLuint vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderString, NULL);
        glCompileShader(vertexShader);
        //check compilation status
        shaderCompileLog(vertexShader);
        
        //read, parse and compile the vertex shader
        std::string f = readShaderFile(fragmentShaderFileName);
        const GLchar* fragmentShaderString = f.c_str();
        GLuint fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderString, NULL);
        glCompileShader(fragmentShader);
        //check compilation status
        shaderCompileLog(fragmentShader);
        
        //attach and link the shader programs
        this->shaderProgram = glCreateProgram();
        glAttachShader(this->shaderProgram, vertexShader);
        glAttachShader(this->shaderProgram, fragmentShader);
        glLinkProgram(this->shaderProgram);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        //check linking info
        shaderLinkLog(this->shaderProgram);
        initUniforms();
    }
    
    void Shader::useShaderProgram() {

        glUseProgram(this->shaderProgram);
    }

    void Shader::initUniforms()
    {
        uniformModelLoc = glGetUniformLocation(shaderProgram, "model");
        uniformViewLoc = glGetUniformLocation(shaderProgram, "view");
        uniformNormalMatrixLoc = glGetUniformLocation(shaderProgram, "normalMatrix");
        uniformProjectionLoc = glGetUniformLocation(shaderProgram, "projection");
        
        uniformEyePosition = glGetUniformLocation(shaderProgram, "eyePosition");
        uniformSpecularIntensity = glGetUniformLocation(shaderProgram, "material.specularIntensity");
        uniformSpecularShininess = glGetUniformLocation(shaderProgram, "material.shininess");

        uniformDirectionalLight.ambientColourLoc = glGetUniformLocation(shaderProgram, "directionalLight.base.colour");
        uniformDirectionalLight.ambientIntensityLoc = glGetUniformLocation(shaderProgram, "directionalLight.base.ambientIntensity");
        uniformDirectionalLight.diffuseIntensityLoc = glGetUniformLocation(shaderProgram, "directionalLight.base.diffuseIntensity");
        uniformDirectionalLight.direction = glGetUniformLocation(shaderProgram, "directionalLight.direction");
        
        uniformPointLightCount = glGetUniformLocation(shaderProgram, "pointLightCount");
        for (int i = 0; i < MAX_NUMBER_OF_POINT_LIGHTS; i++) {
            char locBuff[100] = { '\0' };
            snprintf(locBuff, sizeof(locBuff), "pointLights[%i].base.colour", i);
            uniformPointLights[i].ambientColourLoc = glGetUniformLocation(shaderProgram, locBuff);
            snprintf(locBuff, sizeof(locBuff), "pointLights[%i].base.ambientIntensity", i);
            uniformPointLights[i].ambientIntensityLoc = glGetUniformLocation(shaderProgram, locBuff);
            snprintf(locBuff, sizeof(locBuff), "pointLights[%i].base.diffuseIntensity", i);
            uniformPointLights[i].diffuseIntensityLoc = glGetUniformLocation(shaderProgram, locBuff);

            snprintf(locBuff, sizeof(locBuff), "pointLights[%i].position", i);
            uniformPointLights[i].position = glGetUniformLocation(shaderProgram, locBuff);
            snprintf(locBuff, sizeof(locBuff), "pointLights[%i].dimmingCoeffs", i);
            uniformPointLights[i].dimmingCoefficients = glGetUniformLocation(shaderProgram, locBuff);
        }
        uniformTexture = glGetUniformLocation(shaderProgram, "diffuseTexture");
        uniformDirectionalShadowMap = glGetUniformLocation(shaderProgram, "shadowMap");
        uniformDirectionalLightTransform = glGetUniformBlockIndex(shaderProgram, "directionalLightTransform");
    }

    void Shader::setDirectionalLight(DirectionalLight* light)
    {
        light->useLight(getDirectionalLAmbientIntensityUniform(), getDirectionalLAmbientColourUniform(),
            getDirectionalLDirectionUniform(), getDirectionalLDiffuseIntensityUniform());
    }
    void Shader::setPointLights(PointLight* lights, unsigned int count)
    {
     
        if (count > MAX_NUMBER_OF_POINT_LIGHTS)
            count = MAX_NUMBER_OF_POINT_LIGHTS;
        glUniform1i(getPointLightCountUniform(), count);
        for (unsigned int i = 0; i < count; i++) {
            lights[i].useLight(getPointLAmbientIntensityUniform(i), getPointLAmbientColourUniform(i),
                getPointLLightPositionUniform(i), getPointLDiffuseIntensityUniform(i), getPointLDimmingCoefficientsUniform(i));
        }
    }
}
