#pragma once

#include <iostream>
#include "cScreen.h"
#include <SFML/Graphics.hpp>
#include "Game.h"

class MenuScreen : public cScreen
{
public:
	MenuScreen();
	~MenuScreen();
	int Run(sf::RenderWindow &App, Game &game);
};

