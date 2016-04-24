#pragma once
#include <string>
using namespace std;

class Game
{
private:
	int _numberOfPlayers;
	int _numberOfActualRound;
	int _numberOfRounds;
//	Round *round = new Round();
//	Player _player[];

public:
	Game(int numberOfRounds, int numberOfPlayers);
	void endGame();
	void setNumberOfRounds(int number);
	int getNumberOfRounds();
	~Game();

};