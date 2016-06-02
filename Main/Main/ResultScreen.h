#pragma once
#include <iostream>
#include "cScreen.h"
#include <SFML/Graphics.hpp>

class ResultScreen : public cScreen
{
public:
	ResultScreen();
	~ResultScreen();
	int Run(sf::RenderWindow &App, Game &game);
};

