#include "stdafx.h"
#include "WordsOfPlayer.h"


WordsOfPlayer::WordsOfPlayer(): _country(""), _city(""), _thing(""), _plant("") { }

WordsOfPlayer::WordsOfPlayer(const WordsOfPlayer& source) 
	: _country(source._country), _city(source._city), _thing(source._thing), _plant(source._plant) { }

WordsOfPlayer& WordsOfPlayer::operator=(const WordsOfPlayer& source)
{
	if (this != &source)
	{
		_country = source._country;
		_city = source._city;
		_thing = source._thing;
		_plant = source._plant;
	}
	return *this;
}

WordsOfPlayer::WordsOfPlayer(const WordsOfPlayer&& source)
	: _country(std::move(source._country)), _city(std::move(source._city)), _thing(std::move(source._thing)), _plant(std::move(source._plant)) { }

WordsOfPlayer& WordsOfPlayer::operator=(const WordsOfPlayer&& source) {
	_country = std::move(source._country);
	_city = std::move(source._city);
	_thing = std::move(source._thing);
	_plant = std::move(source._plant);
	return *this;
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
	cout << "setCountry: " << _country << endl;

}

string WordsOfPlayer::getCountry()
{
	cout << "getCountry: " << _country << endl;
	return _country;
}

void WordsOfPlayer::setCity(string city)
{
	transform(city.begin(), city.end(), city.begin(), ::toupper);
	_city = city;
	cout << "setCity: " << _city << endl;

}

string WordsOfPlayer::getCity()
{
	cout << "getCity: " << _city << endl;

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
