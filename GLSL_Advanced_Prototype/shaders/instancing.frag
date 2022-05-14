#version 460

in vec3 normal;
in vec3 fragPos;
in vec2 UV;

in vec3 Ka;
in vec3 Kd;
in vec3 Ks;

in float alpha;

in vec4 eyeSpacePos;

layout (location = 0) out vec4 fragColor;

uniform vec3 lightPos; 
uniform vec3 lightColor;
uniform float lightIntensity;

uniform vec3 viewPos;

uniform sampler2D ourTexture;

uniform int width;
uniform int height;
uniform float radius;
uniform sampler2D noiseTexture;
uniform sampler2D renderTexture;

subroutine vec4 RenderPassType();
subroutine uniform RenderPassType RenderPass;

//////// FOG /////////
struct FogParameters
{
	vec3 color;
	float linearStart;
	float linearEnd;
	float density;
	
	int equation;
	bool isEnabled;
};

float getFogFactor(FogParameters params, float fogCoordinate);

float getFogFactor(FogParameters params, float fogCoordinate)
{
	float result = 0.0;
	if(params.equation == 0)
	{
		float fogLength = params.linearEnd - params.linearStart;
		result = (params.linearEnd - fogCoordinate) / fogLength;
	}
	else if(params.equation == 1) {
		result = exp(-params.density * fogCoordinate);
	}
	else if(params.equation == 2) {
		result = exp(-pow(params.density * fogCoordinate, 2.0));
	}
	
	result = 1.0 - clamp(result, 0.0, 1.0);
	return result;
}

//////// RENDER PASSES /////////
float luminance(vec3 color){
	return dot(color.rgb, vec3(0.2126,0.7152,0.0722));
}

subroutine(RenderPassType)
vec4 firstPass()
{
	// Ambient
    vec3 ambient = Ka * lightIntensity * lightColor;
  	
    // Diffuse 
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(lightPos - fragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 textDiff = texture( renderTexture, UV ).rgb;
    vec3 diffuse = Kd * diff * lightColor * textDiff;
    
    // Specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = Ks * specularStrength * spec * lightColor;  
        
    vec3 result = (ambient + diffuse + specular);

	// Apply fog calculation only if fog is enabled
	FogParameters fogParams = FogParameters(vec3(0.9,0.9,0.9),0.3,0.75,0.1,1,false);

	if (fogParams.isEnabled){
      float fogCoordinate = abs(eyeSpacePos.z / eyeSpacePos.w);
      vec4 outputCol = mix(vec4(result, 1.0), vec4(fogParams.color, 0.1), getFogFactor(fogParams, fogCoordinate));
     
	 return vec4(outputCol.xyz, alpha);
	}
	else{
	  return vec4(result, 0.1);
	  }
}

subroutine(RenderPassType)
vec4 secondPass()
{
		vec4 noise = texture(noiseTexture, UV);
		vec4 color = texture(ourTexture, UV);
		float green = luminance(color.rgb);

		float dist1 = length(gl_FragCoord.xy - vec2(width/4.0, height/2.0));
		float dist2 = length(gl_FragCoord.xy - vec2(3.0* width/4.0, height/2.0));

		if (dist1 > radius && dist2 > radius) green = 0.0;

		return vec4(0.0, green * clamp(noise.a,0.0,1.0),0.0,0.5);
}

//////// MAIN ///////// 
void main() 
{
	fragColor = RenderPass(); // This will either call firstPass() or secondPass()
}

