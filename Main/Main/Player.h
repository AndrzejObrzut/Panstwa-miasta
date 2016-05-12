#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "WordsOfPlayer.h"

using namespace std;

class Player
{
private:
	int _playerNumber;
	string _playerName;
	int _amountOfPoints = 0;
	char _character;
	WordsOfPlayer _wordsOfPlayer;
	void menuOfWords(char number);
	string _words[4];

public:
	Player();
	Player(const Player &source);
	Player& Player::operator=(const Player &source);
	void setPlayerNumber(const int &number);
	int getPlayerNumber() const;
	void setPlayerName(const string &name);
	string getPlayerName() const;
	void playRound(char character);
	void continuePlayingRound();
	string * getWords();
	void addPoints(int amountOfPoints);
	void setPoints(int points);
	int getPoints() const;
	~Player();
};

