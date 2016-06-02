#include "stdafx.h"
#include "TextField.h"


TextField::TextField() {}

TextField::TextField(std::string &string, sf::Font &font, int fontSize, sf::Color &color) : string(string), text(sf::Text(string, font, fontSize))
{
	text.setColor(color);
}


TextField::~TextField() { }

TextField::TextField(const TextField & source) : rectangleFrame(source.rectangleFrame), string(source.string), text(source.text) { }

TextField& TextField::operator=(const TextField& source)
{
	if (this != &source)
	{
		rectangleFrame = source.rectangleFrame;
		string = source.string;
		text = source.text;
	}
	return *this;
}

TextField::TextField(const TextField && source) : rectangleFrame(std::move(source.rectangleFrame)), string(std::move(source.string)), text(std::move(source.text)) { }

TextField& TextField::operator=(const TextField&& source)
{
	rectangleFrame = std::move(source.rectangleFrame);
	string = std::move(source.string);
	text = std::move(source.text);
	return *this;
}

void TextField::draw(sf::RenderWindow &App)
{
	App.draw(rectangleFrame);
	App.draw(text);
}

std::string TextField::action(sf::Event &event)
{
	if (event.text.unicode >= 32 && event.text.unicode < 126 && string.size() < 30)
		string += (char)event.text.unicode;
	else if (event.text.unicode == 8 && string.size() > 0)
		string = string.substr(0, string.length() - 1);

	text.setString(string);
	text.setColor(sf::Color::Black);

	return string;
}


void TextField::setFrame(sf::Vector2f &size, sf::Color &color)
{
	rectangleFrame = sf::RectangleShape(size);
	rectangleFrame.setFillColor(color);
}

void TextField::setPositon(sf::Vector2f &position)
{
	float posX = position.x - text.getGlobalBounds().width * 0.5;
	float posY = position.y - text.getGlobalBounds().height * 0.5;

	text.setPosition(sf::Vector2f(posX, posY));
	rectangleFrame.setPosition(sf::Vector2f(position.x - 5, position.y));
}

bool TextField::isHoverd(sf::Vector2i &mousePos)
{

	sf::IntRect textFiledRect(rectangleFrame.getPosition().x, rectangleFrame.getPosition().y, rectangleFrame.getGlobalBounds().width, rectangleFrame.getGlobalBounds().height);

	if (textFiledRect.contains(mousePos)) return true;
	return false;
}

void TextField::setString(std::string newString)
{
	string = newString;
	text.setString(newString);
	text.setColor(sf::Color::Black);
}
