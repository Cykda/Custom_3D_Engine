#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Projector.h"
#include "Shapes.h"
#include "utils.h"
#include "Clock.h"
#include "Text.h"



using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::cin;


int main()
{

    int size[2] = {1920, 1080};
    sf::RenderWindow window(sf::VideoMode(size[0], size[1]), "Hello World !");
    sf::View Origin(sf::FloatRect(-size[0] / 2, -size[1] / 2, size[0], size[1]));
    window.setVerticalSyncEnabled(true);

    window.setView(Origin);


    Shape Cube = CubeShape(200);
    Parameters parametres(true, true, true);
    
    float side = 100;
    Shape test;

    std::vector<Point> tst = {
        {-side, side, -side},
        {0, 0, side},
        {-side, side, side},
        {0, side, -side}
    
    };

    test.Load(tst);

    Matrix<int> AdjencyMat({
        {0, 1},
        {1, 2},
        {2, 3}
    });
    




    Projector projector(parametres);
    projector.LoadShape(test);
    projector.setDistance(1);
    projector.LoadAdjacencyMatrix(AdjencyMat);
    


    float angle = 0;


    sf::Clock clock;
    Clock CustomTimer(1.f);


    float dt = 0;

    float fps = 0;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        projector.draw(window);
        if (CustomTimer.doTriggered())
        {
            
            fps = 1 / dt;
            CustomTimer.reset(false);

        }
        displayText(window, sf::Vector2f(-size[0] / 2, -size[1] / 2), "./assets/fonts/NewShape-Book.ttf", std::to_string(std::round(fps)), 30, sf::Color::Red);
        
        window.display();

        
        dt = clock.restart().asSeconds();
        
        projector.setAngle(angle);
        CustomTimer.update(dt);
        angle += 0.01;

    
    }






}