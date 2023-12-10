#include "Session.h"

Session::Session(const Session& object)
{
	month = object.month;
	day = object.day;
	year = object.year;
	time_sess = object.time_sess;
	num_sess = object.num_sess;
	hall_number = object.hall_number;
	col_tickets = object.col_tickets;
	film_name = object.film_name;
}

void Session:: showData()
{
	std::cout << "\t\t" << '|' << std::setw(19) << std::left << this->getYear() << '|' << std::setw(18)
		<< this->getMonth() << '|' << std::setw(15) << this->getDay() << "|" << std::setw(13) << this->getTime() << "|" << std::setw(7) << this->getHall() << "|" << std::setw(15) << this->getTick() << "|" << std::endl;
	std::cout << "\t\t----------------------------------------------------------------------------------------------\n";
}
void Session:: showDataSpecial()
{
	std::cout << "\t\t" << '|' << std::setw(17) << std::left << this->getNumSess() << '|' << std::setw(10) << std::left << this->getYear() << '|' << std::setw(10)
		<< this->getMonth() << '|' << std::setw(15) << this->getDay() << "|" << std::setw(13) << this->getTime() << "|" << std::setw(7) << this->getHall()
		<< "|" << std::setw(15) << this->tickets[0]->getCost() << "|" << std::endl;
	std::cout << "\t\t-----------------------------------------------------------------------------------------------\n";
}
void Session:: showDataForCheck()
{
	std::cout << "\t" << '|' << std::setw(10) << std::left << this->getYear() << '|' << std::setw(10)
		<< this->getMonth() << '|' << std::setw(10) << this->getDay() << "|" << std::setw(13) << this->getTime() << "|" << std::setw(7) << this->getHall()
		<< "|" << std::setw(15) << this->getTick() << "|" << std::setw(25) << this->getFilmName() << "|" << std::endl;
	std::cout << "\t--------------------------------------------------------------------------------------------------\n";
}