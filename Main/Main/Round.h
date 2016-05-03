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
	vector <char> _characters;
	string **_words;
	int _numberOfPlayers;
	int *_result;

public:
	Round();
	char selectTheRandomLetter();
	void waitingForPlayer(int number, string name);
	void endTheRound();
	void checkWords();
	int * calculatePoints(string ** words, int numberOfPLayers);
	void addPoints(int points, int numberOfPlayer);
	~Round();
};

