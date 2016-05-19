#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

class cScreen
{
public:
	virtual int Run(sf::RenderWindow &App, Game &Game) = 0;
};

