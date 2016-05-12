// Main.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Menu.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "WindowView.h"
#include "ButtonView.h"


using namespace std;

int main()
{
	srand(time(NULL));


	//Menu menu;
	//bool option = menu.runMenu();
	//if (option == false) {
	//	return 0;
	//}
	//else {
	//	menu.runMenu();
	//}

	

	WindowView window(1024, 768, "Panstwa Miasta");
	window.clear(sf::Color(56, 134, 185, 255));

	ButtonView button("image/SinglePlayer.png", "image/SinglePlayer.png", true, sf::Vector2f(500,500));

	//sf::Texture texture;

	//if (!texture.loadFromFile("image/SinglePlayer.png")) {
	//	cout << "Error while loading image";
	//}

	//sf::Sprite sprite;
	//sprite.setTexture(texture);
	//sprite.setPosition(sf::Vector2f(10, 50));



	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.draw(button);
		window.display();
	}

	system("pause");
    return 0;
}

