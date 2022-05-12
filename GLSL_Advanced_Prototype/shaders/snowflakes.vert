#version 460

layout (location = 0) in vec3 vertexPosition;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 fragPos;

void main()
{
    fragPos = vec3(model * vec4(vertexPosition, 1.0));
    gl_Position = projection * view * vec4(fragPos, 1.0);
}
