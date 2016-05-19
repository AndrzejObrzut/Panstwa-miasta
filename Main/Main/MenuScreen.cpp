#include "stdafx.h"

#include <iostream>
#include "MenuScreen.h"
#include "ButtonView.h"
#include "Game.h"


MenuScreen::MenuScreen()
{
}


MenuScreen::~MenuScreen()
{
}


int MenuScreen::Run(sf::RenderWindow &App, Game &game)
{
	sf::Event event;
	bool running = true;

	sf::Font font;
	if (!font.loadFromFile("fonts/arial.ttf")) 
	{ 
		std::cerr << "Problem with loading fonts" << std::endl; 
	}

	const float MENU_LABEL_SCREEN_POS_X = 0.50;
	const float MENU_LABEL_SCREEN_POS_Y = 0.30;
	int windowWidth = App.getSize().x;
	int windowHeight = App.getSize().y;

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


	sf::String exitButtonPath("image/ExitButton.png");
	const float EXIT_BUTTON_SCREEN_POS_X = 0.50;
	const float EXIT_BUTTON_SCREEN_POS_Y = 0.75;
	ButtonView exitButton(exitButtonPath, exitButtonPath, false);
	float exitButtonWidth = exitButton.getGlobalBounds().width;
	float exitButtonHeight = exitButton.getGlobalBounds().height;
	float exitButtonPosX = windowWidth * EXIT_BUTTON_SCREEN_POS_X - exitButtonWidth * 0.5;
	float exitButtonnPosY = windowHeight * EXIT_BUTTON_SCREEN_POS_Y - exitButtonHeight * 0.5;
	exitButton.setPosition(sf::Vector2f(exitButtonPosX, exitButtonnPosY));



	while (running)
	{
		while (App.pollEvent(event))
		{
			sf::Mouse mouse;
			sf::Vector2i mousePos = mouse.getPosition(App);

			switch (event.type)
			{
			case  sf::Event::Closed:
				App.close();
				break;
			case  sf::Event::MouseMoved:
				if (singlePlayerButton.isButtonHoverd(mousePos) && mouse.isButtonPressed(sf::Mouse::Left))
				{
					//singlePlayerButton.setHidde(true);
					std::cout << "SINGLE " << singlePlayerButton.isHidden() << std::endl;
					return (1);
				}
				if (exitButton.isButtonHoverd(mousePos) && mouse.isButtonPressed(sf::Mouse::Left))
				{
					std::cout << "Exit" << std::endl;
					return (-1);
				}
			default:
				break;
			}

		}

		App.clear(sf::Color(56, 134, 185, 255));

		App.draw(singlePlayerButton);
		App.draw(menuLabel);
		App.draw(exitButton);

		App.display();
	}
	return (-1);
}