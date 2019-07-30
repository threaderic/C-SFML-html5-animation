#pragma once

#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
#elif __linux__
    #include <SFML/Graphics.hpp>
#endif

#include <string>

#include "math.h"

class Light
{
public:
	Light(float px = -100, float py = -100, float pz = -100, float b = 1);
	~Light();
	float x;
	float y;
	float z;
    float brightness = 1;
	void SetBrightness(float b);
};
