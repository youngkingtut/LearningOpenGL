#version 330 core

uniform vec4 myPosition;

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor;
out vec2 TexCoord;

void main(){
    gl_Position = vec4(aPos + myPosition.xyz, 1.0f);
    ourColor = aColor;
    TexCoord = aTexCoord;
}
