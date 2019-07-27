#pragma once

#if _WIN32 //for both 32 and 64 bit environnemnts -- Pre-defined Compiler Macros -- sourceforge
    #include "SFML\Graphics.hpp"
#elif __linux__
    #include <SFML/Graphics.hpp>
#endif

namespace Utils {
	namespace Bezier {
		void QuadraticBezierCurve(const sf::Vector2f &p0, sf::Vector2f &p1, sf::Vector2f &p2, int segments, std::vector<sf::Vector2f> &curvePoints, bool throughControlPoint = false);
		void QuadraticBezierCurve(const sf::Vector2f &p0, sf::Vector2f &p1, sf::Vector2f &p2, int segments, std::vector<sf::Vertex> &curvePoints, sf::Color lineColor, bool throughControlPoint = false);
		void AccumulativeQuadraticBezierCurve(const sf::Vector2f &p0, sf::Vector2f &p1, sf::Vector2f &p2, int segments, std::vector<sf::Vertex> &curvePoints, sf::Color lineColor, bool throughControlPoint = false);
	}
}
