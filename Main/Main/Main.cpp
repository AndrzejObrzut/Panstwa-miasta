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
	//srand(time(NULL));


	//Menu menu;
	//bool option = menu.runMenu();
	//if (option == false) {
	//	return 0;
	//}
	//else {
	//	menu.runMenu();
	//}

	// WINDOW OF GAME
	int windowWidth = 1024;
	int windowHeight = 768;
	sf::String title("Panstwa Miasta");
	sf::VideoMode size(windowWidth, windowHeight);
	sf::RenderWindow window(size, title);
	window.clear(sf::Color(56, 134, 185, 255));


	// MENU CONTROLLER
	sf::Font font;
	if (!font.loadFromFile("fonts/arial.ttf")) { cout << "Problem with loading fonts"; }

	const float MENU_LABEL_SCREEN_POS_X = 0.50;
	const float MENU_LABEL_SCREEN_POS_Y = 0.30;

	sf::Text menuLabel("Panstwa Miasta", font);
	menuLabel.setCharacterSize(60);
	menuLabel.setColor(sf::Color::White);
	float menuLabelPosX = windowWidth * MENU_LABEL_SCREEN_POS_X - menuLabel.getGlobalBounds().width * 0.5;
	float menuLabelPosY = windowHeight * MENU_LABEL_SCREEN_POS_Y - menuLabel.getGlobalBounds().height * 0.5;
	menuLabel.setPosition(sf::Vector2f(menuLabelPosX, menuLabelPosY));

	sf::String singlePlayerButtonPath("image/SinglePlayer.png");
	sf::String singlePlayerButtonHoverPath("image/SinglePlayerButtonShadow.png");
	const float SINGLE_BUTTON_SCREEN_POS_X = 0.50;
	const float SINGLE_BUTTON_SCREEN_POS_Y = 0.60;
	ButtonView singlePlayerButton(singlePlayerButtonPath, singlePlayerButtonHoverPath, false);
	float singleButtonWidth = singlePlayerButton.getGlobalBounds().width;
	float singleButtonHeight = singlePlayerButton.getGlobalBounds().height;
	float singlePlayerButtonPosX = windowWidth * SINGLE_BUTTON_SCREEN_POS_X - singleButtonWidth * 0.5;
	float singlePlayerButtonPosY = windowHeight * SINGLE_BUTTON_SCREEN_POS_Y - singleButtonHeight * 0.5;
	singlePlayerButton.setPosition(sf::Vector2f(singlePlayerButtonPosX, singlePlayerButtonPosY));

	// SET SINGLE GAME

	sf::String menuButtonPath("image/MenuButton.png");
	sf::String menuButtonHoverPath("image/MenuButtonShadow.png");
	const float MENU_BUTTON_SCREEN_POS_X = 0.10;
	const float MENU_BUTTON_SCREEN_POS_Y = 0.10;
	ButtonView menuButton(menuButtonPath, menuButtonHoverPath, false);
	float menuButtonHeight = menuButton.getGlobalBounds().height;
	float menuButtonWidth = menuButton.getGlobalBounds().width;
	float menuButtonPosX = windowWidth * MENU_BUTTON_SCREEN_POS_X - menuButtonWidth * 0.5;
	float menuButtonPosY = windowHeight * MENU_BUTTON_SCREEN_POS_Y - menuButtonHeight * 0.5;
	menuButton.setPosition(sf::Vector2f(menuButtonPosX, menuButtonPosY));

	std::string textInsert;
	sf::Text text(textInsert, font, 35);
	text.setColor(sf::Color(255, 255, 255, 255));

	// HANDLING ACTIONS
	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::MouseMoved) 
			{
				sf::Mouse mouse;

				sf::Vector2i mousePos = mouse.getPosition(window);
				if (singlePlayerButton.isButtonHoverd(mousePos) && mouse.isButtonPressed(sf::Mouse::Left)) 
				{
					singlePlayerButton.setHidde(true);
					menuButton.setHidde(false);
					cout << "SINGLE " << singlePlayerButton.isHidden() << endl;
				}

				if (menuButton.isButtonHoverd(mousePos) && mouse.isButtonPressed(sf::Mouse::Left))
				{
					menuButton.setHidde(true);
					singlePlayerButton.setHidde(false);
					cout << "Menu button tapped" << endl;
				}
			}
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode >= 32 && event.text.unicode < 126) 
				{
					textInsert += (char)event.text.unicode;
				}
				else if (event.text.unicode == 8 && textInsert.size() > 0)
				{
					textInsert = textInsert.substr(0, textInsert.length() - 1);
				}
				text.setString(textInsert);
			}
		}

		window.clear(sf::Color(56, 134, 185, 255));
		if (!singlePlayerButton.isHidden()) 
		{ 
			window.draw(singlePlayerButton);
			window.draw(menuLabel);
		} 
		else 
		{
			window.draw(text);
			window.draw(menuButton);
		}

		window.display();
	}

	//system("pause");
    return 0;
}

