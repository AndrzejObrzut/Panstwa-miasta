#pragma once
#include <SFML/Graphics.hpp>

class ButtonView: public sf::Sprite
{
private:
	sf::Texture normal;
	sf::Texture hover;
	bool hidden;
	bool state;

	sf::Texture loadTexture(sf::String path);
protected:
public:
	ButtonView();
	ButtonView(sf::String& normalImagePath, sf::String& hoverImagePath, bool state);
	ButtonView(sf::String& normalImagePath, sf::String& hoverImagePath, bool state, sf::Vector2f& position);
	~ButtonView();

	void setState(bool state);
	bool getState();

	void setHidde(bool hidde);
	bool isHidden();

	bool isButtonHoverd(sf::Vector2i mousePos);
};

