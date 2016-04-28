#include "stdafx.h"
#include "Round.h"


Round::Round()
{
}

char Round::selectTheRandomLetter()
{
	int liczba;
	do
	{
		liczba = (std::rand() % 25) + 65;
	} 
	while (liczba == 81 || liczba == 86 || liczba == 88 || liczba == 89);
	_character = (char)liczba;
	std::cout << "Wylosowana litera to: " << _character << std::endl;
	return 0;
}

void Round::endTheRound()
{
}

void Round::checkWords()
{
}

void Round::calculateAPoints()
{
}

void Round::addPoints()
{
}


Round::~Round()
{
}
