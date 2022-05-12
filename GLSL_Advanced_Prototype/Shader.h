#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

// GL
#include "glew.h"

// GLFW
#include "GLFW/glfw3.h"

// GLM
#include <glm/glm.hpp> //includes GLM
#include "glm/ext/vector_float3.hpp"
#include "glm/fwd.hpp"
#include <glm/ext/matrix_transform.hpp> // GLM: translate, rotate
#include <glm/ext/matrix_clip_space.hpp> // GLM: perspective and ortho 
#include <glm/gtc/type_ptr.hpp> // GLM: access to the value_ptr

#include "stb_image.h"
#include "Camera.h"

class Shader
{
public:
    // Shader Program ID
    unsigned int ID;

    // Constructor generates the shader on the fly
    // ------------------------------------------------------------------------
    Shader();

    Shader(const char* vertexPath, const char* fragmentPath);

    Shader(const char* vertexPath, const char* fragmentPath, const char* geoPath);

    // Activate the shader
    // ------------------------------------------------------------------------
    void use();

    void deleteShader();

    // Update the shader
    // ------------------------------------------------------------------------
    void updateModelViewProjection(glm::mat4 model, glm::mat4 view, glm::mat4 projection);

    void drawElements(GLuint texture, int NumVertices, GLuint  VAOs[]);

    void loadTexture(GLuint& texture, std::string texturepath);

    // Utility uniform functions
    // ------------------------------------------------------------------------
    void setBool(const std::string& name, bool value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }

    void setInt(const std::string& name, int value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }

    void setFloat(const std::string& name, float value) const
    {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }

    void setMatrix(const std::string& name, glm::mat4  value) const
    {
        // Adding the Uniform to the shader
        int loc = glGetUniformLocation(ID, name.c_str());
        glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
    }

    void setVec3(const std::string& name, float x, float y, float z) const
    {
        glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
    }

    void setVec3(const std::string& name, glm::vec3 vector) const
    {
        glUniform3f(glGetUniformLocation(ID, name.c_str()), vector.x, vector.y, vector.z);
    }


private:
    // Utility function for checking shader compilation/linking errors.
    // ------------------------------------------------------------------------
    void checkCompileErrors(unsigned int shader, std::string type);
};
#endif
