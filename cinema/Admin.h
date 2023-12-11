#pragma once
#include "Person.h"

class Admin : public Person {
private:
	std::string code;
public:
	Admin() { code = ""; };
	Admin(const std::string& login, const std::string& password, const std::string& name, const std::string& code) {
		this->login = login; this->name = name; this->password = password;
		this->code = code;
	}
	Admin(const Admin& object);
	~Admin() {}

	std::string getAdminCode()
	{
		return this->code;
	}
	void setAdminCode(std::string code)
	{
		this->code = code;
	}
	void showData() override
	{

	}
	int getYear() override
	{
		return 0;
	}

	void setMoney(float money) override
	{

	}
	int getWorCode() override
	{
		return 0;
	}

	void setWorcode(int code) override
	{
	}
};