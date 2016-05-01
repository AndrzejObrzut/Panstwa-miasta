#pragma once
#include "Round.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Game
{
private:
	int _numberOfPlayers;
	int _numberOfActualRound;
	int _numberOfRounds;
	char _character;
	Player *_players;
	Round _round;
	string *_words;

public:
	Game();
	Game(int numberOfRounds, int numberOfPlayers);
	void createPlayers(int numberOfPlayers);
	void setPlayersNames();
	void getPlayersNames();
	void playGame();
	void addPoints(int numberOfPlayer, int amountOfPoints);
	void endGame();
	void setNumberOfRounds(int number);
	int getNumberOfRounds();
	~Game();

};