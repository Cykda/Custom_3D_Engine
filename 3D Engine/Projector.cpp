#include <iostream>
#include <algorithm>
#include "Projector.h"

using namespace std;


void connectPoints(Point p1, Point p2, sf::RenderTarget& window)
{
    sf::VertexArray Line(sf::Lines, 2);
    


    Line[0].position = sf::Vector2f(p1.x, p1.y);
    Line[0].color = sf::Color::White;
    Line[1].position = sf::Vector2f(p2.x, p2.y);
    Line[1].color = sf::Color::White;
    
    window.draw(Line);

}




void Projector::setDistance(float distance)
{
    this->distance = distance;

}

Projector::Projector()
{

	//initiate rotation matrices
    this->RotationX.mat = 
    {
        {1, 0, 0},
        {0, cos(this->angleX), -sin(this->angleX)},
        {0, sin(this->angleX), cos(this->angleX)}

    };

    this->RotationY.mat = 
    {
        {cos(this->angleY), 0, sin(this->angleY)},
        {0, 1, 0},
        {-sin(this->angleY), 0, cos(this->angleY)}

    };


    this->RotationZ.mat =
    {
        {cos(this->angleZ), -sin(this->angleZ), 0},
        {sin(this->angleZ), cos(this->angleZ), 0},
        {0, 0, 1}
    };

    this->ProjectionMatrix.mat = 
    {
        {1, 0, 0},
        {0, 1, 0}
    };


}


void Projector::LoadShape(Shape& shape)
{
    this->shape = shape;
}

void Projector::LoadAdjacencyMatrix(std::vector<Connector> AdjencyMatrix)
{
    this->AdjencyMatrix = AdjencyMatrix;
    this->DoAdjencyMatrix = true;
}

void Projector::setAngle(float angleX, float angleY, float angleZ)
{
    this->angleX = deg2rad(angleX);
    this->angleY = deg2rad(angleY);
    this->angleZ = deg2rad(angleZ);
}

void Projector::draw(sf::RenderWindow& window)
{

    this->RotationX.mat =
    {
        {1, 0, 0},
        {0, cos(this->angleX), -sin(this->angleX)},
        {0, sin(this->angleX), cos(this->angleX)}

    };

    this->RotationY.mat =
    {
        {cos(this->angleY), 0, sin(this->angleY)},
        {0, 1, 0},
        {-sin(this->angleY), 0, cos(this->angleY)}

    };


    this->RotationZ.mat =
    {
        {cos(this->angleZ), -sin(this->angleZ), 0},
        {sin(this->angleZ), cos(this->angleZ), 0},
        {0, 0, 1}
    };

    Shape Buffershape;

    for (Point p : this->shape.getShape())
    {

        std::vector<std::vector<float>> ProjectedVector = {
            {p.x},
            {p.y},
            {p.z}


        };



        Matrix<float> projected;
        projected.mat = ProjectedVector;
        
        
        
        Matrix<float> Rotated;

        Rotated = matmul<float>(this->RotationX, projected);
        Rotated = matmul<float>(this->RotationY, Rotated);
        Rotated = matmul<float>(this->RotationZ, Rotated);
        
        
        std::vector<float> BufferNorm = {Rotated.mat[0][0], Rotated.mat[1][0] , Rotated.mat[2][0]};

        float CameraDistance = 1 / (distance - (Rotated.mat[2][0] / 1000));

        if (this->distance == 0)
        {
            CameraDistance = 1;
        }

        this->Projected2D = Matrix<float>({
            {Rotated.mat[0][0] * abs(CameraDistance)},
            {Rotated.mat[1][0] * abs(CameraDistance)}
        });
        

        if (this->doShowPoint)
        {
            DrawPoint(window, sf::Vector2f(this->Projected2D.mat[0][0], this->Projected2D.mat[1][0]), this->pointsColor, this->PointsRadius);
        }



        

        Point CurrentPoint(this->Projected2D.mat[0][0], this->Projected2D.mat[1][0], 0);
        if (this->DoAdjencyMatrix)
        {
            Buffershape.shape.push_back(CurrentPoint);

        }



    }

    if (this->DoAdjencyMatrix)
    {
        for (int i = 0; i < this->AdjencyMatrix.size(); ++i)
        {

                connectPoints(Buffershape.getShape()[this->AdjencyMatrix[i].p1], Buffershape.getShape()[this->AdjencyMatrix[i].p2], window);


                

        }

    }



    Buffershape.shape.clear();



}

void Projector::showPoint(bool state, float radius, sf::Color pointsColor)
{
    this->doShowPoint = state;
    this->PointsRadius = radius;
    this->pointsColor = pointsColor;
}


