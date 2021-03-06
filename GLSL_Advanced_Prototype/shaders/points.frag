#version 460
out vec4 FragColor;

in vec3 fColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourTexture,TexCoord);
    if (FragColor.a < 0.1) discard;
}