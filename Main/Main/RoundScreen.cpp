#include "stdafx.h"
#include "RoundScreen.h"
#include "TextField.h"

RoundScreen::RoundScreen() 
{
}

int RoundScreen::Run(sf::RenderWindow &App, Game &Game)
{
	cout << "TEST" << endl;
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
		countryTextField.draw(App);
		cityTextField.draw(App);
		thingTextField.draw(App);
		plantTextField.draw(App);

		App.display();

		cout << cityName << " vs " << cityTextField.string << endl;
	}

	return 0;
}