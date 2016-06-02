#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

class cScreen
{
public:
	int windowWidth;
	int windowHeight;
	virtual int Run(sf::RenderWindow &App, Game &Game) = 0;
};

