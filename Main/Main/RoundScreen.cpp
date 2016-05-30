#include "stdafx.h"
#include "RoundScreen.h"


RoundScreen::RoundScreen()
{
}


RoundScreen::~RoundScreen()
{
}

int RoundScreen::Run(sf::RenderWindow &App, Game &Game)
{
	sf::Event event;
	bool running = true;
	windowWidth = App.getSize().x;
	windowHeight = App.getSize().y;

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
				break;
			}
		}
	}
}