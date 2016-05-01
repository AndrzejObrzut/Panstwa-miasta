#pragma once
#include <iostream>
#include <string>

using namespace std;

class WordsOfPlayer
{
private:
	string _country = "";
	string _city = "";
	string _thing = "";
	string _plant = "";


public:
	WordsOfPlayer();
	void setCountry(string country);
	string getCountry();
	void setCity(string city);
	string getCity();
	void setThing(string thing);
	string getThing();
	void setPlant(string plant);
	string getPlant();
	~WordsOfPlayer();
};

