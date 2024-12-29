#pragma once

#include <stdio.h>

#include "GL/glew.h"

class ShadowMap {
public:
	ShadowMap();
	~ShadowMap();
	virtual bool init(GLuint width, GLuint height);
	virtual void write();
	virtual void read(GLenum textureUnit);
	GLuint getShadowWidth() { return this->shadowWidth; };
	GLuint getShadowHeight() { return this->shadowHeight; };
protected:
	GLuint FBO;
	GLuint shadowMap;
	GLuint shadowWidth;
	GLuint shadowHeight;
};