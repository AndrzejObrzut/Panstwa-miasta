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
	sf::Vector2f textInputsSize(310, 45);

	float cityTextFiledPosX = windowWidth * 0.35;
	float cityTextFiledPosY = windowHeight * 0.32;


	std::string cityName;

	cityTextField = TextField(cityName, font, 35, textColor);
	cityTextField.setFrame(textInputsSize, textInputsColor);
	cityTextField.setPositon(sf::Vector2f(cityTextFiledPosX, cityTextFiledPosY));

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
				if (cityTextField.isHoverd(mousePos)) {
					cityTextField.action(event);
				}
				break;
			}
		}
		App.clear(sf::Color(56, 134, 185, 255));
		cityTextField.draw(App);
		App.display();
	}

	return 0;
}