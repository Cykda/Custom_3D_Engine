#pragma once
#include "Shapes.h"
#include "matrix.h"
#include "connector.h"


// Pyramid
std::vector<Point> PyramidShape(float side)
{
    return std::vector<Point>( {
        Point(0, -side, 0),
        Point(-side, side, -side),
        Point(-side, side, side),
        Point(side, side, -side),
        Point(side, side, side)


    });
}



extern std::vector<Connector> PYRAMIDADJENCY({

    Connector(0, 1),
    Connector(1, 2),
    Connector(2, 4),
    Connector(4, 3),
    Connector(0, 2),
    Connector(0, 3),
    Connector(0, 4),
    Connector(3, 1)
});


// Cube

Shape CubeShape(float side)
{
    std::vector<Point> Points({
        Point(-side, -side, -side),
        Point(side, -side, -side),
        Point(side, side, -side),
        Point(-side, side, -side),
        Point(-side, -side, side),
        Point(side, -side, side),
        Point(side, side, side),
        Point(-side, side, side)
    });

    Shape C;
    C.Load(Points);
    return C;
}


extern std::vector<Connector> CUBEADJENCY({

    Connector(0, 1),
    Connector(1, 2),
    Connector(2, 3),
    Connector(3, 0),

    Connector(4, 5),
    Connector(5, 6),
    Connector(6, 7),
    Connector(7, 4),

    Connector(0, 4),
    Connector(1, 5),
    Connector(2, 6),
    Connector(3, 7)

});