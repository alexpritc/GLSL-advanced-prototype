#pragma once

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

extern GLFWwindow* window;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "stb_image.h"
#include <iostream>
#include <vector>
#include <map>
#include <random>


class Points
{
    public:

    Points();

    void loadTextureFromFile(const char* filePath);

    void init();

    void draw();

    float GetRandomNumber();

    private:
    GLuint texturebuffer;
    GLuint pointbuffer;

    unsigned int VBO, VAO;
    //GLuint _sprites;
    //int _numSprites = 50;
    //float* vertices = new float[_numSprites * 3];

    int numPoints = 100;

    //std::vector<glm::vec3> points;
    //glm::vec3 points[100];

    GLuint getProgramID() {
        GLuint i = 0;
        glGetIntegerv(GL_CURRENT_PROGRAM, (GLint*)(&i));
        return i;
    }
};

