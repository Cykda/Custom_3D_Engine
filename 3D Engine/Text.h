#pragma once
#include <SFML/Graphics.hpp>
#include <string>


int displayText(sf::RenderWindow &window, sf::Vector2f position, std::string fontPath, std::string message, int CharacterSize, sf::Color textColor);
