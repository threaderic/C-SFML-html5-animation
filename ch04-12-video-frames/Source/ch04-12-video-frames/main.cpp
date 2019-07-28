#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
    #include <sfeMovie\Movie.hpp>
#elif __linux__
    #include <SFML/Graphics.hpp>
    #include "../../external-libraries/sfeMovie/include/Movie.hpp"
#endif


#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(720, 400), "Video Frames", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	sfe::Movie movie;
	if (!movie.openFromFile("ch04-12-video-frames/Source/ch04-12-video-frames/Big_Buck_Bunny_Trailer_400p.ogv"))
		return 1;
	
	movie.setPosition(sf::Vector2f(0.0f, 0.0f));
	movie.play();

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
		movie.update();
		window.clear(sf::Color::Black);
		window.draw(movie);
		window.display();

	}

	return 0;
}