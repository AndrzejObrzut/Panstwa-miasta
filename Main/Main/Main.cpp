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

	//sf::RenderWindow window(sf::VideoMode(1024, 768), "Panstwa Miasta");

	//window.clear(sf::Color(56, 134, 185, 255));

	WindowView window(1024, 768, "Panstwa Miasta");
	window.setColor(sf::Color(56, 134, 185, 255));

	sf::Font font;
	if (!font.loadFromFile("vgafix.fon")) {
		cout << "Can not fund the font file" << endl;
 	}

	sf::String sentence;
	sf::Text text(sentence, font, 40);
	text.setColor(sf::Color(255, 255, 255));
	text.setStyle(sf::Text::Bold);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.display();
	}

	system("pause");
    return 0;
}

