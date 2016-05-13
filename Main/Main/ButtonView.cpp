#include "stdafx.h"
#include <iostream>
#include "ButtonView.h"

using namespace std;

ButtonView::ButtonView()
{

}

ButtonView::ButtonView(sf::String& normalImagePath, sf::String& hoverImagePath, bool state)
{
	normal = loadTexture(normalImagePath);
	hover = loadTexture(hoverImagePath);
	if (!state) {
		setTexture(normal);
	}
	else {
		setTexture(hover);
	}

	state = state;
	hidden = false;
}

ButtonView::ButtonView(sf::String& normalImagePath, sf::String& hoverImagePath, bool state, sf::Vector2f& position)
{
	normal = loadTexture(normalImagePath);
	hover = loadTexture(hoverImagePath);
	if (state) {
		setTexture(normal);
	}
	else {
		setTexture(hover);
	}

	state = state;
	hidden = false;
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


void ButtonView::setHidde(bool hidde) 
{
	if (hidden) {
		setColor(sf::Color(0, 255, 0, 0));
	}
	else {
		setTexture(normal);
	}
	
	hidden = hidde;
}

bool ButtonView::isHidden()
{
	return hidden;
}

bool ButtonView::isButtonHoverd(sf::Vector2i mousePos) 
{
	sf::IntRect buttonRect(this->getPosition().x, this->getPosition().y, this->getGlobalBounds().width, this->getGlobalBounds().height);

	if (buttonRect.contains(mousePos)) 
	{
		this->setTexture(hover);
		return true;
	}
	this->setTexture(normal);
	return false;
}

