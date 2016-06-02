#include "stdafx.h"
#include "ResultScreen.h"
#include "ButtonView.h"


ResultScreen::ResultScreen() { }

ResultScreen::~ResultScreen() { }

int ResultScreen::Run(sf::RenderWindow &App, Game &game)
{
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

	const float CONTINUE_LABEL_SCREEN_POS_X = 0.5;
	const float CONTINUE_LABEL_SCREEN_POS_Y = 0.8;
	sf::Text continueLabel("Czy chcesz kontynulowac?", font);
	continueLabel.setCharacterSize(35);
	continueLabel.setColor(sf::Color::White);
	float continueLabelPosX = windowWidth * CONTINUE_LABEL_SCREEN_POS_X - continueLabel.getGlobalBounds().width * 0.5;
	float continueLabelPosY = windowHeight * CONTINUE_LABEL_SCREEN_POS_Y - continueLabel.getGlobalBounds().height * 0.5;
	continueLabel.setPosition(sf::Vector2f(continueLabelPosX, continueLabelPosY));

	const float NEXT_ROUND_BUTTON_SCREEN_POS_X = 0.6;
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

	const float NO_BUTTON_POS_X = 0.4;
	const float NO_BUTTON_POS_Y = 0.9;
	sf::String noButtonPath("image/ExitButton.png");
	ButtonView noButton(noButtonPath, noButtonPath, false);
	float noButtonWidth = noButton.getGlobalBounds().width;
	float noButtonHeight = noButton.getGlobalBounds().height;
	float noButtonPosX = windowWidth * NO_BUTTON_POS_X - noButtonWidth * 0.5;
	float noButtonPosY = windowHeight * NO_BUTTON_POS_Y - noButtonHeight * 0.5;
	noButton.setPosition(sf::Vector2f(noButtonPosX, noButtonPosY));

	vector<Player> allPlayers = game.getPlayers();
	vector<int> currentRoundPoints = game.getPointsOfAllPlayers();

	float NAMES_POS_X = 0.2;
	float CURRENT_POINTS_POS_X = 0.5;
	float ALL_POINTS_POS_X = 0.7;
	float LABELS_POS_Y = 0.2;
	
	sf::Text nameLabel("", font);
	nameLabel.setCharacterSize(35);
	nameLabel.setColor(sf::Color::White);

	sf::Text currentPointsLabel("", font);
	currentPointsLabel.setCharacterSize(35);
	currentPointsLabel.setColor(sf::Color::White);

	sf::Text allPointsLabel("", font);
	allPointsLabel.setCharacterSize(35);
	allPointsLabel.setColor(sf::Color::White);

	bool isDisplayed = false;

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
		if (!isDisplayed) {
			isDisplayed = true;
			for (int i = 0; i < allPlayers.size(); i++)
			{
				nameLabel.setString(allPlayers[i].getPlayerName());
				float nameLabelPosX = windowWidth * NAMES_POS_X - nameLabel.getGlobalBounds().width * 0.5;
				float nameLabelPosY = windowHeight * LABELS_POS_Y - nameLabel.getGlobalBounds().height * 0.5;
				nameLabel.setPosition(sf::Vector2f(nameLabelPosX, nameLabelPosY));
				App.draw(nameLabel);

				allPointsLabel.setString(std::to_string(allPlayers[i].getPoints()));
				float allPointsLabelPosX = windowWidth * ALL_POINTS_POS_X - allPointsLabel.getGlobalBounds().width * 0.5;
				float allPointsLabelPosY = windowHeight * LABELS_POS_Y - allPointsLabel.getGlobalBounds().height * 0.5;
				allPointsLabel.setPosition(sf::Vector2f(allPointsLabelPosX, allPointsLabelPosY));
				App.draw(allPointsLabel);

				currentPointsLabel.setString(std::to_string(currentRoundPoints[i]));
				float currentPointsLabelPosX = windowWidth * CURRENT_POINTS_POS_X - currentPointsLabel.getGlobalBounds().width * 0.5;
				float currentPointsLabelPosY = windowHeight * LABELS_POS_Y - currentPointsLabel.getGlobalBounds().height * 0.5;
				currentPointsLabel.setPosition(sf::Vector2f(currentPointsLabelPosX, currentPointsLabelPosY));
				App.draw(currentPointsLabel);

				LABELS_POS_Y += 0.1;
			}

		} 
		else
		{
			LABELS_POS_Y = 0.2;
			isDisplayed = false;
		}


		App.draw(nextRoundButton);
		App.draw(continueLabel);
		App.draw(backToMenuButton);
		App.draw(noButton);
		App.draw(menuLabel);

		App.display();
	}
	return (-1);
}