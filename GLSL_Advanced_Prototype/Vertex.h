#pragma once

#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include <map>
#include <random>

struct Material
{
	std::string name;
	glm::vec3 ambientColour;
	glm::vec3 diffuseColour;
	glm::vec3 specularColour;
	float specularHighlights;
	float opticalDensity;
	float dissolve;
	int illum;
	std::string textureFileName;
};

struct Vertex
{
	glm::vec3 position;
	glm::vec3 colour;
	glm::vec2 texcoord;
	glm::vec3 normal;
	Material material;
};