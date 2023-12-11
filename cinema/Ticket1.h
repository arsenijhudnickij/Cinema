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
public:
	Ticket() {
		seat = 0;
		row = 0;
		cost = 0;
		special_code = "";
		id_user;
		film_name = "";
	};
	Ticket(const int& seat, const int& row, const float& cost, const T& special_code,const std::string& film1)
	{
		this->seat = seat; this->row = row; this->cost = cost; this->special_code = special_code;
		this->user = NULL; this->film_name = film1;
	}
	Ticket(const Ticket& object)
	{
		seat = object.seat;
		row = object.row;
		cost = object.cost;
		special_code = object.special_code;
		film_name = object.film_name;
	}
	~Ticket() {}

	T getSpecial_code()
	{
		return this->special_code;
	}
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
	void setUser(Person* u)
	{
		this->user = u;
	}
	Person* getUser()
	{
		return this->user;
	}
	std::string getFilmName()
	{
		return this->film_name;
	}

	template <class T>
	friend std::ostream& operator<<(std::ostream& out, Ticket<T>* ticket)
	{
		
		out  << ticket->getRow() << "\t" << ticket->getSeat() << std::endl;
		out << ticket->getCost() << std::endl;
		out << ticket->getSpecial_code() << std::endl;
		out << ticket->getFilmName() << std::endl;
		return out;
	}
	template <class T>
	friend std::istream& operator>>(std::istream& in, Ticket<T>* ticket)
	{
		std::string filmName;
		int seat, row;
		float cost;
		T specialCode;
		
		in >> row >> seat;
		in >> cost;
		in >> specialCode;
		getline(in,filmName);
		if (!filmName.size()) { return in; }
	    ticket->setFilmName(filmName);
	    ticket->setSeat(seat);
        ticket->setRow(row);
        ticket->setCost(cost);
	    ticket->setSpecial_code(specialCode);
		ticket->setUser(NULL);
		return in;
	}
};