#version 460

layout(points) in;
layout(triangle_strip, max_vertices = 3) out;

uniform int numTrees;

in VS_OUT {
    vec3 fragPos;
    vec3 normal;
    vec2 UV;
    vec3 Ka;
    vec3 Kd;
    vec3 Ks;
    float alpha;
    vec4 eyeSpacePos;

} gs_in[];

out vec3 fragPos;
out vec3 normal;
out vec2 UV;

out vec3 Ka;
out vec3 Kd;
out vec3 Ks;

out float alpha;

smooth out vec4 eyeSpacePos;

void buildTrees(vec4 position, int offset)
{
	for (int i = 0; i < numTrees; i++)
    {
        gl_Position = position + vec4(offset * i, 0.0, 0.0, 0.0);
        fragPos = gs_in[0].fragPos;
        normal = gs_in[0].normal;
        UV = gs_in[0].UV;
        Ka = gs_in[0].Ka;
        Kd = gs_in[0].Kd;
        Ks = gs_in[0].Ks;
        alpha = gs_in[0].alpha;
        eyeSpacePos = gs_in[0].eyeSpacePos;
        EmitVertex(); 
    }
  
    EndPrimitive();
}

void main()
{

   buildTrees(gl_in[0].gl_Position, 10);

}
