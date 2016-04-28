#pragma once
#include <iostream>
#include "Round.h"
#include "Player.h"
using namespace std;

class Game
{
private:
	int _numberOfPlayers;
	int _numberOfActualRound;
	int _numberOfRounds;
//	Player _player[];
	Round _round;

public:
	Game(int numberOfPlayers);
	Game(int numberOfRounds, int numberOfPlayers);
	void playGame();
	void endGame();
	void setNumberOfRounds(int number);
	int getNumberOfRounds();
	void newRound();
	~Game();

};