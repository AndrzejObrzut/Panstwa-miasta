#include "stdafx.h"
#include "WordsOfPlayer.h"


WordsOfPlayer::WordsOfPlayer()
{
}

void WordsOfPlayer::setCountry(string country)
{
	_country = country;
}

string WordsOfPlayer::getCountry()
{
	return _country;
}

void WordsOfPlayer::setCity(string city)
{
	_city = city;
}

string WordsOfPlayer::getCity()
{
	return _city;
}

void WordsOfPlayer::setThing(string thing)
{
	_thing = thing;
}

string WordsOfPlayer::getThing()
{
	return _thing;
}

void WordsOfPlayer::setPlant(string plant)
{
	_plant = plant;
}

string WordsOfPlayer::getPlant()
{
	return _plant;
}


WordsOfPlayer::~WordsOfPlayer()
{
}
