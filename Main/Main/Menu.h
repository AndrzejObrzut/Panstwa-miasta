#pragma once

namespace MenuOptions {
	enum Option : char { LocalGame, OnlineGame, Exit, BadRequest };
}
class Menu
{
public:
	Menu();
	~Menu();

	void runMenu();
protected:

private:
	void choseMenuOption(MenuOptions::Option option);
	void runLocalGame();
	void runOnlineGame();
	MenuOptions::Option menuOption;
};

