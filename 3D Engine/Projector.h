#pragma once
#include <SFML/Graphics.hpp>
#include "matrix.h"
#include "Shapes.h"

#include "connector.h"
#include "utils.h"















class Projector
{
public:
	Projector();
	void LoadShape(Shape& shape);
	void LoadAdjacencyMatrix(std::vector<Connector> AdjencyMatrix);
	void setAngle(float angleX, float angleY, float angleZ);
	void setDistance(float distance);
	void draw(sf::RenderWindow& window);
	void showPoint(bool state, float radius, sf::Color pointsColor);

private:


	Matrix<float> RotationX;
	Matrix<float> RotationY;
	Matrix<float> RotationZ;
	Matrix<float> ProjectionMatrix;


	float distance = 1;

	bool DoAdjencyMatrix = true;
	std::vector<Connector> AdjencyMatrix;



	Matrix<float> Projected2D;
	float angleX = 0.f;
	float angleY = 0.f;
	float angleZ = 0.f;

	Shape shape;


	bool doShowPoint = false;
	sf::Color pointsColor = sf::Color::White;
	float PointsRadius = 2.f;

};




void connectPoints(Point p1, Point p2, sf::RenderTarget& window);