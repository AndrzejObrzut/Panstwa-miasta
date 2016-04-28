#include "stdafx.h"
#include "Game.h"


Game::Game(int numberOfPlayers) : _numberOfPlayers(numberOfPlayers)
{
}

Game::Game(int numberOfRounds, int numberOfPlayers) : _numberOfRounds(numberOfRounds), _numberOfPlayers(numberOfPlayers)
{
}

void Game::playGame()
{
	newRound();
}

void Game::endGame()
{
}

void Game::setNumberOfRounds(int number)
{
	_numberOfRounds = number;
}

int Game::getNumberOfRounds()
{
	return _numberOfRounds;
}

void Game::newRound()
{
	cout << "Nowa runda" << endl;
}

Game::~Game()
{
}
