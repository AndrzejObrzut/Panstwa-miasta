#include "stdafx.h"
#include "WindowView.h"
#include <SFML/Graphics.hpp>


WindowView::WindowView()
{
	//sf::RenderWindow(win)
}

WindowView::WindowView(int height, int width, sf::String title)
{
	sf::RenderWindow(sf::VideoMode(height, width), title);
}

WindowView::~WindowView()
{
}

void WindowView::setSize(int height, int width)
{
	size = sf::Vector2i(height, width);
}

sf::Vector2i WindowView::getSize()
{
	return size;
}

void WindowView::setColor(sf::Color color)
{
	color = color;
	clear(color);
}

sf::Color WindowView::getColor()
{
	return color;
}