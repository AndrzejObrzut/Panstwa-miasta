#include "stdafx.h"
#include "ChoosePlayerScreen.h"
#include "ButtonView.h"


ChoosePlayerScreen::ChoosePlayerScreen()
{
}


ChoosePlayerScreen::~ChoosePlayerScreen()
{
}

int ChoosePlayerScreen::Run(sf::RenderWindow & App)
{
	sf::Event event;
	bool running = true;
	int windowWidth = App.getSize().x;
	int windowHeight = App.getSize().y;

	const float BACK_MENU_BUTTON_POS_X = 0.08;
	const float BACK_MENU_BUTTON_POS_Y = 0.10;
	sf::String backToMenuButtonPath("image/MenuButton.png");
	sf::String backToMenuHoverButtonPath("image/MenuButtonShadow.png");
	ButtonView backToMenuButton(backToMenuButtonPath, backToMenuHoverButtonPath, false);
	float backToMenuButtonWidth = backToMenuButton.getGlobalBounds().width;
	float backToMenuButtonHeight = backToMenuButton.getGlobalBounds().height;
	float backToMenuButtonPosX = windowWidth * BACK_MENU_BUTTON_POS_X - backToMenuButtonWidth * 0.5;
	float backToMenuButtonPosY = windowHeight * BACK_MENU_BUTTON_POS_Y - backToMenuButtonHeight * 0.5;
	backToMenuButton.setPosition(sf::Vector2f(backToMenuButtonPosX, backToMenuButtonPosY));


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
				if (backToMenuButton.isButtonHoverd(mousePos) && mouse.isButtonPressed(sf::Mouse::Left))
				{
					std::cout << "Back to menu" << std::endl;
					return (0);
				}
			}
		}
		App.clear(sf::Color(56, 134, 185, 255));

		App.draw(backToMenuButton);
		App.display();
	}
	return (-1);
}
