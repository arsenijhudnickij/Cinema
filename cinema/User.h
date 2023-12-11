#pragma once
#include "Person.h"
#include "Ticket1.h"

class User : public Person {
private:
	std::string email;
	int year_birth;
	int month_birth;
	int date_birth;
	float money;
	std::vector<Ticket<std::string>*> myTickets;
public:
	User() {
		email = "";
		year_birth = 0;
		month_birth = 0;
		date_birth = 0;
		money = 0;
	};
	User(const std::string name, const std::string login, const std::string password, const std::string& email, const int& year_birth, const int& month_birth, const int& date_birth, const float& money)
	{
		this->name = name; this->login = login; this->password = password;
		this->email = email; this->year_birth = year_birth; this->month_birth = month_birth; this->date_birth = date_birth;
		this->money = money;
	}
	User(const User& object);
	~User() {}

	void setEmail(std::string email)
	{
		this->email = email;
	}

	void setYearBirth(int year)
	{
		this->year_birth = year;
	}

	void setDate(int date)
	{
		this->date_birth = date;
	}

	void setMonthBirth(int month_birth)
	{
		this->month_birth = month_birth;
	}

	void setMoney(float money) override
	{
		this->money = money;
	}

	std::string getEmail()
	{
		return this->email;
	}

	int getYear() override
	{
		return this->year_birth;
	}
	int getMonth()
	{
		return this->month_birth;
	}
	int getDay()
	{
		return this->date_birth;
	}
	float getMoney()
	{
		return this->money;
	}
	void addTicket(Ticket<std::string>* a)
	{
		return this->myTickets.push_back(a);
	}
	void showData() override
	{
		std::cout << "\t\t" << '|' << std::setw(30) << std::left << this->getName() << '|' << std::setw(20)
			<< this->getYear() << '|' << std::setw(14) << this->getMonth() << " |" << std::setw(14) << this->getDay() << "|" << std::endl;
		std::cout << "\t\t------------------------------------------------------------------------------------\n";

	}
	int getWorCode() override
	{
		return 0;
	}
	void showTicketsTable();
	void setWorcode(int code) override
	{
	}
};