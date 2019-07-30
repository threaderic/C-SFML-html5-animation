#pragma once

#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
#elif __linux__
    #include <SFML/Graphics.hpp>
#endif

#include <string>

#include "Point3d.h"
#include "math.h"

class Triangle
{
public:
	Triangle(Point3d &a, Point3d &b, Point3d &c, sf::Color color = sf::Color::Red);
	~Triangle();
	Point3d *pointA;
    Point3d *pointB;
    Point3d *pointC;
    sf::Color fillColor;
    sf::Color lineColor;
    float lineWidth = 1;
    float alpha = 1.0f;

	void Draw(sf::RenderWindow &window);
	bool IsBackface();
    float GetDepth()const;
};
