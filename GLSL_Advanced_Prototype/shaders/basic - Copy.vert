#version 460

layout (location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 vertexUV;
layout(location = 2) in vec3 vertexNormal;

layout (location = 3) in vec3 ambientColor;
layout (location = 4) in vec3 diffuseColor;
layout (location = 5) in vec3 specularColor;

layout (location = 5) in float dissolve;

uniform vec3 offsets[100];

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 color;
out vec3 fragPos;
out vec3 normal;
out vec2 UV;

out vec3 Ka;
out vec3 Kd;
out vec3 Ks;

out float alpha;

smooth out vec4 eyeSpacePos;

void main()
{
    vec3 offset = offsets[gl_InstanceID];
    fragPos = vec3(model * vec4(vertexPosition + offset, 1.0));
    gl_Position = projection * view * vec4(fragPos, 1.0);

    normal = vertexNormal;
    UV = vertexUV;

    Ka = ambientColor;
  	Kd = diffuseColor;
    Ks = specularColor;

    alpha = dissolve;

    mat4 mvMatrix = view * model;
    eyeSpacePos = mvMatrix * vec4(vertexPosition + offset, 1.0);
}
