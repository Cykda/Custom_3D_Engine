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

Projector::Projector(Parameters p)
{

	//initiate rotation matrices
    this->parametres = p;
    this->RotationX.mat = 
    {
        {1, 0, 0},
        {0, cos(this->angle), -sin(this->angle)},
        {0, sin(this->angle), cos(this->angle)}

    };

    this->RotationY.mat = 
    {
        {cos(this->angle), 0, sin(this->angle)},
        {0, 1, 0},
        {-sin(this->angle), 0, cos(this->angle)}

    };


    this->RotationZ.mat =
    {
        {cos(this->angle), -sin(this->angle), 0},
        {sin(this->angle), cos(this->angle), 0},
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

void Projector::setAngle(float angle)
{
    this->angle = angle;
}

void Projector::draw(sf::RenderTarget& window)
{

    this->RotationX.mat =
    {
        {1, 0, 0},
        {0, cos(this->angle), -sin(this->angle)},
        {0, sin(this->angle), cos(this->angle)}

    };

    this->RotationY.mat =
    {
        {cos(this->angle), 0, sin(this->angle)},
        {0, 1, 0},
        {-sin(this->angle), 0, cos(this->angle)}

    };


    this->RotationZ.mat =
    {
        {cos(this->angle), -sin(this->angle), 0},
        {sin(this->angle), cos(this->angle), 0},
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
        /*
        if (this->parametres.RotateX)
        {
            Rotated = matmul<float>(this->RotationX, projected);
        }
        if (this->parametres.RotateY)
        {
            Rotated = matmul<float>(this->RotationY, Rotated);
        }
        if (this->parametres.RorateZ)
        {
            Rotated = matmul<float>(this->RotationZ, Rotated);
        }
        */

        if (this->parametres.RotateX && !this->parametres.RotateY && !this->parametres.RorateZ)
        {
            Rotated = matmul<float>(this->RotationX, projected);
        }
        else if (!this->parametres.RotateX && this->parametres.RotateY && !this->parametres.RorateZ)
        {
            Rotated = matmul<float>(this->RotationY, projected);
        }
        else if (!this->parametres.RotateX && !this->parametres.RotateY && this->parametres.RorateZ)
        {
            Rotated = matmul<float>(this->RotationZ, projected);
        }
        else if (this->parametres.RotateX && this->parametres.RotateY && !this->parametres.RorateZ)
        {
            Rotated = matmul<float>(this->RotationX, projected);
            Rotated = matmul<float>(this->RotationY, Rotated);
        }
        else if (this->parametres.RotateX && !this->parametres.RotateY && this->parametres.RorateZ)
        {
            Rotated = matmul<float>(this->RotationX, projected);
            Rotated = matmul<float>(this->RotationZ, Rotated);
        }
        else if (!this->parametres.RotateX && this->parametres.RotateY && this->parametres.RorateZ)
        {
            Rotated = matmul<float>(this->RotationY, projected);
            Rotated = matmul<float>(this->RotationZ, Rotated);
        }
        else if (this->parametres.RotateX && this->parametres.RotateY && this->parametres.RorateZ)
        {
            Rotated = matmul<float>(this->RotationX, projected);
            Rotated = matmul<float>(this->RotationY, Rotated);
            Rotated = matmul<float>(this->RotationZ, Rotated);
        }
        else
        {
            Rotated = projected;
        }
        float z = 0;

        std::vector<float> BufferNorm = {Rotated.mat[0][0], Rotated.mat[1][0] , Rotated.mat[2][0]};



        float CameraDistance = 1 / (distance - (Rotated.mat[2][0] / 1000));

     
        this->ProjectionMatrix.mat =
        {
            {abs(CameraDistance), 0, 0},
            {0, abs(CameraDistance), 0}
        };

        this->Projected2D = Matrix<float>({
            {Rotated.mat[0][0]},
            {Rotated.mat[1][0]}
        });
        
        
        sf::CircleShape point;
        point.setPointCount(100);
        point.setRadius(2);
        point.setOrigin(sf::Vector2f(point.getGlobalBounds().width / 2, point.getGlobalBounds().height / 2));
        point.setFillColor(sf::Color::White);
        point.setPosition(sf::Vector2f(this->Projected2D.mat[0][0], this->Projected2D.mat[1][0]));
        window.draw(point);


        

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


