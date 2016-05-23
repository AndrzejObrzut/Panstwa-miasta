#pragma once
#include <iostream>
#include "cScreen.h"
#include <SFML/Graphics.hpp>
#include "Game.h"

class ChoosePlayerScreen: public cScreen
{
private:
	sf::Font font;
	sf::RectangleShape textFieldRect;
	std::string playerName;
	sf::Text textField;
	void setTextField();
public:
	ChoosePlayerScreen();
	~ChoosePlayerScreen();
	int Run(sf::RenderWindow &App, Game &game);
	//int Run(sf::RenderWindow &App, const Game &game);
};

