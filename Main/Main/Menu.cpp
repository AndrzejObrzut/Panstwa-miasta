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

void Menu::runMenu() {


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

	
}

void Menu::choseMenuOption(MenuOptions::Option option) {

}

void Menu::runLocalGame() {
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

}
