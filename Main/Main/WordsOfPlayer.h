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
	void initializeWords();
	void setCountry(string country);
	string getCountry() const;
	void setCity(string city);
	string getCity() const;
	void setThing(string thing);
	string getThing() const;
	void setPlant(string plant);
	string getPlant() const;
	~WordsOfPlayer();
};

