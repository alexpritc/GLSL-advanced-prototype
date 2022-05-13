#version 460
out vec4 FragColor;

in vec3 fColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
    //FragColor = vec4(fColor, 1.0);
    FragColor = texture(ourTexture,TexCoord);
    if (FragColor.a < 0.1) discard;
}