#pragma once
#include <SFML/Graphics.hpp>

class ButtonView: public sf::Sprite
{
private:
	sf::Texture normal;
	sf::Texture clicked;
	sf::Vector2f position;
	bool hiden;
	bool state;

	sf::Texture loadTexture(sf::String path);
protected:
public:
	ButtonView();
	ButtonView(sf::String normalImagePath, sf::String clickedImagePath, bool state, sf::Vector2f position);
	~ButtonView();

	void setState(bool state);
	bool getState();

	sf::Vector2f getPosition();
	void setPositon(sf::Vector2f postion);
};
