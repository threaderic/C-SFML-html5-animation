#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
#elif __linux__
    #include <SFML/Graphics.hpp>
#endif

#include "Ball.h"

int main()
{
	//You can turn off antialiasing if your graphics card doesn't support it
	sf::ContextSettings context;
	context.antialiasingLevel = 4;

	sf::RenderWindow window(sf::VideoMode(400,400), "Velocity 1", sf::Style::Titlebar | sf::Style::Close, context);
	window.setFramerateLimit(60);
	
	float vx = 1;
	Ball ball = Ball(50, 100, 40, sf::Color::Red);

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
			}
		}

		ball.Translate(vx,0);

		window.clear(sf::Color::White);
		window.draw(ball.shape);
		window.display();

	}

	return 0;
}
