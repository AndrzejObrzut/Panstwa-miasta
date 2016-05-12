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
	int _whichPlayer;
	char _character;
	vector <char> _characters;
	string **_words;
	int _numberOfPlayers;
	int *_result;

public:
	Round();
	char selectTheRandomLetter();
	void waitingForPlayer(const int &number,const string &name) const;
	void checkWords() const;
	int * calculatePoints(string ** words, const int &numberOfPlayers);
	void addPoints(const int &points,const int &numberOfPlayer) const;
	~Round();
};

