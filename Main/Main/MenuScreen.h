#pragma once

#include <iostream>
#include "cScreen.h"
#include <SFML/Graphics.hpp>

class MenuScreen : public cScreen
{
public:
	MenuScreen();
	~MenuScreen();
	virtual int Run(sf::RenderWindow &App);
};

