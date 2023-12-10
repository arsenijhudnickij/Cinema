#include "Person.h"

Person::Person(const Person& object)
{
	login = object.login;
	password = object.password;
	name = object.name;
}