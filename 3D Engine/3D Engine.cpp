#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Engine.h"



using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::cin;




int main()
{



    int size[2] = {1920, 1080};
    
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    sf::RenderWindow window(sf::VideoMode(size[0], size[1]), "Custom 3D Engine", sf::Style::Default, settings);
    sf::View Origin(sf::FloatRect(-size[0] / 2, -size[1] / 2, size[0], size[1]));
    window.setVerticalSyncEnabled(true);

    window.setView(Origin);



    
    float side = 200;
    float length = 200;

    float factor = 0.5f;




    std::vector<Point> Hexagone_Cone({


        Point(side * cos(deg2rad(240)), side * sin(deg2rad(240)), length),
        Point(-side, 0, length),
        Point(side * cos(deg2rad(120)), side * sin(deg2rad(120)), length),
        Point(side * cos(deg2rad(60)), side * sin(deg2rad(60)), length),
        Point(side, 0, length),
        Point(side * cos(deg2rad(300)), side * sin(deg2rad(300)), length),



        Point(side * cos(deg2rad(240)) * factor, side * sin(deg2rad(240) * factor), -length),
        Point(-side, 0, -length),
        Point(side * cos(deg2rad(120)) * factor, side * sin(deg2rad(120)) * factor, -length),
        Point(side * cos(deg2rad(60)) * factor, side * sin(deg2rad(60)) * factor, -length),
        Point(side, 0, -length),
        Point(side * cos(deg2rad(300)) * factor, side * sin(deg2rad(300)) * factor, -length)




    });

    



    Shape shape = HexagonPrism(side, length);
    
    Projector projector;
    projector.LoadShape(shape);
    projector.setDistance(1);
    projector.LoadAdjacencyMatrix(HEXAGONPRISMADJACENCY);
    projector.showPoint(true, 5, sf::Color::Yellow);
    


    float angleX = 0.f;
    float angleY = 0.f;
    float angleZ = 0.f;
    
    float RotationSpeed = 0.6f;

    sf::Clock clock;
    Clock CustomTimer(1.f);


    float dt = 0;

    float fps = 0;

    bool Dpressed = false;
    bool Zpressed = false;
    bool Qpressed = false;
    bool Spressed = false;


    // H, J, K for automatic rotation

    bool Hpressed = false;
    bool Jpressed = false;
    bool Kpressed = false;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::D)
                {
                    Dpressed = true;
                }
                else if (event.key.code == sf::Keyboard::Z)
                {
                    Zpressed = true;
                }
                else if (event.key.code == sf::Keyboard::Q)
                {
                    Qpressed = true;
                }
                else if (event.key.code == sf::Keyboard::S)
                {
                    Spressed = true;
                }


                else if (event.key.code == sf::Keyboard::H)
                {
                    if (Hpressed)
                    {
                        Hpressed = false;
                    }
                    else
                    {
                        Hpressed = true;
                    }
                }
                else if (event.key.code == sf::Keyboard::J)
                {
                    if (Jpressed)
                    {
                        Jpressed = false;
                    }
                    else
                    {
                        Jpressed = true;
                    }
                }
                else if (event.key.code == sf::Keyboard::K)
                {
                    if (Kpressed)
                    {
                        Kpressed = false;
                    }
                    else
                    {
                        Kpressed = true;
                    }
                }

            }
            else if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::D)
                {
                    Dpressed = false;
                }
                else if (event.key.code == sf::Keyboard::Z)
                {
                    Zpressed = false;
                }
                else if (event.key.code == sf::Keyboard::Q)
                {
                    Qpressed = false;
                }
                else if (event.key.code == sf::Keyboard::S)
                {
                    Spressed = false;
                }
            }


        }


        window.clear();
        DrawPoint(window, sf::Vector2f(0, 0), sf::Color::Red, 2.f);
        

        
        projector.draw(window);
        if (CustomTimer.doTriggered())
        {
            
            fps = 1 / dt;
            CustomTimer.reset(false);
            fps = roundf(fps);

        }
        displayText(window, sf::Vector2f(-size[0] / 2, -size[1] / 2), "./assets/fonts/NewShape-Book.ttf", std::to_string(fps), 30, sf::Color::Red);
        window.display();

        
        dt = clock.restart().asSeconds();
        
        CustomTimer.update(dt);
        
        if (Zpressed || Hpressed)
        {
            angleX += RotationSpeed;
        }
        if (Dpressed || Jpressed)
        {
            angleY += RotationSpeed;
        }
        if (Qpressed || Kpressed)
        {
            angleZ += RotationSpeed;
        }


        if (Spressed)
        {
            angleX -= RotationSpeed;
        }

        //cout << "Angle X: " << angleX << endl;
        
        
        projector.setAngle(angleX, angleY, angleZ);
    
    }






}
