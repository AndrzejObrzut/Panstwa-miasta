// Main.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Menu.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "ButtonView.h"


using namespace std;

int main()
{
	srand(time(NULL));


	//Menu menu;
	//bool option = menu.runMenu();
	//if (option == false) {
	//	return 0;
	//}
	//else {
	//	menu.runMenu();
	//}

	int windowWidth = 1024;
	int windowHeight = 768;
	sf::String title("Panstwa Miasta");
	sf::VideoMode size(windowWidth, windowHeight);
	sf::RenderWindow window(size, title);
	window.clear(sf::Color(56, 134, 185, 255));

	sf::String singlePlayerButtonPath("image/SinglePlayer.png");
	sf::String singlePlayerButtonClickedPath("image/SinglePlayer.png");


	const float SINGLE_BUTTON_SCREEN_POS_X = 0.50;
	const float SINGLE_BUTTON_SCREEN_POS_Y = 0.60;
	ButtonView singlePlayerButton(singlePlayerButtonPath, singlePlayerButtonClickedPath, true);
	float singleButtonWidth = singlePlayerButton.getGlobalBounds().width;
	float singleButtonHeight = singlePlayerButton.getGlobalBounds().height;
	float singlePlayerButtonPosX = windowWidth * SINGLE_BUTTON_SCREEN_POS_X - singleButtonWidth * 0.5;
	float singlePlayerButtonPosY = windowHeight * SINGLE_BUTTON_SCREEN_POS_Y - singleButtonHeight * 0.5;
	singlePlayerButton.setPosition(sf::Vector2f(singlePlayerButtonPosX, singlePlayerButtonPosY));

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.draw(singlePlayerButton);
		window.display();
	}

	system("pause");
    return 0;
}

