#include "stdafx.h"
#include "ResultScreen.h"


ResultScreen::ResultScreen()
{
}


ResultScreen::~ResultScreen()
{
}


int ResultScreen::Run(sf::RenderWindow &App, Game &game)
{
	sf::Event event;
	bool running = true;

	sf::Font font;
	if (!font.loadFromFile("fonts/arial.ttf"))
		std::cerr << "Problem with loading fonts" << std::endl;

	
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
				break;
			default:
				break;
			}

		}

		App.clear(sf::Color(56, 134, 185, 255));

		App.display();
	}
	return (-1);
}