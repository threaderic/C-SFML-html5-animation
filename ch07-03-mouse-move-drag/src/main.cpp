#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
#elif __linux__
    #include <SFML/Graphics.hpp>
#endif

#include <iostream>

#include "Utils.h"
#include "Ball.h"

int main() {
    //You can turn off antialiasing if your graphics card doesn't support it
    sf::ContextSettings context;
    context.antialiasingLevel = 4;

    sf::RenderWindow window(sf::VideoMode(400, 400), "Mouse Move Drag", sf::Style::Titlebar | sf::Style::Close,
                            context);
    window.setFramerateLimit(60);

    sf::Font font;

    if (!font.loadFromFile("ch07-03-mouse-move-drag/res/cour.ttf")) {
        std::cout << "Cannot find cour.ttf file";
        return -1;
    }

    sf::Text debugText;
    debugText.setPosition(10, window.getSize().y - 20);
    debugText.setFont(font);
    debugText.setFillColor(sf::Color::Black);
    debugText.setCharacterSize(15);
    debugText.setString("Press and drag circle with mouse.");

    Ball ball(window.getSize().x / 2, window.getSize().y / 2, 30, sf::Color::Red);

    bool isMouseDown = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (Utils::ContainsPoint(ball.GetBounds(), event.mouseButton.x, event.mouseButton.y))
                        isMouseDown = true;
                    break;
                case sf::Event::MouseButtonReleased:
                    isMouseDown = false;
                case sf::Event::MouseMoved:
                    if (isMouseDown) {
                        ball.SetX(event.mouseMove.x);
                        ball.SetY(event.mouseMove.y);
                    }
                    break;
            }
        }

        window.clear(sf::Color::White);
        window.draw(debugText);
        ball.Draw(window);
        window.display();
    }
}
