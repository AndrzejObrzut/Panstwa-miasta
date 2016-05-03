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
	vector <string> _word;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < _numberOfPlayers; j++)
		{
			_word.push_back(_words[i][j]);
		}
		for (int j = 0; j < _numberOfPlayers; j++)
		{
			if (_words[i][j] == "")
			{
				addPoints(0,j);
			}
			else
			{
				bool equal = false;
				for (int k = 0; k < _numberOfPlayers; k++)
				{
					if (_words[i][j] == _word[k])
					{
						equal = true;
					}
				}
				if (equal == true)
				{
					addPoints(10,j);
				}
				else
				{
					addPoints(5,j);
				}
			}
		}
		_word.clear;
	}
}

int * Round::calculatePoints(string ** words, int numberOfPlayers)
{
	_result = new int[_numberOfPlayers];
	_result = 0;
	_numberOfPlayers = numberOfPlayers;
	_words = new string*[numberOfPlayers];
	for (int i = 0; i < numberOfPlayers; i++)
	{
		_words[i] = words[i];
	}
	cout << "calculatePoints" << _words[0][0];
	checkWords();
	
	//_getch();
	return _result;
}

void Round::addPoints(int points, int numberOfPlayer)
{
	_result[numberOfPlayer] += points;
}




Round::~Round()
{
}
