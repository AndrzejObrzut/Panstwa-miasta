#include "stdafx.h"
#include "RoundScreen.h"
#include "TextField.h"

RoundScreen::RoundScreen() 
{
}

int RoundScreen::Run(sf::RenderWindow &App, Game &Game)
{
	sf::Event event;
	bool running = true;
	windowWidth = App.getSize().x;
	windowHeight = App.getSize().y;
	
	sf::Font font;
	if (!font.loadFromFile("fonts/arial.ttf"))
		std::cerr << "Problem with loading fonts" << std::endl;

	sf::Color textColor = sf::Color::Black;
	sf::Color textInputsColor = sf::Color::White;
	sf::Vector2f textInputsSize(310, 35);

	float allTextFieldPosX = windowWidth * 0.45;
	float coutryTextFieldPosY = windowHeight * 0.25;
	float cityTextFieldPosY = windowHeight * 0.33;
	float thingTextFieldPosY = windowHeight * 0.4;
	float plantTextFieldPosY = windowHeight * 0.48;

	std::string countryName;
	std::string cityName;
	std::string thingName;
	std::string plantName;

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

	std::string letter = "A";			// WYLOSOWANA LITERA
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

	Game.play();
	letter = Game.getCharacter();
	int countOfPlayers = Game.getPlayersCount();

	/*
	while round 
		while player
	*/
	while (running)
	{
		for (int i = 0; i < countOfPlayers; i++) 
		{
			bool playerFinishRound = false;
			while (!playerFinishRound) 
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
	

	}


	return 0;
}