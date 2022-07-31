#pragma once
#include "Shapes.h"
#include "matrix.h"


std::vector<Point> PYRAMIDSHAPE(float side)
{
    return std::vector<Point>( {
        Point(0, -side, 0),
        Point(-side, side, -side),
        Point(-side, side, side),
        Point(side, side, -side),
        Point(side, side, side)


    });
}



extern Matrix<int> PYRAMIDADJENCY({
    {0, 1},
    {1, 2},
    {2, 4},
    {4, 3},
    {0, 2},
    {0, 3},
    {0, 4},
    {3, 1}
});


