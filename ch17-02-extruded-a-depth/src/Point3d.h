#pragma once

#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
#elif __linux__
    #include <SFML/Graphics.hpp>
#endif

#include <string>

#include "math.h"

class Point3d
{
public:
	Point3d(float x, float y, float z);
	~Point3d();
	float x;
	float y;
	float z;
    float cX;
    float cY;
	float cZ;
	float vpX;
	float vpY;
	float fl;

	void SetCenter(float x, float y, float z);
	void SetVanishingPoint(float x, float y);
	void RotateX(float angle);
	void RotateY(float angle);
	void RotateZ(float angle);
    float GetScreenX();
	float GetScreenY();
};
