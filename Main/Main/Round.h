#pragma once
class Round
{
public:
	char _character;
	int _duration;
	int _points[];
	
	Round();
	char selectTheRandomLetter();
	void endTheRound();
	void checkWords();
	void calculateAPoints();
	void addPoints();
	~Round();
};

