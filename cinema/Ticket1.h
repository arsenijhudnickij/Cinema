#pragma once
#include "Person.h"

template <class T>
class Ticket {
private:
	int seat;
	int row;
	float cost;
	T special_code;
	int id_user;
	std::string film_name;
	int year;
	int month;
	int day;
	std::string time;
public:
	Ticket() {
		seat = 0;
		row = 0;
		cost = 0;
		special_code = "";
		id_user;
		film_name = "";
	};

	Ticket(const int& seat, const int& row, const float& cost, const T& special_code, const std::string& film1,const std::string& time, const int& id, const int& year,const int& month, const int& day)
	{
		this->seat = seat; this->row = row; this->cost = cost; this->special_code = special_code;this->film_name = film1; this->id_user = id;
		this->year = year; this->month = month; this->day = day; this->time = time;
	}
	Ticket(const Ticket& object)
	{
		seat = object.seat;
		row = object.row;
		cost = object.cost;
		special_code = object.special_code;
		film_name = object.film_name;
		year = object.year;
		month = object.month;
		day = object.day;
		time = object.time;
	}
	~Ticket() {}

	int getSeat()
	{
		return this->seat;
	}
	int getRow()
	{
		return this->row;
	}
	float getCost()
	{
		return this->cost;
	}
	int getUserId()
	{
		return this->id_user;
	}
	void setUserId(int id)
	{
		this->id_user = id;
	}
	void setFilmName(std::string film)
	{
		this->film_name = film;
	}
	void setSpecial_code(T special_code)
	{
		this->special_code = special_code;
	}
	void setSeat(int seat)
	{
		this->seat = seat;
	}
	void setRow(int row)
	{
		this->row = row;
	}
	void setCost(float cost)
	{
		this->cost = cost;
	}
	int getYear()
	{
		return this->year;
	}
	int getMonth()
	{
		return this->month;
	}
	int getDay()
	{
		return this->day;
	}
	std::string getTime()
	{
		return this->time;
	}
	void setTime(std::string time)
	{
		this->time = time;
	}
	void setYear(int year)
	{
		this->year = year;
	}
	void setMonth(int month)
	{
		this->month = month;
	}
	void setDay(int day)
	{
		this->day = day;
	}
	std::string getFilmName()
	{
		return this->film_name;
	}
	T getSpecial_code()
	{
		return this->special_code;
	}
	template <class T>
	friend std::ostream& operator<<(std::ostream& out, Ticket<T>* ticket)
	{
		out  << ticket->getRow() << "\t" << ticket->getSeat() << "\t" << ticket->getUserId() << std::endl;
		out << ticket->getCost() << std::endl;
		out << ticket->getSpecial_code() << std::endl;
		out << ticket->getYear() << "\t" << ticket->getMonth() << "\t" << ticket->getDay() << std::endl;
		out << ticket->getTime() << std::endl;
		out << ticket->getFilmName() << std::endl;
		return out;
	}
	template <class T>
	friend std::istream& operator>>(std::istream& in, Ticket<T>* ticket)
	{
		std::string filmName, time;
		int seat, row, year, month, day;
		int userId;
		float cost;
		T specialCode;
		
		in >> row >> seat >> userId;
		in >> cost;
		in >> specialCode;
		in >> year >> month >> day;
		in >> time;
		getline(in,filmName);
		getline(in, filmName);
		if (!filmName.size()) { return in; }
	    ticket->setFilmName(filmName);
	    ticket->setSeat(seat);
        ticket->setRow(row);
        ticket->setCost(cost);
	    ticket->setSpecial_code(specialCode);
		ticket->setUserId(userId);
		ticket->setYear(year);
		ticket->setMonth(month);
		ticket->setDay(day);
		ticket->setTime(time);
		return in;
	}
};