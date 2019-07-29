#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
#elif __linux__
    #include <SFML/Graphics.hpp>
#endif

#include <iostream>
#include <random>

#include "Utils.h"
#include "Ball.h"

const float BOUNCE = -0.7f;
const float GRAVITY = 0.1f;
float oldX = 0;
float oldY = 0;

void CheckBoundaries(sf::RenderWindow &window, Ball &ball) {
    float left = 0;
    float right = window.getSize().x;
    float top = 0;
    float bottom = window.getSize().y;

    sf::Vector2f ballPos = ball.shape.getPosition();

    ball.vy += GRAVITY;
    if (ballPos.x + ball.shape.getRadius() > right) {
        ball.SetX(right - ball.shape.getRadius());
        ball.vx *= BOUNCE;
    } else if (ballPos.x - ball.shape.getRadius() < left) {
        ball.SetX(left + ball.shape.getRadius());
        ball.vx *= BOUNCE;
    }

    if (ballPos.y + ball.shape.getRadius() > bottom) {
        ball.SetY(bottom - ball.shape.getRadius());
        ball.vy *= BOUNCE;
    } else if (ballPos.y - ball.shape.getRadius() < top) {
        ball.SetY(top + ball.shape.getRadius());
        ball.vy *= BOUNCE;
    }

    ball.Translate(ball.vx, ball.vy);
}

void TrackVelocity(Ball &ball) {
    ball.vx = ball.GetX() - oldX;
    ball.vy = ball.GetY() - oldY;
    oldX = ball.GetX();
    oldY = ball.GetY();
}

int main() {
    //You can turn off antialiasing if your graphics card doesn't support it
    sf::ContextSettings context;
    context.antialiasingLevel = 4;

    sf::RenderWindow window(sf::VideoMode(400, 400), "Throwing", sf::Style::Titlebar | sf::Style::Close,
                            context);
    window.setFramerateLimit(60);

    sf::Font font;

    if (!font.loadFromFile("ch07-06-throwing/res/cour.ttf")) {
        std::cout << "Cannot find cour.ttf file";
        return -1;
    }

    sf::Text debugText;
    debugText.setPosition(10, window.getSize().y - 20);
    debugText.setFont(font);
    debugText.setFillColor(sf::Color::Black);
    debugText.setCharacterSize(15);
    debugText.setString("Press, drag and throw circle with mouse.");

    std::mt19937 mt(time(NULL));
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);

    Ball ball(window.getSize().x / 2, window.getSize().y / 2, 30, sf::Color::Red);
    ball.vx = dist(mt) * 10 - 5;
    ball.vy = -10;

    bool isMouseDown = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (Utils::ContainsPoint(ball.GetBounds(), event.mouseButton.x, event.mouseButton.y)) {
                        isMouseDown = true;
                    }
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

        if (isMouseDown)
            TrackVelocity(ball);
        else
            CheckBoundaries(window, ball);

        window.draw(ball.shape);
        window.display();
    }
}
