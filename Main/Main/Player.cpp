#include "stdafx.h"
#include "Player.h"


void Player::menuOfWords(int number)
{
	switch (number)
	{
	case 1:

		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	default:
		break;
	}
}

Player::Player()
{
}

void Player::setPlayerNumber(int number)
{
	_playerNumber = number;
}

int Player::getPlayerNumber()
{
	return _playerNumber;
}

void Player::setPlayerName(string name)
{
	_playerName = name;
}

string Player::getPlayerName()
{
	return _playerName;
}

void Player::playRound(char character)
{
	cout << "Litera : " << character << endl;
	cout << "1. Panstwo : " << wordsOfPLayer.getCountry << endl;
	cout << "2. Miasto : " << wordsOfPLayer.getCity << endl;
	cout << "1. Rzecz : " << wordsOfPLayer.getThing << endl;
	cout << "1. Roslina : " << wordsOfPLayer.getPlant << endl;
}

void Player::addPoints(int amountOfPoints)
{
	_amountOfPoints += amountOfPoints;
}

int Player::checkAmountOfPoints()
{
	return _amountOfPoints;
}


Player::~Player()
{
}
