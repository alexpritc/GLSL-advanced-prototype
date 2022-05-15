#version 460

layout (location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 vertexUV;
layout(location = 2) in vec3 vertexNormal;

layout (location = 3) in vec3 ambientColor;
layout (location = 4) in vec3 diffuseColor;
layout (location = 5) in vec3 specularColor;

layout (location = 5) in float dissolve;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform float time; // Animation time

uniform vec3 offsets[100];

// Wave parameters
uniform float frequency = 1.5f;
uniform float velocity = 2.5f;
uniform float amplitude = 1.25f;

uniform float y;

out vec3 color;
out vec3 fragPos;
out vec3 normal;
out vec2 UV;

out vec3 Ka;
out vec3 Kd;
out vec3 Ks;

smooth out vec4 eyeSpacePos;

void main()
{

    vec3 offset = offsets[gl_InstanceID];
    fragPos = vec3(model * vec4(vertexPosition + offset, 1.0));

    // Translate vertices on y axis
    float u = frequency * fragPos.x - velocity * time;
    float i = frequency * fragPos.z - velocity * time;
   
   fragPos.y = fragPos.y - y + amplitude * sin(u) * sin(i);

    gl_Position = projection * view * vec4(fragPos, 1.0);

    // Compute normal vector
     vec3 n = vec3(0.0);
    n.xy = normalize(vec2(cos(u) + vec2(cos(i), 1.0)));

    normal = vertexNormal; //* n;
    UV = vertexUV;

    Ka = ambientColor;
  	Kd = diffuseColor;
    Ks = specularColor;

    mat4 mvMatrix = view * model;
    eyeSpacePos = mvMatrix * vec4(vertexPosition, 1.0);
}
