#pragma once

// STD
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>

//GLEW
#include<glew.h>

//GLFW
#include<glfw3.h>

// GLM
#include <glm/glm.hpp>
#include<glm/vec3.hpp>
#include<glm/vec4.hpp>
#include<glm/mat4x4.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

// Project
#include "Vertex.h"


static std::vector<Material> loadMTL(const char* file_name) {

	// Materials array
	std::vector<Material> materials;

	std::stringstream ss;
	std::ifstream in_file(file_name);
	std::string line = "";
	std::string prefix = "";

	glm::vec3 temp_vec3;
	std::string temp_string;
	float temp_float;
	int temp_int;

	Material tempMaterial;

	// File open error check
	if (!in_file.is_open())
	{
		throw "ERROR::OBJLOADER::Could not open file.";
	}

	// Read one line at a time
	while (std::getline(in_file, line))
	{
		//Get the prefix of the line
		ss.clear();
		ss.str(line);
		ss >> prefix;

		if (prefix == "newmtl") // New material
		{
			if (tempMaterial.name != "") {
				materials.push_back(tempMaterial);
			}
			ss >> temp_string;
			tempMaterial.name = temp_string;
		}
		else if (prefix == "Ka") // Ambient
		{
			ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			tempMaterial.ambientColour = temp_vec3;
		}
		else if (prefix == "Kd") // Diffuse
		{
			ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			tempMaterial.diffuseColour = temp_vec3;
		}
		else if (prefix == "Ks") // Specular
		{
			ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			tempMaterial.specularColour = temp_vec3;
		}
		else if (prefix == "Ns") // Specular highlight
		{
			ss >> temp_float;
			tempMaterial.specularHighlights = temp_float;
		}
		else if (prefix == "Ni") // Optical density
		{
			ss >> temp_float;
			tempMaterial.opticalDensity = temp_float;
		}
		else if (prefix == "d") // Dissolve
		{
			ss >> temp_float;
			tempMaterial.dissolve = temp_float;
		}
		else if (prefix == "illum") // Illumination model
		{
			ss >> temp_int;
			tempMaterial.illum = temp_int;
		}
		else if (prefix == "map_Kd") // Texture filepath
		{
			ss >> temp_string;
			tempMaterial.textureFileName = temp_string;
		}
	}

	// Push the last mtl
	if (tempMaterial.name != "") {
		materials.push_back(tempMaterial);
	}

	// DEBUG
	std::cout << "Nr of materials: " << materials.size() << "\n";

	// Loaded success
	std::cout << "MTL file loaded!" << "\n";

	return materials;
}


static Material findMaterialByName(std::string name, std::vector<Material> allMaterials) {

	// Load in all indices
	for (size_t i = 0; i < allMaterials.size(); ++i)
	{
		if (allMaterials[i].name == name) {
			return allMaterials[i];
		}
	}
}

static std::vector<Vertex> loadOBJ(const char* obj_file_name, const char* mtl_file_name)
{
	std::vector<Material> allMaterials = loadMTL(mtl_file_name);

	//Vertex portions
	std::vector<glm::fvec3> vertex_positions;
	std::vector<glm::fvec2> vertex_texcoords;
	std::vector<glm::fvec3> vertex_normals;
	std::vector<Material> vertex_materials;

	//Face vectors
	std::vector<GLint> vertex_position_indicies;
	std::vector<GLint> vertex_texcoord_indicies;
	std::vector<GLint> vertex_normal_indicies;

	//Vertex array
	std::vector<Vertex> vertices;

	std::stringstream ss;
	std::ifstream in_file(obj_file_name);
	std::string line = "";
	std::string prefix = "";
	glm::vec3 temp_vec3;
	glm::vec2 temp_vec2;
	GLint temp_glint = 0;

	std::string temp_material_name;

	// File open error check
	if (!in_file.is_open())
	{
		throw "ERROR::OBJLOADER::Could not open file.";
	}

	// Read one line at a time
	while (std::getline(in_file, line))
	{
		//Get the prefix of the line
		ss.clear();
		ss.str(line);
		ss >> prefix;

		if (prefix == "v") // Vertex
		{
			ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			vertex_positions.push_back(temp_vec3);
		}
		else if (prefix == "vt") // Texture coord
		{
			ss >> temp_vec2.x >> temp_vec2.y;
			vertex_texcoords.push_back(temp_vec2);
		}
		else if (prefix == "vn") // Normal
		{
			ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			vertex_normals.push_back(temp_vec3);
		}
		else if (prefix == "usemtl") { // The following faces will use this material (read from MTL file) 

			ss >> temp_material_name;
			//vertex_materials.push_back(findMaterialByName(temp_material_name, allMaterials));
		}
		else if (prefix == "f") // Faces
		{
			int counter = 0;

			while (ss >> temp_glint)
			{
				// Pushing indices into correct arrays
				if (counter == 0) {
					vertex_position_indicies.push_back(temp_glint);
					vertex_materials.push_back(findMaterialByName(temp_material_name, allMaterials));
				}
				else if (counter == 1) {
					vertex_texcoord_indicies.push_back(temp_glint);

				}
				else if (counter == 2) {
					vertex_normal_indicies.push_back(temp_glint);
				}

				// Handling characters
				if (ss.peek() == '/')
				{
					++counter;
					ss.ignore(1, '/');
				}
				else if (ss.peek() == ' ')
				{
					++counter;
					ss.ignore(1, ' ');
				}

				// Reset the counter
				if (counter > 2)
					counter = 0;
			}
		}
	}

	// Build final vertex array (mesh)
	vertices.resize(vertex_position_indicies.size(), Vertex());

	// Load in all indices
	for (size_t i = 0; i < vertices.size(); ++i)
	{
		vertices[i].position = vertex_positions[vertex_position_indicies[i] - 1];
		vertices[i].texcoord = vertex_texcoords[vertex_texcoord_indicies[i] - 1];
		vertices[i].normal = vertex_normals[vertex_normal_indicies[i] - 1];
		vertices[i].material = vertex_materials[i];
	}

	// DEBUG
	std::cout << "Nr of vertices: " << vertices.size() << "\n";

	// Loaded success
	std::cout << "OBJ file loaded!" << "\n";
	return vertices;
}