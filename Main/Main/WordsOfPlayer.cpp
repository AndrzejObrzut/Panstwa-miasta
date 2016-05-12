#include "stdafx.h"
#include "WordsOfPlayer.h"


WordsOfPlayer::WordsOfPlayer()
{
}

void WordsOfPlayer::initializeWords()
{
	_country = "";
	_city = "";
	_thing = "";
	_plant = "";
}

void WordsOfPlayer::setCountry(string country)
{
	transform(country.begin(), country.end(), country.begin(), ::toupper);
	_country = country;
}

string WordsOfPlayer::getCountry()
{
	return _country;
}

void WordsOfPlayer::setCity(string city)
{
	transform(city.begin(), city.end(), city.begin(), ::toupper);
	_city = city;
}

string WordsOfPlayer::getCity()
{
	return _city;
}

void WordsOfPlayer::setThing(string thing)
{
	transform(thing.begin(), thing.end(), thing.begin(), ::toupper);
	_thing = thing;
}

string WordsOfPlayer::getThing()
{
	return _thing;
}

void WordsOfPlayer::setPlant(string plant)
{
	transform(plant.begin(), plant.end(), plant.begin(), ::toupper);
	_plant = plant;
}

string WordsOfPlayer::getPlant()
{
	return _plant;
}


WordsOfPlayer::~WordsOfPlayer()
{
}
