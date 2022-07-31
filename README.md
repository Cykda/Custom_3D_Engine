﻿# Custom 3D engine for SFML


## preamble

Hi everybody, I present myself in front of this community for showing
you my custom 3D engine for Simple and Fast Multimedia Library (**SFML**).
I want to learn how 3D graphics works so I simply pick a 2D library (I already
know SFML) and make my own simple 3D rendering engine in C++.


## So how does it works ?

3D in its simplest form is basically matrix multiplication.

**1.** You have an array of points (***X; Y; Z** coordinates*) like for exemple 
representing a cube, You have to go from 3D space to 2D space 
(*only **X; Y** coordinates*).
This step is really simple because you have to multiply the points matrix:
```
     ___
    | X |
    | Y |
    | Z |
     ‾‾‾
```
by the projection matrix:<br/>
![alt Projection Matrix](https://wikimedia.org/api/rest_v1/media/math/render/svg/0fae863970e466a20b888f60585547bef7e06837)


But if you look closely to the result, you realize that the result is
just the points matrix where the *Z* coordinate has been removed.


**2.** Ok so now it is kind of boaring because we rendered a shape but it
doesn't do anything so we can add rotation so, before we multiply the point
matrix with rotation matrices:

![Wikipedia rotation matrices](https://wikimedia.org/api/rest_v1/media/math/render/svg/39b17b4c8417e071083a2a1756d51014d5b34900)<br/><br/>
[Wikipedia rotation matrices page](https://en.wikipedia.org/wiki/Rotation_matrix)

and then you multiply the result by the projection matrix.


## How to use my custom engine

First of all my engine is running on **Visual Studio 2022** and runs on
**C++17**, I run my code in **Debug mode x64**.
To run my code, just open the file **3D Engine.cpp** and run the code.

This engine is design to be modular, you can write your own 3D shape.

## How to write a custom shape

First of all you have to write a shape:
```cpp
Shape CustomShape;

```
then you have to create an ```std::vector<Point>``` to contain
the points coordinates of you shape:

```cpp
float side = 200.f;
std::vector<Point> Points = {

    Point(-side, -side, -side),
    Point(side, -side, -side),
    Point(side, side, -side),
    Point(-side, side, -side),
    Point(-side, -side, side),
    Point(side, -side, side),
    Point(side, side, side),
    Point(-side, side, side)

}; // this is the Point matrix for a 3D cube

```

and then we have to load the shape with the ```std::vector<Point>```:
```cpp

CustomShape.Load(Points);

```
now that we have a shape we just have to setup the engine, I assume that 
you know how to setup **SFML**.
First we have to declare parameters:
```cpp
Parameters parameters(true, true, true); 
// Parameters parameters(doRotateX, doRotateY, doRotateZ);
```

and then we have to declare the projector, load the shape and define
the perspective:
```cpp
Projector projector(parameters);
projector.LoadShape(CustomShape);
projector.setDistance(1);

```

```projector.setDistance(1)``` set the perspective, 1 in recommended or
it will deforme the perspective.


Ok so now we have to declare the adjacency matrix.
The adjacency matrix is just a matrix that dictates 
the connections between the points.
For a cube the matrix looks like this:
```cpp

Matrix<int> AdjencyCube({
        {1, 4},
        { 2, 5 },
        { 3, 6 },
        { 0, 7 },
        { 5 },
        { 6 },
        { 7 },
        { 4 }
});

```
**explanation:** <br/>
You declatre a new ```Matrix<int>``` with the constructor of connections;
for this example int the first line the second point is connected to the fourth 
(*because the list of points start in the position 0*)
the second line connects the third point with the sixth.
And for the fith line we just connect je sixth point with itself to 
avoid false connection trigger.

And then we just load the above declared matrix in the projector:
```cpp
projector.LoadAdjacencyMatrix(AdjencyCube);
```

And then in **SFML** we just draw the projector:
```cpp
window.clear();

projector.draw(window);

window.display();
```

In case you set the projector to rotate you just have to create an
angle variable: ```float angle = 0.f;```,
update the angle automatically and then increment the angle value by
a small value:
```cpp
projector.setAngle(angle);
angle += 0.01;
```

## And then what ?

And then what ?!? this kind of project is never finished and if you explore
the source code you can probably figure a better way to do this stuff.
This software is extremely slow and when you write a complex custom
shape it is very slow and my next goal is to add translation matrix
to translate the shapes in the 3D space.

to resume, this piece of garbage is easily slow but I had a really
good time doing this and in case you read this README file feel free
to modify, fork merge this software to make everybody learn more about
the programming, 3D, and matrices.

## Things to add

- add translation matrix
- optimizing code 

## Bibliography
- Rotation matrices [Wikipedia](https://en.wikipedia.org/wiki/Rotation_matrix)
- Projection Matrix [Wikipedia](https://en.wikipedia.org/wiki/Projection_matrix)
- C++ graphics lib [SFML](https://www.sfml-dev.org/index.php) 