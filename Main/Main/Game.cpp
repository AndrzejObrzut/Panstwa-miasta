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
		_players[i].setPlayerNumber(i + 1);
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
			_words[i] = _players[i].getWords();
		}

		_result = _round.calculatePoints(_words, _numberOfPlayers);

		for (int i = 0; i < _numberOfPlayers; i++)
		{
			addPoints(i, _result[i]);
		}

		system("cls");
		cout << "\tPanstwo\t|\tMiasto\t|\tRzecz\t|\tRoslina" << endl;
		
		for (int j = 0; j < _numberOfPlayers; j++)
		{
			cout << "GRACZ " << j + 1 << ": ";
			for (int i = 0; i < 4; i++)
			{
				cout << _words[j][i] << "   |   ";
			}
			cout << endl;
		}
		
		for (int i = 0; i < _numberOfPlayers; i++)
		{
			cout << "Gracz nr " << i + 1 << " posiada " << _players[i].getPoints() << " punktow" << endl;
		}
		

		/*
		Po zakoñczeniu rund wszystkich graczy pytamy czy kontynuowac gre.
		Je¿eli naciœniemy 'y' zostaje wylosowana nowa litera i gracze zaczynaja nowa runde.
		Po wyjœciu z gry trzeba bedzie wyswietlic zwyciezce i punkty wszystkich graczy.
		*/
		
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


	system("cls");
	Player * temporaryPlayers = new Player[_numberOfPlayers];


	for (int i = 0; i < _numberOfPlayers; i++)
	{
		temporaryPlayers[i] = _players[i];
	}

	bool continueLoop = true;
	do
	{
		continueLoop = false;
		for (int i = 1; i < _numberOfPlayers; i++)
		{
			if (temporaryPlayers[i - 1].getPoints() < temporaryPlayers[i].getPoints())
			{
				swap(temporaryPlayers[i - 1], temporaryPlayers[i]);
				continueLoop = true;
			}
		}
	} while (continueLoop);





	int place = 0;

	if (temporaryPlayers[0].getPoints() != temporaryPlayers[1].getPoints())
	{
		place++;
		cout << "Wygaral gracz nr " << temporaryPlayers[0].getPlayerNumber() << ". (" << temporaryPlayers[0].getPlayerName() << "). Ilosc punktow " << temporaryPlayers[0].getPoints() << ". Gratulacje :)" << endl;
	}
	else
	{
		cout << "Mamy remis!" << endl;
		cout << "Wygarali:" << endl;
		cout << "gracz nr " << temporaryPlayers[0].getPlayerNumber() << ". (" << temporaryPlayers[0].getPlayerName() << "). Ilosc punktow " << temporaryPlayers[0].getPoints() << endl;
		
		bool inLoop = true;
		int i = 1;
		do 
		{
			place++;
			inLoop = false;
			if (temporaryPlayers[i].getPoints() == temporaryPlayers[i - 1].getPoints())
			{
				cout << "gracz nr " << temporaryPlayers[i].getPlayerNumber() << ". (" << temporaryPlayers[i].getPlayerName() << "). Ilosc punktow " << temporaryPlayers[i].getPoints() << endl;
				inLoop = true;
			}
			i++;
		} while (inLoop);
		cout << "Gratulacje :)" << endl;
	}

	for (int i = place; i < _numberOfPlayers - 1; i++)
	{
		if (temporaryPlayers[i].getPoints() == temporaryPlayers[i + 1].getPoints() || temporaryPlayers[i].getPoints() == temporaryPlayers[i - 1].getPoints())
		{
			cout << place + 1 << ". miejsce zajal ex aequo gracz nr " << temporaryPlayers[i].getPlayerNumber() << ". (" << temporaryPlayers[i].getPlayerName() << "). Ilosc punktow " << temporaryPlayers[i].getPoints() << endl;
		}
		else
		{
			cout << i + 1 << ". miejsce zajal gracz nr " << temporaryPlayers[i].getPlayerNumber() << ". (" << temporaryPlayers[i].getPlayerName() << "). Ilosc punktow " << temporaryPlayers[i].getPoints() << endl;
			place = i + 1;
		}
	}	

	if (temporaryPlayers[_numberOfPlayers - 1].getPoints() != temporaryPlayers[0].getPoints())
	{
		if (temporaryPlayers[_numberOfPlayers - 1].getPoints() == temporaryPlayers[_numberOfPlayers - 2].getPoints())
		{
			cout << place + 1 << ". miejsce zajal ex aequo gracz nr " << temporaryPlayers[_numberOfPlayers - 1].getPlayerNumber() << ". (" << temporaryPlayers[_numberOfPlayers - 1].getPlayerName() << "). Ilosc punktow " << temporaryPlayers[_numberOfPlayers - 1].getPoints() << endl;
		}
		else
		{
			cout << _numberOfPlayers << ". miejsce zajal gracz nr " << temporaryPlayers[_numberOfPlayers - 1].getPlayerNumber() << ". (" << temporaryPlayers[_numberOfPlayers - 1].getPlayerName() << "). Ilosc punktow " << temporaryPlayers[_numberOfPlayers - 1].getPoints() << endl;
		}
	}

	_getch();

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
	delete _result;
	delete _words;
}
