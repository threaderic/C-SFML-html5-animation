#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
#elif __linux__
    #include <SFML/Graphics.hpp>
#endif

#include <iostream>
#include <cmath>

int main() {
    //You can turn off antialiasing if your graphics card doesn't support it
    sf::ContextSettings context;
    context.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(400, 400), "Skew X", sf::Style::Titlebar | sf::Style::Close,
                            context);
    window.setFramerateLimit(60);

    float angle = 0;
    sf::RectangleShape rectangle(sf::Vector2f(150, 150));
    rectangle.setOrigin(75, 75);
    rectangle.setFillColor(sf::Color::Red);

    float skewX = 0,
            dx = window.getSize().x / 2,
            dy = window.getSize().y / 2;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseMoved:
                    skewX = (event.mouseMove.x - (window.getSize().x / 2.0f)) * 0.01f;
            }
        }

        sf::Transform transform = sf::Transform(1, skewX, dx, 0, 1, dy, 0, 0, 1);

        window.clear(sf::Color::White);
        window.draw(rectangle, transform);
        window.display();
    }

}
