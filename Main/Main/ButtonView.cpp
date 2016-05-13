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
	setPosition(position);
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

bool ButtonView::isButtonClicked() {
	sf::Mouse mouse;
	sf::Vector2i mousePos = mouse.getPosition();

	
	sf::IntRect buttonRect(this->getPosition().x, this->getPosition().y, this->getGlobalBounds().width, this->getGlobalBounds().height);

	if (buttonRect.contains(mousePos)) {
		state = true;
		this->setTexture(hover);
		return true;
	} 
	return false;
}
