#pragma once
#include "Person.h"

class Worker : public Person {
private:
	int workers_code;
	static int count;
public:
	Worker() { workers_code = 0; };
	Worker(const std::string& login, const std::string& password, const std::string& name, const int& workers_code) {
		this->login = login; this->name = name; this->password = password;
		this->workers_code = workers_code;
		count++;
	}
	Worker(const Worker& object);
	~Worker() {}

	int getWorCode() override
	{
		return this->workers_code;
	}

	static int getCount()
	{
		return count;
	}

	int getYear() override
	{
		return 0;
	}

	void showData() override
	{
		std::cout << "\t\t\t\t" << '|' << std::setw(30) << std::left << this->getName() << '|' << std::setw(29) << this->getWorCode() << "|" << std::endl;
		std::cout << "\t\t\t\t--------------------------------------------------------------\n";
	}

	void setMoney(float money) override
	{

	}
};