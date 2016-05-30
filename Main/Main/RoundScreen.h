#pragma once
#include <iostream>
#include "cScreen.h"
#include "TextField.h"

class RoundScreen: public cScreen
{
	TextField countryTextField;
	TextField cityTextField;
	TextField thingTextField;
	TextField plantTextField;
public:
	RoundScreen();
	int Run(sf::RenderWindow &App, Game &Game);
};

