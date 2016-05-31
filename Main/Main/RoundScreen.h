#pragma once
#include <iostream>
#include "cScreen.h"
#include "TextField.h"

class RoundScreen : public cScreen
{
	std::string countryName;
	std::string cityName;
	std::string thingName;
	std::string plantName;

	TextField countryTextField;
	TextField cityTextField;
	TextField thingTextField;
	TextField plantTextField;

	void resetFileds();
public:
	RoundScreen();
	int Run(sf::RenderWindow &App, Game &Game);

};
