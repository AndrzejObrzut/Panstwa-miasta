#pragma once
#include <iostream>
#include "cScreen.h"
#include <SFML/Graphics.hpp>

class ChoosePlayerScreen: public cScreen
{
public:
	ChoosePlayerScreen();
	~ChoosePlayerScreen();
	virtual int Run(sf::RenderWindow &App);
};

