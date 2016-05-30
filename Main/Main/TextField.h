#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

class TextField
{
public:
	sf::RectangleShape rectangleFrame;
	std::string string;
	sf::Text text;

	TextField();
	TextField(std::string &string,sf::Font &font, int fontSize, sf::Color &color);
	TextField (const TextField& source);
	TextField& operator=(const TextField& source);
	TextField (const TextField&& source);
	TextField& operator=(const TextField&& source);
	~TextField();

	void draw(sf::RenderWindow &App);
	void setFrame(sf::Vector2f size, sf::Color color);
	void TextField::setPositon(sf::Vector2f position);
};

