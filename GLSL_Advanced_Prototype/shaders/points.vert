#version 460

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform sampler2D ourTexture;

out VS_OUT {
    vec3 color;
} vs_out;


void main()
{
    vec3 fragPos = vec3(model * vec4(aPos, 1.0));
    gl_Position = projection * view * vec4(fragPos, 1.0);

    vs_out.color = aColor;
}
