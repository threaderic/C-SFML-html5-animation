#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
#elif __linux__
    #include <SFML/Graphics.hpp>
#endif

#include "Ball.h"
#include <cmath>

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Random", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	float angleX = 0;
	float angleY = 0;
	int range = 50;
	float centerX = window.getSize().x / 2.0f;
	float centerY = window.getSize().y / 2.0f;
	float xSpeed = 0.07f;
	float ySpeed = 0.11f;

	Ball ball(centerX, centerY, 40, sf::Color::Red);

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

		angleX += xSpeed;
		angleY += ySpeed;
		ball.shape.setPosition(centerX + std::sin(angleX) * range, centerY + std::sin(angleY) * range);

		window.clear(sf::Color::White);
		window.draw(ball.shape);
		window.display();
	}


}