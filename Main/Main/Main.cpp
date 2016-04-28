// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Round.h"

int main()
{
	srand(time(NULL));
	int numberOfPlayers = 0;
	int numberOfActualPlayers = 0;
	int numberOfRounds = 0;

	cout << "Ile graczy bierze udzial w rozgrywce?" << endl;
	cin >> numberOfPlayers;
	
	Game game;
	game.createPlayers(numberOfPlayers);
	game.setPlayersNames();
	game.getPlayersNames();

	game.playGame();




	system("pause");
    return 0;
}

