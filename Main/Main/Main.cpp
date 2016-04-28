// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Round.h"

int main()
{
	int numberOfPlayers = 0;
	int numberOfActualPlayers = 0;
	int numberOfRounds = 0;
	Player *players;


	cout << "Ile graczy bierze udzial w rozgrywce?" << endl;
	cin >> numberOfPlayers;
	players = new Player[numberOfPlayers];
	for (int i = 0; i < numberOfPlayers; i++)
	{
		cout << "Podaj imie " << i + 1 << ". gracza" << endl;
		string name;
		cin >> name;
		players[i].setPlayerName(name);
	}

	for (int i = 0; i < numberOfPlayers; i++)
	{
		string name = players[i].getPlayerName();
		cout << "Imie " << i + 1 << ". gracza: " << name << endl;
	}

	Game game(numberOfPlayers);
	game.playGame();

	delete[] players;



	system("pause");
    return 0;
}

