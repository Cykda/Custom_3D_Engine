#include "Shapes.h"


void DrawPoint(sf::RenderWindow& window, sf::Vector2f position, sf::Color color, float radius)
{
	sf::CircleShape point;
	point.setPointCount(100);
	point.setRadius(radius);
	point.setOrigin(sf::Vector2f(point.getGlobalBounds().width / 2, point.getGlobalBounds().height / 2));
	point.setFillColor(color);
	point.setPosition(position);
	window.draw(point);

}

