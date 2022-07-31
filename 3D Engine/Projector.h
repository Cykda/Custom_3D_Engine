#pragma once
#include <SFML/Graphics.hpp>
#include "matrix.h"
#include "Shapes.h"
#include "Parameters.h"



extern Matrix<int> ADJENCYCUBE;
Shape CubeShape(float side);












class Projector
{
public:
	Projector(Parameters p);
	void LoadShape(Shape& shape);
	void LoadAdjacencyMatrix(Matrix<int> AdjencyMatrix);
	void setAngle(float angle);
	void setDistance(float distance);
	void draw(sf::RenderTarget& window);

private:

	Parameters parametres;

	Matrix<float> RotationX;
	Matrix<float> RotationY;
	Matrix<float> RotationZ;
	Matrix<float> ProjectionMatrix;


	float distance = 1;

	bool DoAdjencyMatrix = false;
	Matrix<int> AdjencyMatrix;



	Matrix<float> Projected2D;
	float angle = 0;

	Shape shape;





};




void connectPoints(Point p1, Point p2, sf::RenderTarget& window);