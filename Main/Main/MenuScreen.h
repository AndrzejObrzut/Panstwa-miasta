#pragma once

#include <iostream>
#include "cScreen.h"
#include <SFML/Graphics.hpp>

class MenuScreen : public cScreen
{
private:
	int alpha_max;
	int alpha_div;
	bool playing;
public:
	MenuScreen();
	~MenuScreen();
	virtual int Run(sf::RenderWindow &App);
};

