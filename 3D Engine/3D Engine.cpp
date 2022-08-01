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
    window.setVerticalSyncEnabled(false);

    window.setView(Origin);



    Parameters parametres(true, true, true);
    
    float side = 300;
    float length = 300;

    



    Shape hex = HexagonPrism(side, length);


    Projector projector(parametres);
    projector.LoadShape(hex);
    projector.setDistance(1);
    projector.LoadAdjacencyMatrix(HEXAGONPRISMADJACENCY);
    projector.showPoint(true, 10, sf::Color::Green);
    


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
        DrawPoint(window, sf::Vector2f(0, 0), sf::Color::Red, 2.f);
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
