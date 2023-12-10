#pragma once
#include "libraries.h"

class Person {
protected:
	std::string login;
	std::string password;
	std::string name;
public:
	Person() {
		login = "";
		password = "";
		name = "";
	};
	Person(const std::string& login, const std::string& password, const std::string& name)
	{
		this->login = login; this->name = name; this->password = password;
	}
	Person(const std::string& login, const std::string& password) :login(login), password(password) {};
	Person(const Person& object);
	~Person() {}

	std::string getLogin()
	{
		return this->login;
	}
	std::string getPassword()
	{
		return this->password;
	}
	std::string getName()
	{
		return this->name;
	}
	void setName(std::string name)
	{
		this->name = name;
	}
	void setLogin(std::string login)
	{
		this->login = login;
	}
	void setPassword(std::string password)
	{
		this->password = password;
	}

	virtual void showData() = 0;

	virtual int getYear() = 0;

	virtual void setMoney(float money) = 0;
	virtual int getWorCode() = 0;
};