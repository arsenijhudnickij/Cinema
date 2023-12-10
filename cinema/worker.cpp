#include "Worker.h"

int Worker::count = 0;

Worker::Worker(const Worker& object)
{
	name = object.name;
	login = object.login;
	password = object.password;
	workers_code = object.workers_code;
}