#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
#elif __linux__
    #include <SFML/Graphics.hpp>
#endif

#include <iostream>
#include <cmath>
#include <random>

#include "Ball.h"

int main() {
    //You can turn off antialiasing if your graphics card doesn't support it
    sf::ContextSettings context;
    context.antialiasingLevel = 4;

    sf::RenderWindow window(sf::VideoMode(400, 400), "Random 6", sf::Style::Titlebar | sf::Style::Close,
                            context);
    window.setFramerateLimit(60);

    std::mt19937 m(std::time(NULL));
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);

    std::vector<sf::CircleShape> dots;
    int numBalls = 300,
            iterations = 6;

    while (numBalls--) {
        float xPos = 0;
        for (int i = 0; i < iterations; ++i) {
            xPos += window.getSize().x * dist(m);
        }

        float x = xPos / iterations;
        float y = window.getSize().y / 2 + dist(m) * 50 - 25;

        dots.emplace_back(sf::CircleShape(2));
        dots[dots.size() - 1].setOrigin(2, 2);
        dots[dots.size() - 1].setPosition(x, y);
        dots[dots.size() - 1].setFillColor(sf::Color::Black);
    }

    window.clear(sf::Color::White);

    for (int i = 0; i < dots.size(); ++i) {
        window.draw(dots[i]);
    }

    window.display();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
    }
}
