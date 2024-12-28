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
        GLuint getAmbientIntensityUniform() const { return this->uniformAmbientIntensityLoc; };
        GLuint getAmbientColourUniform() const { return this->uniformAmbientColourLoc; };
        GLuint getDiffuseIntensityUniform() const { return this->uniformDiffuseIntensityLoc; };
        GLuint getDirectionUniform() const { return this->direction; };
        GLuint getEyePositionUniform() const { return this->uniformEyePosition; };
        GLuint getSpecularIntensityUniform() const { return this->uniformSpecularIntensity; };
        GLuint getSpecularShininessUniform() const { return this->uniformSpecularShininess; };

        void setModelLocUniform(GLuint loc) { this->uniformModelLoc = loc; };
        void setViewLocUniform(GLuint loc) { this->uniformViewLoc = loc; };
        void setProjectionLocUniform(GLuint loc) { this->uniformProjectionLoc = loc; };
        void setNormalMatrixLocUniform(GLuint loc) { this->uniformNormalMatrixLoc = loc; };
        void setAmbientIntensityUniform(GLuint loc) { this->uniformAmbientIntensityLoc = loc; };
        void setAmbientColourUniform(GLuint loc) { this->uniformAmbientColourLoc = loc; };
        void setDiffuseIntensityUniform(GLuint loc) { this->uniformDiffuseIntensityLoc = loc; };
        void setDirectionUniform(GLuint loc) { this->direction = loc; };
        void setEyePositionUniform(GLuint loc) { this->uniformEyePosition = loc; };
        void setSpecularIntensityUniform(GLuint loc) { this->uniformSpecularIntensity = loc; };
        void setSpecularShininessUniform(GLuint loc) { this->uniformSpecularShininess = loc; };

    private:
        GLuint uniformModelLoc{};
        GLuint uniformViewLoc{};
        GLuint uniformProjectionLoc{};
        GLuint uniformNormalMatrixLoc{};
        GLuint uniformAmbientIntensityLoc{};
        GLuint uniformAmbientColourLoc{};
        GLuint uniformDiffuseIntensityLoc{};
        GLuint direction{};
        GLuint uniformEyePosition{};
        GLuint uniformSpecularIntensity{};
        GLuint uniformSpecularShininess{};

        void initUniforms();
        std::string readShaderFile(std::string fileName);
        void shaderCompileLog(GLuint shaderId);
        void shaderLinkLog(GLuint shaderProgramId);
    };
}

#endif /* Shader_hpp */
