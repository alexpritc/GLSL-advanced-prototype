# COMP3015 CW2: Advanced Prototype 70%

<!-- CONTACT -->
## Contact

Alex Pritchard - [@alexpritc](https://twitter.com/alexpritc) - hi@apritc.com

Project Link: [https://github.com/alexpritc/GLSL-advanced-prototype](https://github.com/alexpritc/GLSL-advanced-prototype)

![image](https://user-images.githubusercontent.com/23083779/168473931-825969f7-4c9d-4925-80a0-a92c3a44b041.png)

## How does it work?
This project uses OpenGL 4.x and C++. It works by loading and rendering .obj files with their respective .mtl information for material and texture binding. It utilizes three advanced OpenGL techniques:
* Geometry shaders (point sprites)
* Vertex animation
* Instancing

## How does your code fit together and how should a programmer navigate it?
All of the GLFW Window management is handled in it's own class, [OpenGLWindow.cpp](). Each window instance has it's own instances of [Model.cpp]() that loads the vertices, normals, indicies, material and texture information from an .obj file (path is specified). It binds this information to the shader program which is an instance of [Shader.cpp]() which reads from and writes to fragment and vertex shaders. 

There are three different shader programs used in this project: instancing (which instantiates *x* number of .obj models into the scene using `gl_InstanceID`), vertexanim (which changes the positions of the vertices on each draw call to simulate animation/movement), and points (which passes a set of points to a geometry shader to create a quad at that position and apply a texture).

Additionally, each shader program's vertex shader handles the Model View Projection matrix and its fragmnet shader handles the colour of vertices, texturing and phong lighting. The colouring of vertices specifically isn't handled in the vertex shader to avoid fragment interpolation. This achieves a cartoony asethetic.

## What makes your shader program special and how does it compare to similar things?
This project was started from scratch, with the idea being to create a clone of Minecraft asethetics. There is little unqiue about these shaders, truth be told. There are some performance issues but instancing the trees does reduce the load. There are improvements that could be made, with more knowledge on the subject, to improve the quality of the product.

With further development, it could be used to:
* Create a minecraft clone.
* Development of other games.
* Improved performance of applications.

![image](https://user-images.githubusercontent.com/23083779/168473953-a784bef2-2956-43d1-b845-d7a77b4aca34.png)

## Which version Visual Studio and Operating System you used to test/write the code locally?
* Visual Studio 2019
* Windows 10

<!-- INSTALLATION -->
## Installation

_Follow the instructions below to setup the app. This project doesn't rely on any external dependencies or services._

1. Clone the repo
   ```sh
   git clone https://github.com/alexpritc/GLSL-prototype
   ```
2. Extract the latest build at [GLSL-advanced-prototype.zip](https://github.com/alexpritc/GLSL-advanced-prototype/blob/main/GLSL_Advanced_Prototype.zip)

3. Run `GLSL_Advanced_Prototype.exe`
   ```sh
   https://github.com/alexpritc/GLSL-advanced-prototype/GLSL_Prototype.exe
   ```
	
<!-- REQUIREMENTS -->
#### Requirements
* Windows 10+
* x64 bit OS
* A keyboard
* A mouse

<!-- How to use -->
## Controls
Here is the list of the keys that can be used to interact with the program
<table>
<tr><th colspan="2">Camera</th></tr>
	<tr><td><b>W</b></td><td>Move forward</td></tr>
	<tr><td><b>S</b></td><td>Move backward</td></tr>
	<tr><td><b>A</b></td><td>Move left</td></tr>
	<tr><td><b>D</b></td><td>Move right</td></tr>
	<tr><td><b>Mouse</b></td><td>Look around</td></tr>
	<tr><td><b>R</b></td><td>Zoom</td></tr>
<tr><th colspan="2">Other</th></tr>
	<tr><td><b>ESC</b></td><td>Close the program</td></tr>
</table>

## Video
_Click to play developer walkthrough:_

[https://www.youtube.com/watch?v=mGD4mQEvDUc](https://www.youtube.com/watch?v=mGD4mQEvDUc)

<!-- LIBRARIES -->
## List of libraries used
* GL - OpenGL
* GLFW - OpenGL framework used for cross-platform window creation and input handling
* GLM - Mathematics library (vectors, matrices, quaternions etc.)

<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

Resources I found helpful and would like to give credit to:

* [Learn OpenGL Tutorials](https://github.com/JoeyDeVries/LearnOpenGL)

![image](https://user-images.githubusercontent.com/23083779/168474017-2e7a4863-2131-4ba7-885e-3ac239bc4235.png)
