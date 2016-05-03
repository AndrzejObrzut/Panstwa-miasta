#include "stdafx.h"
#include "Game.h"


Game::Game()
{
}

Game::Game(int numberOfRounds, int numberOfPlayers) : _numberOfRounds(numberOfRounds), _numberOfPlayers(numberOfPlayers)
{
}

void Game::createPlayers(int numberOfPlayers)
{
	_numberOfPlayers = numberOfPlayers;
	_players = new Player[_numberOfPlayers];
	_words = new string*[_numberOfPlayers];
	_result = new int[_numberOfPlayers];
}

void Game::setPlayersNames()
{
	for (int i = 0; i < _numberOfPlayers; i++)
	{
		cout << "Podaj imie " << i + 1 << ". gracza" << endl;
		string name;
		cin >> name;
		_players[i].setPlayerName(name);
	}
}

void Game::getPlayersNames()
{
	for (int i = 0; i < _numberOfPlayers; i++)
	{
		string name = _players[i].getPlayerName();
		cout << "Imie " << i + 1 << ". gracza: " << name << endl;
	}
}

void Game::playGame()
{
	cout << "Nowa runda" << endl;
	bool continueGame = true;

	do
	{
		/*
		Klasa "Game" zawiera zmienna "_round".
		Myœlê, ¿e wystarczy nam jeden obiekt i dzi³anie na nim, 
		a nie wywo³ywanie za ka¿dym razem przy nowej rundzie "new Round".
		Poza tym klasa "Game" posiada tablicê graczy, na których dzia³amy 
		przez ca³¹ grê.
		*/
		/*
		Zmienna _character przechowuje niepowtarzaln¹ wylosowan¹ literê.
		*/
		_character = _round.selectTheRandomLetter();
		/*
		Myœlê, ¿e to bêdzie g³ówna pêtla programu.
		Ta poni¿ej.
		Najpierw wywo³ujemy gracza i czekamy a¿ naciœnie przysik.
		Nastêpnie wyœwietlamy mu litere i wyrazy jakie ma wpisywaæ (pañstwa, miasta...)
		Nastêpnie jak skoñczy to wczytuje siê nastêpny gracz.
		*/
		for (int i = 0; i < _numberOfPlayers; i++)
		{
			cout << "i= " << i << endl;
			_round.waitingForPlayer(i, _players[i].getPlayerName());
			_players[i].playRound(_character);
			//string * pointer = _players[i].getWords();
			//cout << "pointer1 " << pointer[0];
			//cout << "pointer2 " << pointer[1];
			//cout << "pointer3 " << pointer[2];
			//cout << "pointer4 " << pointer[3];
			//_getch();
			/*
			Tu bêd¹ nastêpne funkcjonalnoœci
			*/
		}

		for (int i = 0; i < _numberOfPlayers; i++)
		{
			cout << "in for " << i << endl;
			_words[i] = _players[i].getWords();
		}

		_result = _round.calculatePoints(_words, _numberOfPlayers);

		for (int i = 0; i < _numberOfPlayers; i++)
		{
			addPoints(i, _result[i]);
		}

		/*
		Po zakoñczeniu rund wszystkich graczy pytamy czy kontynuowac gre.
		Je¿eli naciœniemy 'y' zostaje wylosowana nowa litera i gracze zaczynaja nowa runde.
		Po wyjœciu z gry trzeba bedzie wyswietlic zwyciezce i punkty wszystkich graczy.
		*/
		system("cls");
		cout << "Kontynuowac gre? <y/n>" << endl;
		char choose;
		do
		{
			choose = _getch();
		} 
		while ((choose != 'y') && (choose != 'n'));

		if (choose == 'y')
		{
			continueGame = true;
		}
		else
		{
			continueGame = false;
		}
	} while (continueGame);
}

void Game::addPoints(int numberOfPlayer, int amountOfPoints)
{
	_players[numberOfPlayer].addPoints(amountOfPoints);
}

void Game::endGame()
{
}

void Game::setNumberOfRounds(int number)
{
	_numberOfRounds = number;
}

int Game::getNumberOfRounds()
{
	return _numberOfRounds;
}


Game::~Game()
{
	delete[] _players;
}
