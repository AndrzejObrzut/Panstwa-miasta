#include "stdafx.h"
#include <iostream>
#include "Menu.h"
#include "Game.h"
#include "Player.h"
#include "Round.h"

using namespace std;

Menu::Menu()
{
}


Menu::~Menu()
{
}

bool Menu::runMenu() {


	string gameOption;
	cout << "Witaj w PANSTWA MIASTA" << endl;
	cout << "1. Gra lokalna -> 1 || local" << endl;
	cout << "2. Gra Online -> 2 || online" << endl;
	cout << "3. Wyjscie -> 3 || exit" << endl;
	cin >> gameOption;

	if (gameOption == "1" || gameOption == "local") {
		menuOption = MenuOptions::LocalGame;
	}
	else if (gameOption == "2" || gameOption == "online") {
		menuOption = MenuOptions::OnlineGame;
	}
	else if (gameOption == "3" || gameOption == "exit") {
		menuOption = MenuOptions::Exit;
	}
	else {
		menuOption = MenuOptions::BadRequest;
		cout << "Zla opcja" << endl;
	}

	return choseMenuOption(menuOption);	
}

bool Menu::choseMenuOption(MenuOptions::Option option) {
	
	bool returnOption;
	switch (option) {
	case MenuOptions::LocalGame:
		returnOption = true;
		runLocalGame();
		break;
	case MenuOptions::OnlineGame:
		returnOption = true;
		runOnlineGame();
		break;
	case MenuOptions::Exit:
		returnOption = false;
		break;
	case MenuOptions::BadRequest:
		returnOption = true;
		runMenuAgain();
		break;
	default:
		returnOption = true;
		runMenuAgain();
		break;
	}

	return returnOption;
}

void Menu::runMenuAgain() {
	system("cls");
	cout << "Wybrana zla opcje" << endl;
	runMenu();
}

void Menu::runLocalGame() {
	system("cls");
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
}

void Menu::runOnlineGame() {
	system("cls");
	cout << "Wersja multiplayer w budowie" << endl;
	runMenu(); // to change when online version will be done
}
