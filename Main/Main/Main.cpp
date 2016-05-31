// Main.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "cScreen.h"
#include "MenuScreen.h"
#include "ChoosePlayerScreen.h"
#include "RoundScreen.h"
#include "ResultScreen.h"

using namespace std;

int main()
{

	srand(time(NULL));

	std::vector<cScreen*> Screens;
	int screen = 0;


	int windowWidth = 1024;
	int windowHeight = 768;
	sf::String title("Panstwa Miasta");
	sf::VideoMode size(windowWidth, windowHeight);
	sf::RenderWindow App(size, title);

	MenuScreen menu;
	Screens.push_back(&menu);
	ChoosePlayerScreen choosePlayer;
	Screens.push_back(&choosePlayer);
	RoundScreen roundScreen;
	Screens.push_back(&roundScreen);
	ResultScreen resultScreen;
	Screens.push_back(&resultScreen);

	Game game;

	while (screen >= 0) 
	{
		screen = Screens[screen]->Run(App, game);
	}


	return EXIT_SUCCESS;
}

