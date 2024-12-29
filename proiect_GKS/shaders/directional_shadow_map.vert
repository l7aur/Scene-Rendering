#version 410 core

layout(location = 0) in vec3 vPosition;

uniform mat4 model;
uniform mat4 directionalLightTransform;

void main() {
	gl_Position = directionalLightTransform * model * vec4(vPosition, 1.0f);
}