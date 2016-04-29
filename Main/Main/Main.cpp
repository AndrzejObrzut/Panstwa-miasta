// Main.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Menu.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));


	Menu menu;
	bool option = menu.runMenu();
	if (option == false) {
		return 0;
	}
	else {
		menu.runMenu();
	}

	system("pause");
    return 0;
}

