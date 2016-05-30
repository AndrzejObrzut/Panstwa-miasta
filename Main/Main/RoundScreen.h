#pragma once
#include <iostream>
#include "cScreen.h"
#include "TextField.h"

class RoundScreen: public cScreen
{
	TextField cityTextField;
public:
	RoundScreen();
	int Run(sf::RenderWindow &App, Game &Game);
};

