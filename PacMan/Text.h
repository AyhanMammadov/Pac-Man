#pragma once
#include<sstream>
struct Text {
	sf::Text text;
	sf::Font font;
	Text(string pathForText)
	{
		font.loadFromFile(pathForText);
	}
	int count = 0;
	void TextFunc(sf::RenderWindow* window, Player* hero) {
		sf::Text textForWindow = sf::Text("", font, 20);
		textForWindow.setFillColor(sf::Color::Black);
		textForWindow.setStyle(sf::Text::Regular);

		if (gameMap[hero->newCordinatY][hero->newCordinatY] == ' ')
			count = hero->getCountOfStars() * 100;

		ostringstream score;
		score << count;

		textForWindow.setString("Game score: " + score.str());
		textForWindow.setPosition(2, 2);

		window->draw(textForWindow);
	}
};