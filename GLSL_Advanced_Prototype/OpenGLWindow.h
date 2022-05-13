#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <glm/glm.hpp> //includes GLM
#include "glm/ext/vector_float3.hpp"
#include "glm/fwd.hpp"
#include <glm/ext/matrix_transform.hpp> // GLM: translate, rotate
#include <glm/ext/matrix_clip_space.hpp> // GLM: perspective and ortho 
#include <glm/gtc/type_ptr.hpp> // GLM: access to the value_ptr

#include <iostream>
#include <vector>
#include <map>
#include <random>

#include "Camera.h"
#include "Shader.h"
#include "ObjectLoader.h"
#include "Model.h"
#include "Points.h"
#include "noisetex.h"
#include "Noise.h"

/**
 * Provides easy and convenient way to handle OpenGL Window creation and basic scene management (init, render and release).
 */
class OpenGLWindow
{
public:
    /**
     * Constructor of the class, initializes internal structures.
     */
    OpenGLWindow();

    bool createOpenGLWindow(const std::string& windowTitle, bool showFullscreen);

    /**
     * Runs the whole application. Contains the main application loop.
     */
    void runApp();

    /**
    * Terminates the application.
    */
    void closeApp();

    void renderScene();

    void draw();

private:
    GLFWwindow* _window = nullptr; // Pointer to GLFWwindow, nullptr by default

    float _deltaTime = 0.0f; // Time delta between last frame and current frame
    float _lastFrame = 0.0f;

    int _screenWidth = 0;
    int _screenHeight = 0;

    Shader _snowflakeShader;

    Camera _sceneCamera;

    GLuint _sprites;
    int _numSprites;

    glm::vec3 translations[100];
};
