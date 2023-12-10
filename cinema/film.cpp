#include "Film.h"

Film::Film(const Film& object)
{
	ganre = object.ganre;
	name_film = object.name_film;
	minutes_film = object.minutes_film;
	hour_film = object.hour_film;
	sessions = object.sessions;
	category_age = object.category_age;
}

void Film::showData()
{
	std::cout << "\t\t" << '|' << std::setw(30) << std::left << this->getName() << '|' << std::setw(20)
		<< this->getGanre() << '|' << std::setw(15) << this->getCategory() << "|" << std::setw(12) << this->getHour() << "|" << std::setw(10) << this->getMinute() << "|" << std::endl;
	std::cout << "\t\t---------------------------------------------------------------------------------------------\n";
}

void Film::showSessions()
{
	std::cout << "\t\t----------------------------------------------------------------------------------------------\n";
	std::cout << "\t\t|                                          СЕАНСЫ                                            |\n";
	std::cout << "\t\t----------------------------------------------------------------------------------------------\n";
	std::cout << "\t\t" << '|' << std::setw(19) << std::left << "Год " << '|' << std::setw(18) << "Месяц " << '|' << std::setw(15) << "День" << "|" << std::setw(13) << "Время начала " << "|" << std::setw(7) << "Зал " << "|" << std::setw(15) << "Кол-во билетов" << "| \n";
	std::cout << "\t\t----------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < sessions.size(); i++)
	{
		sessions[i]->showData();
	}
}

void Film::showSessionsSpecial()
{
	std::cout << "\t\t-----------------------------------------------------------------------------------------------\n";
	std::cout << "\t\t|                                           СЕАНСЫ                                            |\n";
	std::cout << "\t\t-----------------------------------------------------------------------------------------------\n";
	std::cout << "\t\t" << '|' << std::setw(17) << std::left << "Номер сеанса " << '|' << std::setw(10) << std::left << "Год " << '|' << std::setw(10) << "Месяц " << '|' << std::setw(15) << "День" << "|" << std::setw(13) << "Время начала " << "|" << std::setw(7) << "Зал " << "|" << std::setw(15) << "Цена билета" << "| \n";
	std::cout << "\t\t-----------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < sessions.size(); i++)
	{
		sessions[i]->showDataSpecial();
	}
}