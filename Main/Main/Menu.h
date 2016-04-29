#pragma once

namespace MenuOptions {
	enum Option : char { LocalGame, OnlineGame, Exit, BadRequest };
}
class Menu
{
public:
	Menu();
	~Menu();

	bool runMenu();
protected:

private:
	bool choseMenuOption(MenuOptions::Option option);
	void runMenuAgain();
	void runLocalGame();
	void runOnlineGame();
	MenuOptions::Option menuOption;
};

