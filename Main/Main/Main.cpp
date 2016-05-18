// Main.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "cScreen.h"
#include "MenuScreen.h"

using namespace std;

int main()
{
	std::vector<cScreen*> Screens;
	int screen = 0;


	int windowWidth = 1024;
	int windowHeight = 768;
	sf::String title("Panstwa Miasta");
	sf::VideoMode size(windowWidth, windowHeight);
	sf::RenderWindow App(size, title);

	MenuScreen menu;
	Screens.push_back(&menu);

	while (screen >= 0) 
	{
		screen = Screens[screen]->Run(App);
	}


	return EXIT_SUCCESS;
}

