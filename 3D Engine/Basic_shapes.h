#pragma once
#include "Shapes.h"
#include "matrix.h"
#include "connector.h"
#include "utils.h"

// Pyramid
Shape PyramidShape(float side)
{
    std::vector<Point> PyramidVector( {
        Point(0, -side, 0),
        Point(-side, side, -side),
        Point(-side, side, side),
        Point(side, side, -side),
        Point(side, side, side)


    });
    Shape s;
    s.Load(PyramidVector);
    return s;
}



extern std::vector<Connector> PYRAMIDADJACENCY({

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


extern std::vector<Connector> CUBEADJACENCY({

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

// hexagonal prism



Shape HexagonPrism(float side, float length)
{
    std::vector<Point> hexagonal_points({

    Point(side * cos(deg2rad(240)), side * sin(deg2rad(240)), length),
    Point(-side, 0, length),
    Point(side * cos(deg2rad(120)), side * sin(deg2rad(120)), length),
    Point(side * cos(deg2rad(60)), side * sin(deg2rad(60)), length),
    Point(side, 0, length),
    Point(side * cos(deg2rad(300)), side * sin(deg2rad(300)), length),



    Point(side * cos(deg2rad(240)), side * sin(deg2rad(240)), -length),
    Point(-side, 0, -length),
    Point(side * cos(deg2rad(120)), side * sin(deg2rad(120)), -length),
    Point(side * cos(deg2rad(60)), side * sin(deg2rad(60)), -length),
    Point(side, 0, -length),
    Point(side * cos(deg2rad(300)), side * sin(deg2rad(300)), -length)



    });

    Shape s;
    s.Load(hexagonal_points);
    return s;
}

extern std::vector<Connector> HEXAGONPRISMADJACENCY({

        Connector(0, 1),
        Connector(1, 2),
        Connector(2, 3),
        Connector(3, 4),
        Connector(4, 5),
        Connector(5, 0),



        Connector(6, 7),
        Connector(7, 8),
        Connector(8, 9),
        Connector(9, 10),
        Connector(10, 11),
        Connector(11, 6),



        Connector(0, 6),
        Connector(1, 7),
        Connector(2, 8),
        Connector(3, 9),
        Connector(4, 10),
        Connector(5, 11)



});