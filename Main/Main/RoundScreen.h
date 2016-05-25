#pragma once
#include <iostream>
#include "cScreen.h"

class RoundScreen: public cScreen
{
public:
	RoundScreen();
	~RoundScreen();
	int Run(sf::RenderWindow &App, Game &Game);
};

