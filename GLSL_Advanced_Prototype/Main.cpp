#pragma once
//#include "helper/scene.h"
//#include "helper/scenerunner.h"
//#include "scenebasic_uniform.h"
#include "OpenGLWindow.h"

int main(int argc, char* argv[])
{
	//SceneRunner runner("Alex Pritchard - C1: Initial Prototype 30%");

	//std::unique_ptr<Scene> scene;

	//scene = std::unique_ptr<Scene>(new SceneBasic_Uniform());


	//return runner.run(*scene);


	glfwInit();

	const std::string& windowTitle = "Alex Pritchard - COMP3015 CW2: Advanced Prototype 70%";

#ifdef _WIN32
	//bool showFullscreen = MessageBox(nullptr, L"Would you like to run in fullscreen mode?", L"Fullscreen", MB_ICONQUESTION | MB_YESNO) == IDYES;
#else
	char answer;
	std::cout << "Would you like to run in fullscreen mode? (y/n): ";
	std::cin >> answer;
	bool showFullscreen = tolower(answer) == 'y';
#endif

	OpenGLWindow window;
	if (!window.createOpenGLWindow(windowTitle, false))
	{
		printf("Failed to create window. Shutting down...\n");
		return 1;
	}

	window.runApp();

	window.closeApp();

	return 0;
}