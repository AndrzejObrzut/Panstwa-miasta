#include "stdafx.h"
#include "Game.h"

Game::Game(string name, string description)
{
	_name = name;
	_description = description;

}


string Game::DisplayValues()
{
	return "Name: " + _name + ", description: " + _description;
}
