#include "stdafx.h"

#include <iostream>
#include "MenuScreen.h"
#include "ButtonView.h"


MenuScreen::MenuScreen()
{
	alpha_div = 3;
	alpha_max = 3 * 255;
	playing = false;
}


MenuScreen::~MenuScreen()
{
}

int MenuScreen::Run(sf::RenderWindow &App) 
{
	sf::Event event;
	bool running = true;
	int alpha = 0;
	int menu = 0;

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


	if (playing)
	{
		alpha = alpha_max;
	}

	while (running)
	{
		while (App.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				App.close();
			}
			if (event.type == sf::Event::MouseMoved)
			{
				sf::Mouse mouse;

				sf::Vector2i mousePos = mouse.getPosition(App);
				if (singlePlayerButton.isButtonHoverd(mousePos) && mouse.isButtonPressed(sf::Mouse::Left))
				{
					//singlePlayerButton.setHidde(true);
					std::cout << "SINGLE " << singlePlayerButton.isHidden() << std::endl;
				}
				if (exitButton.isButtonHoverd(mousePos) && mouse.isButtonPressed(sf::Mouse::Left)) 
				{
					std::cout << "Exit" << std::endl;
					return (-1);
				}
			}
		}
		if (alpha < alpha_max)
		{
			alpha++;
		}

		App.clear(sf::Color(56, 134, 185, 255));

		App.draw(singlePlayerButton);
		App.draw(menuLabel);
		App.draw(exitButton);

		App.display();
	}
	return (-1);
}