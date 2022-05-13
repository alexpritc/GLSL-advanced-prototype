#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "stb_image.h"
#include "noisetex.h"

class Noise
{
public:

    Noise();
    Noise(int w, int h) {
        width = w;
        height - h;
        noiseTex = NoiseTex::generatePeriodic2DTex(200.0f, 0.5f, 1024, 1024);
    }
    void GenerateNoise();

    void update();

    void render();

    void loadTextureFromFile(const char* filePath);

    void firstPass();

    void secondPass();

    void setupFBO();

private:

    GLuint fsQuad, firstPassIndex, secondPassIndex;
    GLuint noiseTex;
    GLuint renderTex;
    GLuint renderbuffer;

    unsigned int handle[2];

    // Array for full-screen quad
    GLfloat verts[18] = {
        -1.0f,-1.0f,0.0f,   // bottom left
        1.0f,-1.0f,0.0f,    // bottom right
        1.0f,1.0f,0.0f,     // top right
        -1.0f,-1.0f,0.0f,   // bottom left
        1.0f,1.0f,0.0f,     // top right
        -1.0f,1.0f,0.0f     // top left
    };

    GLfloat tc[12] = {
        0.0f, 0.0f,1.0f,0.0f,1.0f,1.0f,
        0.0f,0.0f,1.0f,1.0f,0.0f,1.0f
    };

    int width, height;
    float angle;

    GLuint getProgramID() {

        GLuint i = 0;
        glGetIntegerv(GL_CURRENT_PROGRAM, (GLint*)(&i));
        return i;
    }
};

