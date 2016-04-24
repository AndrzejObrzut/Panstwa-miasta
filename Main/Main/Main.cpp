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
	int numberOfActualPlayers;
	int numberOfRounds = 0;

	Game *game = new Game(numberOfRounds, numberOfPlayers);

	system("pause");
    return 0;
}

