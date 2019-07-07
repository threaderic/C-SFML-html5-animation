#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
#elif __linux__
    #include <SFML/Graphics.hpp>
#endif

#include <iostream>
int main() 
{
	sf::Window window(sf::VideoMode(800,600), "Mouse Position", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::MouseButtonReleased:
					std::cout << "x: " << event.mouseButton.x << ", y: " << event.mouseButton.y << std::endl;
					break;
			}
		}
	}
}
