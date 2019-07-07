#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
#elif __linux__
    #include <SFML/Graphics.hpp>
#endif

#include <iostream>
int main() 
{
	sf::Window window(sf::VideoMode(800,600), "Event Demo", sf::Style::Titlebar | sf::Style::Close);
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
				case sf::Event::MouseButtonPressed:
					std::cout << "Mouse Down\n";
					break;
				case sf::Event::MouseButtonReleased:
					std::cout << "Mouse Up\n";
					break;
			}
		}
	}

    return 0;
}
