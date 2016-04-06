#pragma once
#include <string>
using namespace std;

class Game
{
private:
	string _name;
	string _description;

public:
	Game(string name, string description);
	string DisplayValues();

};