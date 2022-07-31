#include <iostream>
#include "Text.h"


using std::cout;
using std::endl;
using std::cerr;
//
int displayText(sf::RenderWindow& window, sf::Vector2f position, std::string fontPath, std::string message, int CharacterSize, sf::Color textColor)
{

	sf::Font font;
	if (!font.loadFromFile(fontPath))
	{
		cerr << "FONT PATH INCORRECT" << endl;
		return EXIT_FAILURE;
	}

	sf::Text text;

	text.setFont(font);
	text.setString(message);
	text.setCharacterSize(CharacterSize);
	text.setFillColor(textColor);
	text.setPosition(position);


	window.draw(text);

	return EXIT_SUCCESS;
}
