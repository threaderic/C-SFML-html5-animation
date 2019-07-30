#pragma once

#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
#elif __linux__
    #include <SFML/Graphics.hpp>
#endif

#include <string>
#include <cmath>

#include "Utils.h"

class Segment
{
public:
	Segment(float width, float height, sf::Color color = sf::Color::White);
	~Segment();

	sf::ConvexShape shape;
    sf::CircleShape leftPin;
    sf::CircleShape rightPin;
    std::string id;
    float width = 0;
    float height = 0;
	float vx;
	float vy;
	///Overrides current position
	void SetPosition(sf::Vector2f pos);
	void SetPosition(float x, float y);
	void SetX(float x);
	void SetY(float y);
	float GetX();
	float GetY();
	///Increase current position by x and y values
	void Translate(float x, float y);
	///Overrides current rotation (in degrees)
	void SetRotation(float angle);
	///Increase current rotation by an anglee (in degrees)
	void Rotate(float angle);
    void Draw(sf::RenderWindow &renderWindow);
    void UpdatePinsPosition();
    sf::Vector2f GetPin();
	sf::FloatRect GetBounds();
};

