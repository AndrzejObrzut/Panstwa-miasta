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
	string *_words;
	int _numberOfPlayers;

public:
	Round();
	char selectTheRandomLetter();
	void waitingForPlayer(int number, string name);
	void endTheRound();
	void checkWords();
	void calculateAPoints(string * words, int numberOfPLayers);
	void addPoints();
	~Round();
};

