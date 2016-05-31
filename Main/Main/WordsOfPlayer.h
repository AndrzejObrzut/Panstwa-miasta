#pragma once
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class WordsOfPlayer
{
private:
	string _country;
	string _city;
	string _thing;
	string _plant;


public:
	WordsOfPlayer();
	WordsOfPlayer(const WordsOfPlayer& source);
	WordsOfPlayer& operator=(const WordsOfPlayer& source);
	WordsOfPlayer(const WordsOfPlayer&& source);
	WordsOfPlayer& operator=(const WordsOfPlayer&& source);
	void initializeWords();
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

