// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Game.h"

int main()
{

	Game *firstGame = new Game("Panstwa-miasta", "Gra polega na wypisywaniu wyraz�w zaczynaj�cych si� na podan� liter�");

	string fullInformations = firstGame->DisplayValues();
	
	cout << fullInformations << endl;
	system("pause");
    return 0;
}

