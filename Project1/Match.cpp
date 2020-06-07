#include "Match.h"
#include <sstream>
#include<iostream>
using namespace std;
void Match::ispis() const
{
	stringstream ss;
	char buffer[256];
	strftime(buffer, sizeof(buffer), "%d.%m.%Y", &date);
	
	ss << buffer << ", " << stadium << ", " << hometeamname << " " << hometeamgoals << ":" << awayteamgoals << " " << awayteamname << endl;

	cout << ss.str() << endl;
}

void Match::set_year(int year)
{
	this->year = year;
}

void Match::set_date(tm date)
{
	this->date = date;
}

void Match::set_stage(string stage)
{
	this->stage = stage;
}

void Match::set_stadium(string stadium)
{
	this->stadium = stadium;
}

void Match::set_city(string city)
{
	this->city = city;
}

void Match::set_hometeamname(string hometeamname)
{
	this->hometeamname = hometeamname;

}

void Match::set_hometeamgoals(int hometeamgoals)
{
	this->hometeamgoals = hometeamgoals;
}

void Match::set_awayteamgoals(int awayteamgoals)
{

	this->awayteamgoals = awayteamgoals;
}

void Match::set_awayteamname(string awayteamname)
{
	this->awayteamname = awayteamname;
}

void Match::set_attendance(int attendance)
{
	this->attendance = attendance;
}

void Match::set_homeINITIALS(string homeINITIALS)
{
	this->homeINITIALS = homeINITIALS;
}

void Match::set_awayINITIALS(string awayINITIALS)
{
	this->awayINITIALS = awayINITIALS;
}

string Match::get_homeINITIALS() const
{
	return homeINITIALS;
}
string Match::get_awayINITIALS() const
{
	return awayINITIALS;
}

int Match::get_year() const
{
	return year;
}

int Match::get_hometeamgoals()
{
	return hometeamgoals;
}

int Match::get_awayteamgoals()
{
	return awayteamgoals;
}

string Match::get_stadium()
{
	return stadium;
}

string Match::get_hometeamname()const
{
	return hometeamname;
}

string Match::get_awayteamname()const
{
	return awayteamname;
}

tm Match::get_date()
{
	return date;
}

string Match::get_stage()
{
	return stadium;
}

string Match::get_city()
{
	return city;
}

int Match::get_attendance()
{
	return attendance;
}
