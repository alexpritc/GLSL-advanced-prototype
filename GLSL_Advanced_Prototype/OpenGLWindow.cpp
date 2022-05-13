#include "OpenGLWindow.h"

// Settings
bool firstMouse = true;
float yaw = -90.0f;
float pitch = 0.0f;
float lastX = 800.0f / 2.0;
float lastY = 600.0 / 2.0;
float fov = 60.0f;

// Shaders
Shader _basicShader;
Shader _noiseShader;

// Lighting
glm::vec3 lightPos(10.0f, 10.0f, 10.0f);
glm::vec3 lightColor(0.9f, 0.9f, 0.9f);
float lightIntensity = 0.25f;

const glm::vec3 sceneScale(1.0f, 1.75f, 1.0f);

// Camera
glm::vec3 cameraPos(50.0f, 0.0f, 50.0f);
const glm::vec3 cameraUp(0.0f, 1.0f, 0.0f);

// Models
Model treeModel;
Points snowflakes;
Noise noise;

bool nightVision;

// Callbacks
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

OpenGLWindow::OpenGLWindow()
{
}

bool OpenGLWindow::createOpenGLWindow(const std::string& windowTitle, bool showFullscreen)
{
	glfwInit();

	const auto primaryMonitor = glfwGetPrimaryMonitor();
	const auto videoMode = glfwGetVideoMode(primaryMonitor);

	_window = glfwCreateWindow(videoMode->width, videoMode->height, windowTitle.c_str(), showFullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
	if (_window == nullptr)
	{
		return false;
	}

	glfwGetWindowSize(_window, &_screenWidth, &_screenHeight);

	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);
	glfwSetCursorPosCallback(_window, cursor_position_callback);

	// Tell GLFW to capture the mouse
	glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwMakeContextCurrent(_window);
	glewInit();

	// Camera and shaders
	_sceneCamera = Camera(cameraPos, cameraUp);
	
	_basicShader = Shader("shaders/basic.vert", "shaders/basic.frag");
	//_noiseShader = Shader("shaders/noise.vert", "shaders/noise.frag");

	//_snowflakeShader = Shader("shaders/snowflakes.vert", "shaders/snowflakes.frag", "shaders/snowflakes.geom");

	_basicShader.use();

	// Models
	treeModel.loadFromFile("media/Trees.obj", "media/Trees.mtl");
	treeModel.loadTextureFromFile("media/noise_texture.jpg");

	noise = Noise(_screenWidth, _screenHeight);
	noise.GenerateNoise();

	// Tree positions
	int index = 0;
	for (int x = 0; x < 10; x++)
	{
		for (int z = 0; z < 10; z++)
		{
			float offset = 30.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (50.0f - 30.0f)));
			glm::vec3 translation;
			translation.x = (float)x * offset;
			translation.y = 0.0f;
			offset = 50.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (60.0f - 50.0f)));
			translation.z = (float)z * offset;
			translations[index++] = translation;
		}
	}

	if (!showFullscreen)
	{
		glfwMaximizeWindow(_window);
		glfwGetWindowSize(_window, &_screenWidth, &_screenHeight);
	}

	return true;
}

void OpenGLWindow::runApp()
{
	glfwGetWindowSize(_window, &_screenWidth, &_screenHeight);

	lastX = _screenWidth / 2;
	lastY = _screenHeight / 2;

	// Render loop
	while (!glfwWindowShouldClose(_window))
	{
		// Input
		processInput(_window);

		// Render heightmap
		renderScene();
	}
}

void OpenGLWindow::renderScene() {

	// Rendering commands here
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glDepthRange(0.0f, 1.0f);
	glClearDepth(1.0f);
	glClearColor(0.9, 0.9, 0.9, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Get delta time
	float _currentFrame = static_cast<float>(glfwGetTime());
	_deltaTime = _currentFrame - _lastFrame;
	_lastFrame = _currentFrame;

	// Get window info
	glfwGetWindowSize(_window, &_screenWidth, &_screenHeight);

	// Update camera based on input
	_sceneCamera.setYaw(yaw);
	_sceneCamera.setPitch(pitch);
	_sceneCamera.setFOV(fov);
	_sceneCamera.processInput(_window, _deltaTime);

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::scale(model, sceneScale);

	// Process shader(s)
	_basicShader.use();
	_basicShader.updateModelViewProjection(model, _sceneCamera.getViewMatrix(), _sceneCamera.getProjectionMatrix());

	// Lighting
	_basicShader.setVec3("lightColor", lightColor);
	_basicShader.setFloat("lightIntensity", lightIntensity);
	_basicShader.setVec3("lightPos", lightPos);
	_basicShader.setVec3("viewPos", _sceneCamera.getPosition());

	_basicShader.setInt("width", _screenWidth);
	_basicShader.setInt("height", _screenHeight);
	_basicShader.setFloat("radius", _screenWidth / 3.5f); // used to be 3.5f

	for (unsigned int i = 0; i < 100; i++)
	{
		_basicShader.setVec3("offsets[" + std::to_string(i) + "]", translations[i]);
	}

	if (nightVision) {
		noise.render();
	}

	treeModel.draw();

	// Check and call events and swap the buffers
	glfwPollEvents();
	glfwSwapBuffers(_window);
}

void OpenGLWindow::closeApp() {
	_basicShader.deleteShader();
	_snowflakeShader.deleteShader();

	glfwDestroyWindow(_window);

	glfwTerminate();
}

// Callback functions
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	// Close application
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}

	// Zoom in
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_RELEASE) {
		fov = 60.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
		fov = 10.0f;
	}

	// Fog toggle
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_RELEASE) {
		nightVision = false;
	}
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
		nightVision = true;
	}
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}
	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f) {
		pitch = 89.0f;
	}
	if (pitch < -89.0f) {
		pitch = -89.0f;
	}
}
