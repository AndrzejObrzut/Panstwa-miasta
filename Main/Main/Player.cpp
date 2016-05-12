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
		_wordsOfPlayer.setCountry(word);
		continuePlayingRound();
		break;
	case '2':
		system("cls");
		cout << "Litera : " << _character << endl;
		cout << "Wpisz miasto" << endl;
		cin >> word;
		_wordsOfPlayer.setCity(word);
		continuePlayingRound();
		break;
	case '3':
		system("cls");
		cout << "Litera : " << _character << endl;
		cout << "Wpisz rzecz" << endl;
		cin >> word;
		_wordsOfPlayer.setThing(word);
		continuePlayingRound();
		break;
	case '4':
		system("cls");
		cout << "Litera : " << _character << endl;
		cout << "Wpisz rosline" << endl;
		cin >> word;
		_wordsOfPlayer.setPlant(word);
		continuePlayingRound();
		break;
	case '5':
		break;
	default:
		continuePlayingRound();
		break;
	}
}

Player::Player()
{
}

Player::Player(const Player & source)
{
	_playerNumber = source._playerNumber;
	_playerName = source._playerName;
	_amountOfPoints = source._amountOfPoints;
	_character = source._character;
	_wordsOfPlayer = source._wordsOfPlayer;
	int i = 0;
	for (auto s : _words)
	{
		_words[i] = source._words[i];
		i++;
	}
}

Player & Player::operator=(const Player & source)
{
	if (this != &source)
	{
		_playerNumber = source._playerNumber;
		_playerName = source._playerName;
		_amountOfPoints = source._amountOfPoints;
		_character = source._character;
		_wordsOfPlayer = source._wordsOfPlayer;
		int i = 0;
		for (auto s : _words)
		{
			_words[i] = source._words[i];
			i++;
		}
	}
	return *this;
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
	_wordsOfPlayer.initializeWords();
	_character = character;
	system("cls");
	cout << "Litera : " << _character << endl;
	cout << "1. Panstwo : " << _wordsOfPlayer.getCountry() << endl;
	cout << "2. Miasto : " << _wordsOfPlayer.getCity() << endl;
	cout << "3. Rzecz : " << _wordsOfPlayer.getThing() << endl;
	cout << "4. Roslina : " << _wordsOfPlayer.getPlant() << endl;
	cout << "5. Zakoncz" << endl;
	cout << "Wpisz numer opcji" << endl;
	char option;
	option = _getch();
	menuOfWords(option);
}

void Player::continuePlayingRound()
{
	system("cls");
	cout << "Litera : " << _character << endl;
	cout << "1. Panstwo : " << _wordsOfPlayer.getCountry() << endl;
	cout << "2. Miasto : " << _wordsOfPlayer.getCity() << endl;
	cout << "3. Rzecz : " << _wordsOfPlayer.getThing() << endl;
	cout << "4. Roslina : " << _wordsOfPlayer.getPlant() << endl;
	cout << "5. Zakoncz" << endl;
	cout << "Wpisz numer opcji" << endl;
	char option;
	option = _getch();
	menuOfWords(option);
}

string * Player::getWords()
{
	_words[0] = _wordsOfPlayer.getCountry();
	_words[1] = _wordsOfPlayer.getCity();
	_words[2] = _wordsOfPlayer.getThing();
	_words[3] = _wordsOfPlayer.getPlant();
	return &_words[0];
}


void Player::addPoints(int amountOfPoints)
{
	_amountOfPoints += amountOfPoints;
}

void Player::setPoints(int points)
{
	_amountOfPoints = points;
}

int Player::getPoints()
{
	return _amountOfPoints;
}


Player::~Player()
{
}
