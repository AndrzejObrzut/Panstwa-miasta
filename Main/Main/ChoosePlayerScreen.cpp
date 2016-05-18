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

	sf::Font font;
	if (!font.loadFromFile("fonts/arial.ttf"))
	{
		std::cerr << "Problem with loading fonts" << std::endl;
	}

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

	std::string firstName;
	sf::Text firstNameTextField(firstName, font, 35);
	firstNameTextField.setColor(sf::Color(255, 255, 255, 255));
	firstNameTextField.setPosition(sf::Vector2f(windowWidth * 0.20 - firstNameTextField.getGlobalBounds().width * 0.5 , windowHeight * 0.20 - firstNameTextField.getGlobalBounds().height
		* 0.5));


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
			case sf::Event::MouseMoved:

				if (backToMenuButton.isButtonHoverd(mousePos) && mouse.isButtonPressed(sf::Mouse::Left))
				{
					std::cout << "Back to menu" << std::endl;
					return (0);
				}
				break;
			case sf::Event::TextEntered:
				if (event.text.unicode >= 32 && event.text.unicode < 126)
				{
					firstName += (char)event.text.unicode;
				}
				else if (event.text.unicode == 8 && firstName.size() > 0) 
				{
					firstName = firstName.substr(0, firstName.length() - 1);
				}
				firstNameTextField.setString(firstName);
				break;
			default:
				break;
			}

		}
		App.clear(sf::Color(56, 134, 185, 255));

		App.draw(backToMenuButton);
		App.draw(firstNameTextField);
		App.display();
	}
	return (-1);
}
