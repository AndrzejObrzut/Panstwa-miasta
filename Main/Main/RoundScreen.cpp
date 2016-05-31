#include "stdafx.h"
#include "RoundScreen.h"
#include "TextField.h"
#include "ButtonView.h"

RoundScreen::RoundScreen() 
{
}

int RoundScreen::Run(sf::RenderWindow &App, Game &Game)
{
	sf::Event event;
	bool running = true;
	windowWidth = App.getSize().x;
	windowHeight = App.getSize().y;


	Game.play();
	char randCharacter = Game.getCharacter();
	std::string letter(1, randCharacter);
	int countOfPlayers = Game.getPlayersCount();

	sf::Font font;
	if (!font.loadFromFile("fonts/arial.ttf"))
		std::cerr << "Problem with loading fonts" << std::endl;

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

	sf::String nextButtonPath("image/ForwardButton.png");
	ButtonView nextButton(nextButtonPath, nextButtonPath, false);
	float nextButtonPosX = windowWidth * 0.80 - nextButton.getGlobalBounds().width * 0.5;
	float nextButtonPosY = windowHeight * 0.80 - nextButton.getGlobalBounds().height * 0.5;
	nextButton.setPosition(nextButtonPosX, nextButtonPosY);

	sf::Color textColor = sf::Color::Black;
	sf::Color textInputsColor = sf::Color::White;
	sf::Vector2f textInputsSize(310, 35);

	float allTextFieldPosX = windowWidth * 0.45;
	float coutryTextFieldPosY = windowHeight * 0.25;
	float cityTextFieldPosY = windowHeight * 0.33;
	float thingTextFieldPosY = windowHeight * 0.4;
	float plantTextFieldPosY = windowHeight * 0.48;

	countryTextField = TextField(countryName, font, 30, textColor);
	countryTextField.setFrame(textInputsSize, textInputsColor);
	countryTextField.setPositon(sf::Vector2f(allTextFieldPosX, coutryTextFieldPosY));

	cityTextField = TextField(cityName, font, 30, textColor);
	cityTextField.setFrame(textInputsSize, textInputsColor);
	cityTextField.setPositon(sf::Vector2f(allTextFieldPosX, cityTextFieldPosY));

	thingTextField = TextField(thingName, font, 30, textColor);
	thingTextField.setFrame(textInputsSize, textInputsColor);
	thingTextField.setPositon(sf::Vector2f(allTextFieldPosX, thingTextFieldPosY));

	plantTextField = TextField(plantName, font, 30, textColor);
	plantTextField.setFrame(textInputsSize, textInputsColor);
	plantTextField.setPositon(sf::Vector2f(allTextFieldPosX, plantTextFieldPosY));

	std::string main = "Wprowadz odpowiedzi";
	sf::Text mainLabel(main, font, 35);
	mainLabel.setColor(sf::Color::White);
	float mainLabelPosX = windowWidth * 0.5 - mainLabel.getGlobalBounds().width * 0.5;
	float mainLabelPosY = windowWidth * 0.05 - mainLabel.getGlobalBounds().height * 0.5;
	mainLabel.setPosition(mainLabelPosX, mainLabelPosY);

	sf::Text letterLabel(letter, font, 35);
	letterLabel.setColor(sf::Color::Red);
	float letterLabelPosX = windowWidth * 0.5 - letterLabel.getGlobalBounds().width * 0.5;
	float letterLabelPosY = windowWidth * 0.1 - letterLabel.getGlobalBounds().height * 0.5;
	letterLabel.setPosition(letterLabelPosX, letterLabelPosY);

	std::string country = "Panstwo";
	std::string city = "Miasto";
	std::string thing = "Rzecz";
	std::string plant = "Roslina";

	float allLabelPosX = windowWidth * 0.3;
	float countryLabelPosY = windowHeight * 0.25;
	float cityLabelPosY = windowHeight * 0.33;
	float thingLabelPosY = windowHeight * 0.4;
	float plantLabelPosY = windowHeight * 0.48;

	sf::Text countryLabel(country, font, 25);
	countryLabel.setColor(sf::Color::White);
	countryLabel.setPosition(allLabelPosX - countryLabel.getGlobalBounds().width * 0.5, countryLabelPosY);

	sf::Text cityLabel(city, font, 25);
	cityLabel.setColor(sf::Color::White);
	cityLabel.setPosition(allLabelPosX - cityLabel.getGlobalBounds().width * 0.5, cityLabelPosY);

	sf::Text thingLabel(thing, font, 25);
	thingLabel.setColor(sf::Color::White);
	thingLabel.setPosition(allLabelPosX - thingLabel.getGlobalBounds().width * 0.5, thingLabelPosY);

	sf::Text plantLabel(plant, font, 25);
	plantLabel.setColor(sf::Color::White);
	plantLabel.setPosition(allLabelPosX - plantLabel.getGlobalBounds().width * 0.5, plantLabelPosY);


	/*
	while round 
		while player
	*/

	vector<Player> allPlayers = Game.getPlayers();
	while (running)
	{

		bool playerFinishRound = false;
		int index = 0;
		while (!playerFinishRound) 
		{
			Player currentPlayer = allPlayers[index];
			cout << "Current player is " << currentPlayer.getPlayerName() << endl;
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
					if (backToMenuButton.isButtonHoverd(mousePos) && mouse.isButtonPressed(sf::Mouse::Left)) { return (0); }

					if (nextButton.isButtonHoverd(mousePos) && mouse.isButtonPressed(sf::Mouse::Left))
					{ 
						if ((index + 1) == Game.getPlayersCount())
						{
							cout << "Koniec gry" << endl;
						}
						else
						{
							cout << "Nastepny gracz" << endl;
							resetFileds();
							index++;
						}
						// zapisz dane gracza
						// if countOfplayers == players.size() { zapytanie o nowa runde - tak reneruj 2, nie renderuj 3 (wyniki) }
						// else renderuj dla gracza++
					}

					break;
				case sf::Event::TextEntered:
					if (countryTextField.isHoverd(mousePos))
						countryName = countryTextField.action(event);

					if (cityTextField.isHoverd(mousePos))
						cityName = cityTextField.action(event);

					if (thingTextField.isHoverd(mousePos))
						thingName = thingTextField.action(event);

					if (plantTextField.isHoverd(mousePos))
						plantName = plantTextField.action(event);

					break;
				}
			}
			App.clear(sf::Color(56, 134, 185, 255));
			App.draw(mainLabel);
			App.draw(letterLabel);
			App.draw(backToMenuButton);
			App.draw(nextButton);
			countryTextField.draw(App);
			cityTextField.draw(App);
			thingTextField.draw(App);
			plantTextField.draw(App);

			App.draw(countryLabel);
			App.draw(cityLabel);
			App.draw(thingLabel);
			App.draw(plantLabel);

			App.display();
		}	

	}

	return 0;
}

void RoundScreen::resetFileds()
{
	countryName = "";
	cityName = "";
	thingName = "";
	plantName = "";

	countryTextField.setString(countryName);
	cityTextField.setString(cityName);
	thingTextField.setString(thingName);
	plantTextField.setString(plantName);
}
