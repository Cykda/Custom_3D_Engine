#pragma once
#include <SFML/Graphics.hpp>

#include <vector>


class Point
{
public:
	Point(float X = 0, float Y = 0, float Z = 0)
	{
		this->x = X;
		this->y = Y;
		this->z = Z;
	}


	float x;
	float y;
	float z;
};


class Point2i
{
public:

	Point2i(int X = 0, int Y = 0)
	{
		this->x = X;
		this->y = Y;
	}

	int x;
	int y;

};



class Shape
{
public:


	Shape() = default;
	Shape(std::vector<Point> shape)
	{
		this->shape = shape;
	}

	void Load(std::vector<Point> shape)
	{
		this->shape = shape;
	}


	std::vector<Point> getShape()
	{
		return this->shape;
	}

	std::vector<Point> shape;
};












void DrawPoint(sf::RenderWindow &window, sf::Vector2f position, sf::Color color, float radius);