#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 uv;
layout (location = 3) in vec3 normal;
out vec3 vertexColor;

//uniform mat4 camMatrix;

void main()
{
    gl_Position = //camMatrix * 
                  vec4(position, 1.0);
    vertexColor = color;
}