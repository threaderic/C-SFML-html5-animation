#include "Triangle.h"

Triangle::Triangle(Point3d &a, Point3d &b, Point3d &c, sf::Color color) {
    pointA = &a;
    pointB = &b;
    pointC = &c;
    fillColor = sf::Color(color.r, color.g, color.b, 255 * alpha);
    lineColor = color;
}

Triangle::~Triangle() {
}

void Triangle::Draw(sf::RenderWindow &window) {

    if (IsBackface()) return;

    sf::VertexArray triangleShape(sf::PrimitiveType::Triangles, 3);

    triangleShape[0] = sf::Vertex(sf::Vector2f(pointA->GetScreenX(), pointA->GetScreenY()), fillColor);
    triangleShape[1] = sf::Vertex(sf::Vector2f(pointB->GetScreenX(), pointB->GetScreenY()), fillColor);
    triangleShape[2] = sf::Vertex(sf::Vector2f(pointC->GetScreenX(), pointC->GetScreenY()), fillColor);

    window.draw(triangleShape);

    if (lineWidth > 0) {
        std::vector<sf::Vertex> outline;
        outline.emplace_back(sf::Vertex(sf::Vector2f(pointA->GetScreenX(), pointA->GetScreenY()), lineColor));
        outline.emplace_back(sf::Vertex(sf::Vector2f(pointB->GetScreenX(), pointB->GetScreenY()), lineColor));
        outline.emplace_back(sf::Vertex(sf::Vector2f(pointC->GetScreenX(), pointC->GetScreenY()), lineColor));

        window.draw(&outline[0], outline.size(), sf::LinesStrip);
    }
}

bool Triangle::IsBackface() {
    float cax = pointC->GetScreenX() - pointA->GetScreenX(),
            cay = pointC->GetScreenY() - pointA->GetScreenY(),
            bcx = pointB->GetScreenX() - pointC->GetScreenX(),
            bcy = pointB->GetScreenY() - pointC->GetScreenY();

    return (cax * bcy > cay * bcx);
}
