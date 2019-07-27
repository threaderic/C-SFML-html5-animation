#pragma once

#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
#elif __linux__
    #include <SFML/Graphics.hpp>
#endif

class Arrow
{
public:
	Arrow(float x, float y);
	~Arrow();

	sf::ConvexShape shape;
};

