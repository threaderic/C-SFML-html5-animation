#pragma once

#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
#elif __linux__
    #include <SFML/Graphics.hpp>
#endif

class Ship
{
public:
	Ship(float x, float y);
	~Ship();
	void Draw(sf::RenderWindow * render);

	sf::ConvexShape shape;
	bool showFlame;
	//Overrides current position
	void SetPosition(float x, float y);
	void SetX(float x);
	void SetY(float y);
	float GetX();
	float GetY();
	//Increase current position by x and y values
	void Translate(float x, float y);

	//Overrides current rotation (in degrees)
	float GetRotation();
	//Overrides current rotation (in degrees)
	void SetRotation(float angle);
	//Increase current rotation (in degrees)
	void Rotate(float angle);

private:
	sf::ConvexShape flame;
};

