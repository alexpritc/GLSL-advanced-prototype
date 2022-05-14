#version 460

layout(points) in;
layout(triangle_strip, max_vertices = 5) out;

out vec2 TexCoord;

in VS_OUT {
    vec3 color;
} gs_in[]; 

out vec3 fColor;  

void buildFlower(vec4 position){
	
	fColor = gs_in[0].color; // gs_in[0] since there's only one input vertex
	gl_Position = position + vec4(-1, -1.5, 0.0, 0.0) ;  // 1:bottom-left   
	TexCoord = vec2(0.0,0.0);
	EmitVertex(); 
	
	gl_Position = position + vec4( 1, -1.5, 0.0, 0.0);    // 2:bottom-right
	TexCoord = vec2(1.0,0.0);
	EmitVertex();

	gl_Position = position + vec4(-1, 1.5, 0.0, 0.0);    // 3:top-left
	TexCoord = vec2(0.0,1.0);
	EmitVertex();

	gl_Position = position + vec4( 1, 1.5, 0.0, 0.0);    // 4:top-right
	TexCoord = vec2(1.0,1.0);
	EmitVertex();

	EndPrimitive();  
}


void main()
{
	buildFlower(gl_in[0].gl_Position);
}
