#include "stdafx.h"
#include <iostream>
#include "ButtonView.h"

using namespace std;

ButtonView::ButtonView()
{

}

ButtonView::ButtonView(sf::String normal, sf::String clicked, bool state, sf::Vector2f position)
{

}

ButtonView::~ButtonView()
{

}

// private
bool ButtonView::checkSpriteImage(sf::String path)
{
	sf::Texture texture;
	if (!texture.loadFromFile(path))
	{
		cout << "Cannot load texture from file with path: " << path << endl;
	}
}


// public
void ButtonView::setState(bool state)
{
	state = state;
}

bool ButtonView::getState() 
{
	return state;
}

sf::Vector2f ButtonView::getPosition() 
{
	return position
}

void ButtonView::setPositon(sf::Vector2f postion)
{
	position = position
}