#include "User.h"


User::User(const User& object)
{
	name = object.name;
	login = object.login;
	password = object.password;
	year_birth = object.year_birth;
	date_birth = object.date_birth;
	month_birth = object.month_birth;
	email = object.email;
	money = object.money;
}

void User::showTicketsTable() {
	if (myTickets.size() > 0)
	{
		std::cout << "Билеты пользователя:\n";
		std::cout << "--------------------------------------------------------------------------------------------------------------\n";
		std::cout << "| Номер | Название фильма        |  Ряд  |  Место  |     Код     | Цена |  Год  |  Месяц  |  День  |  Время  |\n";
		std::cout << "--------------------------------------------------------------------------------------------------------------\n";
		for (int i = 0; i < myTickets.size(); i++) {
			Ticket<std::string>* ticket = myTickets[i];
				std::cout << "|" << std::setw(6) << i + 1 << " | "
					<< std::setw(22) << ticket->getFilmName() << " | "
					<< std::setw(5) << ticket->getRow() << " | "
					<< std::setw(7) << ticket->getSeat() << " | "
					<< std::setw(11) << ticket->getSpecial_code() << " | "
					<< std::setw(4) << ticket->getCost() << " |"
					<< std::setw(6) << ticket->getYear() << " | "
					<< std::setw(7) << ticket->getMonth() << " | "
					<< std::setw(6) << ticket->getDay() << " | "
					<< std::setw(7) << ticket->getTime() << " |\n";
		}
		std::cout <<"--------------------------------------------------------------------------------------------------------------\n";
	}
	else
	{
		std::cout << "\n\n\n\n\n\t\t\t\t\tОтсутствуют купленные билеты" << std::endl;
	}
}