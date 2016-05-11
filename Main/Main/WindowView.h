#pragma once
#include <SFML/Graphics.hpp>

class WindowView: sf::RenderWindow
{
private:
	sf::Color color;
	sf::Vector2i size;
protected:
public:
	WindowView();
	WindowView(int height, int width, sf::String title);
	~WindowView();

	void setSize(int height, int width);
	sf::Vector2i getSize();
	void setColor(sf::Color color);
	sf::Color getColor();
};

