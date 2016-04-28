#include "stdafx.h"
#include "Player.h"


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

void Player::addPoints(int amountOfPoints)
{
	_amountOfPoints = amountOfPoints;
}

int Player::checkAmountOfPoints()
{
	return _amountOfPoints;
}


Player::~Player()
{
}
