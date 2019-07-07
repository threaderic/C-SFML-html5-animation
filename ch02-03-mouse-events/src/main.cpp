#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
#elif __linux__
    #include <SFML/Graphics.hpp>
#endif

#include <iostream>
int main() 
{
	sf::Window window(sf::VideoMode(800,600), "Mouse Events", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);
	sf::Clock clickClock;

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
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        // left click..
                        std::cout << "left click\n";
                    }
                    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                    {
                        // right click..
                        std::cout << "right click\n";
                    }
                    else
                    {
                        // probably middle clicks but who knows ;)
                        std::cout << "on which fucking button did you clicked ?\n";
                    }
                    
                    //next code to be improved...
					if (clickClock.restart().asMilliseconds() <= 500) 
					{
						std::cout << "Double Click\n";
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        // left click..
                        std::cout << "double left click\n";
                    }
                    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                    {
                        // right click..
                        std::cout << "double right click\n";
                    }
                    else
                    {
                        // probably middle clicks but who knows ;)
                        std::cout << "on which fucking button did you double clicked ?\n";
                    }
                    }
					break;
				case sf::Event::MouseButtonReleased:
					std::cout << "Mouse Up\n";
					std::cout << "Mouse Click\n";
					if (clickClock.restart().asMilliseconds() <= 500) 
					{
						std::cout << "Double Click\n";
					}
					break;
				case sf::Event::MouseWheelScrolled:
					std::cout << "Mouse Wheel\n";
					break;
				case sf::Event::MouseMoved:
					std::cout << "Mouse Move\n";
					break;
				case sf::Event::MouseEntered:
					std::cout << "Mouse Over\n";
					break;
				case sf::Event::MouseLeft:
					std::cout << "Mouse Out\n";
					break;
			}
		}
	}
}
