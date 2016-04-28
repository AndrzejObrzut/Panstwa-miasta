#include "stdafx.h"
#include "Game.h"


Game::Game()
{
}

Game::Game(int numberOfRounds, int numberOfPlayers) : _numberOfRounds(numberOfRounds), _numberOfPlayers(numberOfPlayers)
{
}

void Game::createPlayers(int numberOfPlayers)
{
	_numberOfPlayers = numberOfPlayers;
	players = new Player[_numberOfPlayers];
}

void Game::setPlayersNames()
{
	for (int i = 0; i < _numberOfPlayers; i++)
	{
		cout << "Podaj imie " << i + 1 << ". gracza" << endl;
		string name;
		cin >> name;
		players[i].setPlayerName(name);
	}
}

void Game::getPlayersNames()
{
	for (int i = 0; i < _numberOfPlayers; i++)
	{
		string name = players[i].getPlayerName();
		cout << "Imie " << i + 1 << ". gracza: " << name << endl;
	}
}

void Game::playGame()
{
	newRound();
}

void Game::addPoints(int numberOfPlayer, int amountOfPoints)
{
	players[numberOfPlayer - 1].addPoints(amountOfPoints);
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
	_round = new Round;
	_round->selectTheRandomLetter();
}

Game::~Game()
{
	delete[] players;
}
