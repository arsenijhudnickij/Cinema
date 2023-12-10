#pragma once
#include "libraries.h"
#include "Ticket1.h"

class Session {
private:
	int month;
	int day;
	int year;
	int col_tickets;
	std::vector<class Ticket<std::string>*> tickets;
	int num_sess;
	std::string film_name;
	std::string time_sess;
	int hall_number;
public:
	Session() {
		month = 0;
		day = 0;
		year = 0;
		col_tickets = 0;
		time_sess = "";
		hall_number = 0;
		num_sess = 0;
	}

	Session(const int& year, const int& month, const int& day, const int& tic, const std::string time, const int& num_ses, const int& hall_number,
		std::vector<class Ticket<std::string>*> ticket, const std::string film_name)
	{
		this->month = month; this->year = year; this->day = day; this->col_tickets = tic; this->time_sess = time; this->num_sess = num_ses;
		this->hall_number = hall_number;
		this->tickets = ticket; this->film_name = film_name;
	}
	Session(const Session& object);
	~Session() {}

	int getMonth()
	{
		return this->month;
	}
	int getYear()
	{
		return this->year;
	}
	std::string getFilmName()
	{
		return this->film_name;
	}
	int getDay()
	{
		return this->day;
	}
	int getTick()
	{
		return this->col_tickets;
	}
	std::string getTime()
	{
		return this->time_sess;
	}
	int getHall()
	{
		return this->hall_number;
	}
	float getCostTick()
	{
		return this->tickets[0]->getCost();
	}
	void setColTick(int i)
	{
		this->col_tickets = i;
	}
	int getCollTick()
	{
		return this->col_tickets;
	}
	std::vector<class Ticket<std::string>*> getVect()
	{
		return this->tickets;
	}
	void addTicket(class Ticket<std::string>* a)
	{
		this->tickets.push_back(a);
	}
	int getNumSess()
	{
		return this->num_sess;
	}
	void setDay(int day)
	{
		this->day = day;
	}
	void setMonth(int month)
	{
		this->month = month;
	}
	void setYear(int year)
	{
		this->year = year;
	}
	void setHall(int hall)
	{
		this->hall_number = hall;
	}
	void setTick(int tick)
	{
		this->col_tickets = tick;
	}
	void setNumSess(int sess)
	{
		this->num_sess = sess;
	}
	void setFilmName(std::string name)
	{
		this->film_name = name;
	}void setTime(std::string time)
	{
		this->time_sess = time;
	}
	void showData();
	void showDataSpecial();
	void showDataForCheck();

	friend std::ostream& operator<<(std::ostream& out,Session* session)
	{
		out << session->getDay() << "\t" << session->getMonth() << "\t" << session->getYear() << std::endl;
		out << session->getTime() << std::endl;
		out << session->getNumSess() << "\t";
		out << session->getHall() << std::endl;
		out << session->getTick() << std::endl;
		out << session->getFilmName() << std::endl;
		
		return out;
	}
	friend std::istream& operator>>(std::istream& in, Session* session)
	{
		int day, month, year, numSess, hall, tick;
		std::string filmName, time;

		in >> day >> month >> year;
		in >> time;
	    in>> numSess >> hall;
		in >> tick;
		getline(in,filmName);

		session->setDay(day);
		session->setMonth(month);
		session->setYear(year);
		session->setTime(time);
		session->setNumSess(numSess);
		session->setHall(hall);
		session->setTick(tick);
		session->setFilmName(filmName);
		return in;
	}

};