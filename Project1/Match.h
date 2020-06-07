#pragma once
#include <string>
#include<iomanip>
using namespace std;
class Match
{
private:

	int year;
	tm date;
	string stage;
	string stadium;
	string city;
	string hometeamname;
	int hometeamgoals;
	int awayteamgoals;
	string awayteamname;
	int attendance;
	string homeINITIALS;
	string awayINITIALS;



public:
	void ispis() const;
	void set_year(int year);
	void set_date(tm date);
	void set_stage(string stage);
	void set_stadium(string stadium);
	void set_city(string city);
	void set_hometeamname(string hometeamname);
	void set_hometeamgoals(int hometeamgoals);
	void set_awayteamgoals(int awayteamgoals);
	void set_awayteamname(string awayteamname);
	void set_attendance(int attendance);
	void set_homeINITIALS(string homeINITIALS);
	void set_awayINITIALS(string awayINITIALS);

	string get_homeINITIALS() const;
	string get_awayINITIALS() const;
	int get_year() const;
	int get_hometeamgoals();
	int get_awayteamgoals();
	string get_stadium();
	string get_hometeamname()const;
	string get_awayteamname()const;
	tm get_date();
	string get_stage();
	string get_city();
	int get_attendance();
};

