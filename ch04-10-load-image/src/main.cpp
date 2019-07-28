#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
#elif __linux__
    #include <SFML/Graphics.hpp>
#endif

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Load Image", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(1);

	sf::Texture texture;
	if (!texture.loadFromFile("ch04-10-load-image/res/picture2.jpg"))
		return -1;

	sf::Sprite sprite = sf::Sprite(texture);
	sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	window.clear(sf::Color::White);
	window.draw(sprite);
	window.display();

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

	}

	return 0;
}