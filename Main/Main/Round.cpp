#include "stdafx.h"
#include "Round.h"


Round::Round()
{
}

char Round::selectTheRandomLetter()
{
	bool continueWhile = true;
	bool exitFromFor = false;
	int randomNumber;

	do
	{
		do
		{
			randomNumber = (std::rand() % 26) + 65;
		} 
		while (randomNumber == 81 || randomNumber == 86 || randomNumber == 88 || randomNumber == 89);
		_character = (char)randomNumber;

		exitFromFor = true;

		for (int unsigned i = 0; i < _characters.size(); i++)
		{
			if (_character == _characters[i])
			{
				exitFromFor = false;
			}
		}

		if (exitFromFor == false)
		{
			continueWhile = true;
		}
		else
		{
			_characters.push_back(_character);
			continueWhile = false;
		}
	} while (continueWhile);

	std::cout << "Wylosowana litera to: " << _character << std::endl;
	return _character;
}

void Round::waitingForPlayer(int number, string name)
{
	system("cls");
	cout << "Runda gracza nr " << number + 1 << " (" << name << ")" << endl;
	cout << "Nacisnij dowolny przycisk aby rozpoczac runde!" << endl;
	_getch();
}


void Round::endTheRound()
{
}

void Round::checkWords()
{
}

void Round::calculateAPoints(string * words, int numberOfPLayers)
{
}


void Round::addPoints()
{
}


Round::~Round()
{
}
