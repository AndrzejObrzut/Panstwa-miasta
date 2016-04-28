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
		liczba = (std::rand() % 26) + 65;
	} 
	while (liczba == 81 || liczba == 86 || liczba == 88 || liczba == 89);
	//std::cout << "Wylosowana litera to: " << (char)liczba << std::endl;
	return (char)liczba;;
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
