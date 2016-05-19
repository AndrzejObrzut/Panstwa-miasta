#pragma once
#include <iostream>
#include "cScreen.h"
#include <SFML/Graphics.hpp>
#include "Game.h"

class ChoosePlayerScreen: public cScreen
{
public:
	ChoosePlayerScreen();
	~ChoosePlayerScreen();
	int Run(sf::RenderWindow &App, Game &game);
	//int Run(sf::RenderWindow &App, const Game &game);
};

