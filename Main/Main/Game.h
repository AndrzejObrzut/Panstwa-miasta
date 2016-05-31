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
	string **_words;
	int * _result;

public:
	Game();
	Game(const int &numberOfRounds,const int &numberOfPlayers);
	void createPlayers(const int &numberOfPlayers);
	void setPlayersNames();
	void setPlayersNames(vector<string> players);
	void getPlayersNames() const;
	const vector<Player> getPlayers();
	void play();
	void playGame();
	void addPoints(const int &numberOfPlayer,const int &amountOfPoints);
	vector<int> getPointsOfAllPlayers();
	void endGame();
	void setNumberOfRounds(const int &number);
	int getNumberOfRounds() const;
	const char getCharacter();
	const int getPlayersCount();
	~Game();

};