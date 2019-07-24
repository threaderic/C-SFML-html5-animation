#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
#elif __linux__
    #include <SFML/Graphics.hpp>
#endif

#include <iostream>
int main() 
{
	sf::RenderWindow window(sf::VideoMode(800,600), "Mouse Position", sf::Style::Titlebar | sf::Style::Close);
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
                case sf::Event::MouseMoved:
					//std::cout << "Mouse Over\n";
                    std::cout << "x1: " << event.mouseMove.x << ", y2: " << event.mouseMove.y << std::endl;
					break;
			}
		}
		
        // Efface l'écran (remplissage avec du noir)
        window.clear();

        // Affichage du contenu de la fenêtre à l'écran
        window.display();
	}
	
    return EXIT_SUCCESS;
}
