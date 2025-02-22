#include <iostream>
#include <random>
#include <algorithm>
#include "SFML\Graphics.hpp"
#include "Point3d.h"
#include "Triangle.h"
#include "Utils.h"

float fl = 250,
        vpX = 0,
        vpY = 0;

void Move(Point3d &point, float angleX, float angleY) {
    point.RotateX(angleX);
    point.RotateY(angleY);
}

int main() {
    //You can turn off antialiasing if your graphics card doesn't support it
    sf::ContextSettings context;
    context.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(400, 400), "Pyramid", sf::Style::Titlebar | sf::Style::Close,
                            context);
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("res/cour.ttf")) {
        std::cerr << "Error loading cour.ttf file" << std::endl;
        return -1;
    }

    sf::Text infoText;
    infoText.setFont(font);
    infoText.setCharacterSize(10);
    infoText.setFillColor(sf::Color::Black);
    infoText.setPosition(sf::Vector2f(5, window.getSize().y - 20));
    infoText.setString("Move mouse on window.");

    std::mt19937 m(time(NULL));
    std::uniform_real_distribution<float> t(0.0f, 1.0f);

    std::vector<Point3d> points;
    std::vector<Triangle> triangles;
    float angleX = 0;
    float angleY = 0;
    vpX = window.getSize().x / 2.0f;
    vpY = window.getSize().y / 2.0f;

    //front four corners
    points.emplace_back(Point3d(0, -100, 0));
    points.emplace_back(Point3d(100, 100, -100));
    points.emplace_back(Point3d(-100, 100, -100));
    points.emplace_back(Point3d(-100, 100, 100));
    points.emplace_back(Point3d(100, 100, 100));

    triangles.emplace_back(Triangle(points[0], points[1], points[2], Utils::HexColorToSFMLColor("#6666cc")));
    triangles.emplace_back(Triangle(points[0], points[2], points[3], Utils::HexColorToSFMLColor("#66cc66")));
    triangles.emplace_back(Triangle(points[0], points[3], points[4], Utils::HexColorToSFMLColor("#cc6666")));
    triangles.emplace_back(Triangle(points[0], points[4], points[1], Utils::HexColorToSFMLColor("#66cccc")));
    triangles.emplace_back(Triangle(points[1], points[3], points[2], Utils::HexColorToSFMLColor("#cc66cc")));
    triangles.emplace_back(Triangle(points[1], points[4], points[3], Utils::HexColorToSFMLColor("#cc66cc")));

    for (int j = 0; j < points.size(); ++j) {
        points[j].SetVanishingPoint(vpX, vpY);
        points[j].SetCenter(0, 0, 200);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseMoved:
                    angleX = (event.mouseMove.y - vpY) * 0.0005;
                    angleY = (event.mouseMove.x - vpX) * 0.0005;
                    break;
            }
        }


        for (int i = 0; i < points.size(); ++i) {
            Move(points[i], angleX, angleY);
        }

        window.clear(sf::Color::White);
        for (int j = 0; j < triangles.size(); ++j) {
            triangles[j].Draw(window);
        }
        window.draw(infoText);
        window.display();
    }

}
