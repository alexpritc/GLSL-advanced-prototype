#ifndef NOISETEX_H
#define NOISETEX_H

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <glm/glm.hpp> //includes GLM
#include "glm/ext/vector_float3.hpp"
#include "glm/fwd.hpp"
#include <glm/ext/matrix_transform.hpp> // GLM: translate, rotate
#include <glm/ext/matrix_clip_space.hpp> // GLM: perspective and ortho 
#include <glm/gtc/type_ptr.hpp> // GLM: access to the value_ptr
#include <glm/glm.hpp>
#include <glm/gtc/noise.hpp>

namespace NoiseTex
{
  int storeTex( GLubyte * data, int w, int h );

  int generate2DTex(float baseFreq = 4.0f, float persistence = 0.5f, int w = 128, int h = 128, bool periodic = false);

  int generatePeriodic2DTex(float baseFreq = 4.0f, float persist = 0.5f, int w = 128, int h = 128);
};

#endif // NOISETEX_H
