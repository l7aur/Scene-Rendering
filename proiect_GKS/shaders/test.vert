#version 410 core

layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vNormal;
layout(location = 2) in vec2 vTexCoords;

out vec3 fPosition;
out vec3 fNormal;
out vec2 fTexCoords;
out vec4 directionalLightSpacePosition;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 directionalLightTransform;

void main()
{
	gl_Position = projection * view * model * vec4(vPosition, 1.0f);
	directionalLightSpacePosition = directionalLightTransform * model * vec4(vPosition, 1.0f);
	fTexCoords = vTexCoords;
	fNormal = mat3(transpose(inverse(model))) * vNormal;
	fPosition = (model * vec4(vPosition, 1.0f)).xyz;
}