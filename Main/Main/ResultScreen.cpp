#include "stdafx.h"
#include "ResultScreen.h"
#include "ButtonView.h"


ResultScreen::ResultScreen()
{
}


ResultScreen::~ResultScreen()
{
}


int ResultScreen::Run(sf::RenderWindow &App, Game &game)
{
	//sf::Event event;
	//bool running = true;

	//sf::Font font;
	//if (!font.loadFromFile("fonts/arial.ttf"))
	//	std::cerr << "Problem with loading fonts" << std::endl;


	//const float BACK_MENU_BUTTON_POS_X = 0.3;
	//const float BACK_MENU_BUTTON_POS_Y = 0.8;
	//const float NEXT_BUTTON_POS_X = 0.7;
	//const float NEXT_BUTTON_POS_Y = 0.8;

	//sf::String backToMenuButtonPath("image/MenuButton.png");
	//sf::String backToMenuHoverButtonPath("image/MenuButtonShadow.png");
	//ButtonView backToMenuButton(backToMenuButtonPath, backToMenuHoverButtonPath, false);
	//float backToMenuButtonWidth = backToMenuButton.getGlobalBounds().width;
	//float backToMenuButtonHeight = backToMenuButton.getGlobalBounds().height;
	//float backToMenuButtonPosX = windowWidth * BACK_MENU_BUTTON_POS_X - backToMenuButtonWidth * 0.5;
	//float backToMenuButtonPosY = windowHeight * BACK_MENU_BUTTON_POS_Y - backToMenuButtonHeight * 0.5;
	//backToMenuButton.setPosition(sf::Vector2f(backToMenuButtonPosX, backToMenuButtonPosY));

	//sf::String nextButtonPath("image/Accept.png");
	//sf::String nextHoverButtonPath("image/AcceptShadow.png");
	//ButtonView nextButton(nextButtonPath, nextHoverButtonPath, false);
	//float nextButtonWidth = nextButton.getGlobalBounds().width;
	//float nextButtonHeight = nextButton.getGlobalBounds().height;
	//float nextButtonPosX = windowWidth * NEXT_BUTTON_POS_X - nextButtonWidth * 0.5;
	//float nextButtonPosY = windowHeight * NEXT_BUTTON_POS_Y - nextButtonHeight * 0.5;
	//nextButton.setPosition(sf::Vector2f(nextButtonPosX, nextButtonPosY));

	//const float RESULT_TEXT_POS_X = 0.5;
	//const float RESULT_TEXT_POS_Y = 0.05;

	//std::string resultText = "Wyniki graczy";
	//sf::Text resultLabel(resultText, font, 35);
	//resultLabel.setColor(sf::Color::White);
	//float resultLabelPosX = windowWidth * RESULT_TEXT_POS_X - resultLabel.getGlobalBounds().width * 0.5;
	//float resultLabelPosY = windowWidth * RESULT_TEXT_POS_Y - resultLabel.getGlobalBounds().height * 0.5;
	//resultLabel.setPosition(resultLabelPosX, resultLabelPosY);
	//
	//
	//cout << "Result Screen" << endl;
	//while (running)
	//{
	//	cout << "Result Screen  1" << endl;

	//	while (App.pollEvent(event))
	//	{
	//		sf::Mouse mouse;
	//		sf::Vector2i mousePos = mouse.getPosition(App);


	//		switch (event.type)
	//		{
	//		case  sf::Event::Closed:
	//			App.close();
	//			break;
	//		case  sf::Event::MouseMoved:
	//			if (backToMenuButton.isButtonHoverd(mousePos) && mouse.isButtonPressed(sf::Mouse::Left)) { return (0); }

	//			break;
	//		default:
	//			break;
	//		}

	//	}

	//	App.clear(sf::Color(56, 134, 185, 255));
	//	App.draw(resultLabel);
	//	App.draw(backToMenuButton);
	//	App.draw(nextButton);
	//	App.display();
	//	cout << "TEST" << endl;
	//}
	//return (-1);
	windowWidth = App.getSize().x;
	windowHeight = App.getSize().y;

	sf::Event event;
	bool running = true;

	sf::Font font;
	if (!font.loadFromFile("fonts/arial.ttf"))
		std::cerr << "Problem with loading fonts" << std::endl;

	const float MENU_LABEL_SCREEN_POS_X = 0.50;
	const float MENU_LABEL_SCREEN_POS_Y = 0.10;

	sf::Text menuLabel("Wyniki", font);
	menuLabel.setCharacterSize(60);
	menuLabel.setColor(sf::Color::White);
	float menuLabelPosX = windowWidth * MENU_LABEL_SCREEN_POS_X - menuLabel.getGlobalBounds().width * 0.5;
	float menuLabelPosY = windowHeight * MENU_LABEL_SCREEN_POS_Y - menuLabel.getGlobalBounds().height * 0.5;
	menuLabel.setPosition(sf::Vector2f(menuLabelPosX, menuLabelPosY));


	const float NEXT_ROUND_BUTTON_SCREEN_POS_X = 0.65;
	const float NEXT_ROUND_BUTTON_SCREEN_POS_Y = 0.90;
	sf::String nextRoundButtonPath("image/Accept.png");
	sf::String nextRoundButtonHoverPath("image/AcceptShadow.png");
	ButtonView nextRoundButton(nextRoundButtonPath, nextRoundButtonHoverPath, false);
	float nextRoundButtonWidth = nextRoundButton.getGlobalBounds().width;
	float nextRoundButtonHeight = nextRoundButton.getGlobalBounds().height;
	float nextRoundButtonPosX = windowWidth * NEXT_ROUND_BUTTON_SCREEN_POS_X - nextRoundButtonWidth * 0.5;
	float nextRoundButtonPosY = windowHeight * NEXT_ROUND_BUTTON_SCREEN_POS_Y - nextRoundButtonHeight * 0.5;
	nextRoundButton.setPosition(sf::Vector2f(nextRoundButtonPosX, nextRoundButtonPosY));

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

	
	const float NO_BUTTON_POS_X = 0.35;
	const float NO_BUTTON_POS_Y = 0.9;
	sf::String noButtonPath("image/ExitButton.png");
	ButtonView noButton(noButtonPath, noButtonPath, false);
	float noButtonWidth = noButton.getGlobalBounds().width;
	float noButtonHeight = noButton.getGlobalBounds().height;
	float noButtonPosX = windowWidth * NO_BUTTON_POS_X - noButtonWidth * 0.5;
	float noButtonPosY = windowHeight * NO_BUTTON_POS_Y - noButtonHeight * 0.5;
	noButton.setPosition(sf::Vector2f(noButtonPosX, noButtonPosY));


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
				if (nextRoundButton.isButtonHoverd(mousePos) && mouse.isButtonPressed(sf::Mouse::Left)) { return (2); }

				if (backToMenuButton.isButtonHoverd(mousePos) && mouse.isButtonPressed(sf::Mouse::Left)) { return (0); }
				if (noButton.isButtonHoverd(mousePos) && mouse.isButtonPressed(sf::Mouse::Left)) { return (0); }


			default:
				break;
			}

		}

		App.clear(sf::Color(56, 134, 185, 255));

		App.draw(nextRoundButton);
		App.draw(backToMenuButton);
		App.draw(noButton);
		App.draw(menuLabel);

		App.display();
	}
	return (-1);
}