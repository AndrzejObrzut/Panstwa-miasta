#include "stdafx.h"
#include <iostream>
#include "ButtonView.h"

using namespace std;

ButtonView::ButtonView()
{

}

ButtonView::ButtonView(sf::String& normalImagePath, sf::String& clickedImagePath, bool state)
{
	normal = loadTexture(normalImagePath);
	clicked = loadTexture(clickedImagePath);
	if (state) {
		setTexture(normal);
	}
	else {
		setTexture(clicked);
	}

	state = state;
	setPosition(position);
}

ButtonView::ButtonView(sf::String& normalImagePath, sf::String& clickedImagePath, bool state, sf::Vector2f& position)
{
	normal = loadTexture(normalImagePath);
	clicked = loadTexture(clickedImagePath);
	if (state) {
		setTexture(normal);
	}
	else {
		setTexture(clicked);
	}

	state = state;
	position = position;
	setPosition(position);
}

ButtonView::~ButtonView()
{

}

// private

sf::Texture ButtonView::loadTexture(sf::String path)
{
	sf::Texture texture;
	if (!texture.loadFromFile(path)) {
		cout << "Error while loading image" << endl;
		texture.create(50, 50);
	}
	return texture;
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
	return position;
}

void ButtonView::setPositon(sf::Vector2f postion)
{
	position = position;
	setPosition(position);
}