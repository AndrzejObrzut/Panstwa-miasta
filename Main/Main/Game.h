#pragma once
#include <iostream>
#include "Round.h"
#include "Player.h"
#include <vector>

using namespace std;

class Game
{
private:
	int _numberOfPlayers;
	int _numberOfActualRound;
	int _numberOfRounds;
	char _character;
	vector <char> _characters;
	Player *_players;
	Round *_round;

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
	void newRound();
	~Game();

};