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
	_players = new Player[_numberOfPlayers];
}

void Game::setPlayersNames()
{
	for (int i = 0; i < _numberOfPlayers; i++)
	{
		cout << "Podaj imie " << i + 1 << ". gracza" << endl;
		string name;
		cin >> name;
		_players[i].setPlayerName(name);
	}
}

void Game::getPlayersNames()
{
	for (int i = 0; i < _numberOfPlayers; i++)
	{
		string name = _players[i].getPlayerName();
		cout << "Imie " << i + 1 << ". gracza: " << name << endl;
	}
}

void Game::playGame()
{
	newRound();
}

void Game::addPoints(int numberOfPlayer, int amountOfPoints)
{
	_players[numberOfPlayer - 1].addPoints(amountOfPoints);
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
		bool continueWhile = true;
		bool exitFromFor = false;
		cout << "Nowa runda" << endl;
		_round = new Round();
		do
		{
			_character = _round->selectTheRandomLetter();
			exitFromFor = true;

			for (int i = 0; i < _characters.size(); i++)
			{
				if (_character == _characters[i])
				{
					exitFromFor = false;
				}
			}

			if (exitFromFor == false)
			{
				continueWhile = true;
			}
			else
			{
				_characters.push_back(_character);
				continueWhile = false;
			}
		} 
		while (continueWhile);
		std::cout << "Wylosowana litera to: " << _character << std::endl;
}

Game::~Game()
{
	delete[] _players;
}
