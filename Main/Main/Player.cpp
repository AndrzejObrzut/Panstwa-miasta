#include "stdafx.h"
#include "Player.h"


void Player::menuOfWords(char number)
{
	string word = "";
	switch (number)
	{
	case '1':
		system("cls");
		cout << "Litera : " << _character << endl;
		cout << "Wpisz panstwo" << endl;
		cin >> word;
		wordsOfPLayer.setCountry(word);
		playRound(_character);
		break;
	case '2':
		system("cls");
		cout << "Litera : " << _character << endl;
		cout << "Wpisz miasto" << endl;
		cin >> word;
		wordsOfPLayer.setCity(word);
		playRound(_character);
		break;
	case '3':
		system("cls");
		cout << "Litera : " << _character << endl;
		cout << "Wpisz rzecz" << endl;
		cin >> word;
		wordsOfPLayer.setThing(word);
		playRound(_character);
		break;
	case '4':
		system("cls");
		cout << "Litera : " << _character << endl;
		cout << "Wpisz rosline" << endl;
		cin >> word;
		wordsOfPLayer.setPlant(word);
		playRound(_character);
		break;
	case '5':
		break;
	default:
		playRound(_character);
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
	_character = character;
	system("cls");
	cout << "Litera : " << _character << endl;
	cout << "1. Panstwo : " << wordsOfPLayer.getCountry() << endl;
	cout << "2. Miasto : " << wordsOfPLayer.getCity() << endl;
	cout << "3. Rzecz : " << wordsOfPLayer.getThing() << endl;
	cout << "4. Roslina : " << wordsOfPLayer.getPlant() << endl;
	cout << "5. Zakoncz" << endl;
	cout << "Wpisz numer opcji" << endl;
	char option;
	option = _getch();
	menuOfWords(option);
}

string * Player::getWords()
{
	_words[0] = wordsOfPLayer.getCountry();
	_words[1] = wordsOfPLayer.getCity();
	_words[2] = wordsOfPLayer.getThing();
	_words[3] = wordsOfPLayer.getPlant();
	return &_words[0];
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
