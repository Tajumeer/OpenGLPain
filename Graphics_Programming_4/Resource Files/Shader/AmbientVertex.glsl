#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 uvcoord;
layout (location = 3) in vec3 normal;

out vec3 FragPos;
out vec3 Normal;
out vec2 uv;
out vec3 ViewDir;

uniform mat4 camMatrix;
uniform mat4 transform;
uniform vec3 lightPosition;

void main()
{
    gl_Position = camMatrix * transform * vec4(position, 1.0);
    FragPos = vec3(transform * vec4(position, 1.0));
    Normal = mat3(transpose(inverse(transform))) * normal;
    uv = uvcoord;
}
