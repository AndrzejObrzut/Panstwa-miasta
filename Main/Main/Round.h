#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <conio.h>

using namespace std;

class Round
{
private:
	int _duration;
	int *_points;
	int _whichPlayer;
	char _character;
	std::vector <char> _characters;

public:
	Round();
	char selectTheRandomLetter();
	void waitingForPlayer(int number, string name);
	void endTheRound();
	void checkWords();
	void calculateAPoints();
	void addPoints();
	~Round();
};

