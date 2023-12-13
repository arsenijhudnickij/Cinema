#pragma once
#include "Session.h"

class Film {
private:
	std::string ganre;
	std::string name_film;
	std::string category_age;
	int hour_film;
	int minutes_film;
	std::vector<Session*> sessions;
public:
	Film() {
		ganre = "";
		name_film = "";
		hour_film = 0;
		minutes_film = 0;
		category_age = "";
	};
	Film(const std::string& ganre, const std::string& name_film, const int& hour_film, const int& minutes_film, const std::string& category_age)
	{
		this->ganre = ganre; this->name_film = name_film; this->hour_film = hour_film; this->minutes_film = minutes_film;
		this->category_age = category_age;
	}
	Film(const Film& object);
	~Film() {}
	void setName(std::string name)
	{
		this->name_film = name;
	}
	void setGenre(std::string ganr)
	{
		this->ganre = ganr;
	}
	void setCategory(std::string categ)
	{
		this->category_age = categ;
	}
	void setHour(int hour)
	{
		this->hour_film = hour;
	}
	void setMinute(int min)
	{
		this->minutes_film = min;
	}
	std::string getName()
	{
		return this->name_film;
	}
	std::string getGanre()
	{
		return this->ganre;
	}
	std::string getCategory()
	{
		return this->category_age;
	}
	int getHour()
	{
		return this->hour_film;
	}
	int getMinute()
	{
		return this->minutes_film;
	}
	void addSession(Session* a)
	{
		this->sessions.push_back(a);
	}

	std::vector<Session*> getSess()
	{
		return this->sessions;
	}
	void showSessionsSpecial();
	void showSessions();
	void showData();

	friend std::ostream& operator<<(std::ostream& out, Film* film)
	{
		out << film->getHour() << "\t";
		out << film->getMinute() << '\t';
		out << film->getCategory() << "\t";
		out << film->getGanre() << "|";
		out << film->getName() << std::endl;
		return out;
	}

	friend std::istream& operator>>(std::istream& in, Film* film) {
		int hour, minute;
		std::string name, genre, category;

		in >> hour;
		in >> minute;
		in >> category;
		if (!category.size()) { return in; }

		for (char tempSymb{}; tempSymb != '|'; ) {
			genre += tempSymb;
			in >> std::noskipws >> tempSymb;
		}
		in >> std::skipws;
		genre.erase(genre.begin(), genre.begin() + 2);

		getline(in, name);

		film->setName(name);
		film->setGenre(genre);
		film->setCategory(category);
		film->setHour(hour);
		film->setMinute(minute);
		return in;
	}
};