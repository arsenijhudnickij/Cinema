#include "Admin.h"

Admin::Admin(const Admin& object)
{
	name = object.name;
	login = object.login;
	password = object.password;
	code = object.code;
}