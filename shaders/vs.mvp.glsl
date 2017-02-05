#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;

out vec2 passTextureCoord;

uniform mat4 transformMatrix;
uniform mat4 viewMatrix;

void main()
{
    gl_Position = viewMatrix * transformMatrix * vec4(position, 1.0f);
    passTextureCoord = texCoord;
} 