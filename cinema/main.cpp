#include "myNamespace.h"

int main()
{
    system("chcp 1251");
    system("cls");
    int iduser = 1000;
    Method method;
    int current_users = 0;
    std::vector<User*> users;

    std::vector<Worker*> workers;
    int current_workers = myNamespace::inputWorkersFromFile(workers);

    std::array <Film*, 10> films{};
    int current_films = myNamespace::inputFilmsFromFile(films);

    int del_workers = 0;

    std::vector<Session*> sessions  =myNamespace::inputSessionsFromFile(sessions);

    std::string nameAdmin = "qw";
    std::string loginAdmin = "zxcvbnm123";
    std::string passwordAdmin = "qwertyuiop";
    std::string codeAdmin = "qwertyuiop";

    std::unique_ptr<Admin> admin1(new Admin(loginAdmin, myNamespace::kodirovka(passwordAdmin), nameAdmin, codeAdmin));

    int codes[3] = { 123567,634521,719034 };
    int current_sessions = 0;
    int choice{};
    do {
        system("cls");
        myNamespace::menuFull();
        try {
            std::cout << "\n\t\t\t\t\t\t";
            if (!(std::cin >> choice))
                throw std::runtime_error("\n\n\n\t\t\t\t\t\tНеверный ввод данных");
        }
        catch (std::runtime_error errr) {

            std::cout << errr.what() << std::endl;
            std::cout << "\n\t\t\t\t\t\t";
            system("pause");
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            continue;
        }

        User* curr_user = new User();

        std::cin.clear();
        std::cin.ignore(1024, '\n');
        system("cls");
        switch (choice)
        {
        case 1:
        {
            int choice1{};
            do {
                system("cls");
                myNamespace::menuUserWorFirst();
                try {
                    std::cout << "\n\t\t\t\t\t\t";
                    if (!(std::cin >> choice1))
                        throw std::runtime_error("\n\n\n\t\t\t\t\t\tНеверный ввод данных");
                }
                catch (std::runtime_error errr) {

                    std::cout << errr.what() << std::endl;
                    std::cout << "\n\t\t\t\t\t\t";
                    system("pause");
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                    continue;
                }
                std::cin.clear();
                std::cin.ignore(1024, '\n');
                system("cls");
                switch (choice1)
                {
                case 1:
                {
                    iduser++;
                    users.push_back(myNamespace::registrationUser(users,iduser));
                    current_users++;
                    std::cout << "\n";
                    std::cout << "\t\t\t\t\t\t";
                    system("pause");
                    system("cls");
                    break;
                }
                case 2:
                {
                    system("cls");
                    std::cout << "\n";
                    std::cout << "\t\t\t\t\t\t";
                    User* b = myNamespace::authorizationUser(users);
                    if (b != NULL)
                    {
                        curr_user = b;
                        int choose{};
                        std::cout << "\n\n\n\t\t\t\t\t\tВы успешно авторизовались!" << std::endl;
                        do {
                            system("cls");
                            std::cout << "\n\n\n";
                            myNamespace::menuUserFin();
                            try {
                                std::cout << "\n\t\t\t\t\t\t";
                                if (!(std::cin >> choose))
                                    throw std::runtime_error("\n\n\n\t\t\t\t\t\tНеверный ввод данных");
                            }
                            catch (std::runtime_error errr) {

                                std::cout << errr.what() << std::endl;
                                std::cout << "\n\t\t\t\t\t\t";
                                system("pause");
                                std::cin.clear();
                                std::cin.ignore(1024, '\n');
                                continue;
                            }

                            std::cin.clear();
                            std::cin.ignore(1024, '\n');
                            system("cls");
                            switch (choose)
                            {
                            case 1:
                            {
                                if (2023 - curr_user->getYear() >= 18)
                                {
                                    float my_money{};
                                    std::cout << "\n\n\n\n\n\t\t\t\t\tВведите количество ваших средств:" << std::endl;
                                    do {
                                        my_money = myNamespace::checkNumberfl(my_money);
                                        if (my_money < 0)
                                        {
                                            std::cout << "\n\n\t\t\t\t\tНеверный ввод данных" << std::endl;
                                        }
                                    } while (my_money < 0);

                                    system("cls");

                                    for (int i = 0; i < users.size(); i++)
                                    {
                                        if (users[i]->getName() == curr_user->getName() && (users[i]->getLogin() == curr_user->getLogin()))
                                        {
                                            users[i]->setMoney(my_money+users[i]->getMoney());
                                            std::cout << "\n\n\n\n\n\t\t\t\t\tДанные о количестве средств успешно добавлены" << std::endl;
                                            break;
                                        }
                                    }
                                }
                                else
                                {
                                    std::cout << "\n\n\n\n\n\t\t\t\tПользователи младше 18 лет не имеют права оплаты в системе" << std::endl;
                                }
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 2:
                            {
                                 if (current_films > 0)
                                 {
                                    myNamespace::checkSessions(current_films, films);
                                 }
                                else
                                {
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tВ системе отсутствуют фильмы" << std::endl;
                                }
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 3:
                            {        
                                if (current_films > 0)
                                {
                                    Film* bbb = myNamespace::checkSessions1(current_films, films);
                                    if (bbb != NULL)
                                    {
                                        std::vector<Session*> session_cor = bbb->getSess();
                                        int sess_num{};
                                        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите номер сеанса:" << std::endl;
                                        do {
                                            sess_num = myNamespace::checkNumber(sess_num);
                                            if (sess_num < 0)
                                            {
                                                std::cout << "\n\t\t\t\t\t\tНеверный ввод, попробуйте сначала" << std::endl;
                                            }
                                        } while (sess_num < 0);
                                        system("cls");

                                        Session* g;
                                        for (int i = 0; i < session_cor.size(); i++)
                                        {
                                            if (sess_num == session_cor[i]->getNumSess())
                                            {
                                                g = session_cor[i];
                                                myNamespace::checkHall(g, g->getCostTick());
                                                int row1{};
                                                std::cout << "\n\n\n\n\n\t\t\t\tВведите желаемый ряд(если хотите вернуться введите ряд - (-1), место- (-1)):" << std::endl;
                                                do {
                                                    row1 = myNamespace::checkNumber(row1);
                                                    if (row1 < -2 || row1 > (g->getCollTick()) / 10)
                                                    {
                                                        std::cout << "\n\n\t\t\t\t\t\tНеверный ввод данных" << std::endl;
                                                    }
                                                } while (row1 < -2 || row1 > (g->getCollTick()) / 10);

                                                int seat1{};
                                                std::cout << "\n\n\n\n\n\t\t\t\tВведите желаемое место,(если хотите вернуться введите ряд - (-1), место- (-1)):" << std::endl;
                                                do {
                                                    seat1 = myNamespace::checkNumber(seat1);
                                                    if (seat1 < -2 || seat1 > 10)
                                                    {
                                                        std::cout << "\n\n\t\t\t\t\t\tНеверный ввод данных" << std::endl;
                                                    }
                                                } while (seat1 < -2 || seat1 > 10);
                                                system("cls");
                                                int flad = 0;
                                  
                                                for (int row = 0; row < (g->getCollTick() / 10); ++row)
                                                {
                                                    if (flad == 0)
                                                    {
                                                        for (int seat = 1; seat <= 10; ++seat)
                                                        {
                                                            if (flad == 0)
                                                            {
                                                                if (row1 == row + 1 && seat1 == seat)
                                                                {
                                                                    flad++;
                                                                    int a = (row) * 10 + seat - 1;
                                                                    if (g->getVect()[a]->getUser() == NULL)
                                                                    {
                                                                        if (curr_user->getMoney() >= g->getVect()[a]->getCost())
                                                                        {
                                                                            curr_user->setMoney(curr_user->getMoney() - g->getVect()[a]->getCost());
                                                                            g->getVect()[a]->setUser(curr_user);
                                                                            curr_user->addTicket(g->getVect()[a]);
                                                                            std::cout << "\n\n\n\n\n\t\t\t\t\tУспешно куплен" << std::endl;
                                                                            break;
                                                                        }
                                                                        else
                                                                        {
                                                                            std::cout << "\n\n\n\n\n\t\t\t\t\tНедостаточно средств" << std::endl;
                                                                            break;
                                                                        }
                                                                    }
                                                                    else
                                                                    {
                                                                        std::cout << "\n\n\n\n\n\t\t\t\t\t\tБилет уже был куплен" << std::endl;
                                                                        break;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                    else
                                                    {
                                                        break;
                                                    }
                                                }
                                                if (flad == 0)
                                                {
                                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tНет таких мест" << std::endl;
                                                }
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tВ системе отсутствуют фильмы" << std::endl;
                                }
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 4:
                            {        
                                if (current_films > 0)
                                {
                                    myNamespace::searchFilm(current_films, films);
                                }
                                else
                                {
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tВ системе отсутствуют фильмы" << std::endl;
                                }
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 5:
                            {
                                int sort{};
                                do {
                                    if (current_films > 0)
                                    {
                                        std::cout << "\n\n\n\t\t\t\t\t1. Сортировка по жанру" << std::endl;
                                        std::cout << "\t\t\t\t\t2. Сортировка по названию" << std::endl;
                                        std::cout << "\t\t\t\t\t3. Сортировка по продолжительности" << std::endl;
                                        std::cout << "\t\t\t\t\t4. Выход" << std::endl;
                                        std::cout << "\t\t\t\t\t Ваш выбор?\n" << std::endl;
                                        try {
                                            std::cout << "\n\t\t\t\t\t\t";
                                            if (!(std::cin >> sort))
                                                throw std::runtime_error("\n\n\n\t\t\t\t\t\tНеверный ввод данных");
                                        }
                                        catch (std::runtime_error errr) {

                                            std::cout << errr.what() << std::endl;
                                            std::cout << "\n\t\t\t\t\t\t";
                                            system("pause");
                                            std::cin.clear();
                                            std::cin.ignore(1024, '\n');
                                            continue;
                                        }
                                        system("cls");
                                        myNamespace::sortFilms(films, current_films, sort);
                                    }
                                    else
                                    {
                                        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВ системе отсутствуют фильмы" << std::endl;
                                    }
                                } while (sort != 4);
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 6:
                            {
                                if (current_films > 0)
                                {
                                    myNamespace::checkSessionsData(current_films, films);
                                }
                                else
                                {
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tВ системе отсутствуют фильмы" << std::endl;
                                }
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 7:
                            {
                                if (current_films > 0)
                                {
                                    myNamespace::showFilms(current_films, films);
                                }
                                else
                                {
                                    std::cout << "\n\n\n\n\n\t\t\t\t\tВ системе отсутствуют фильмы" << std::endl;
                                }
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 8:
                            {
                                if (current_films > 0)
                                {
                                    myNamespace::showFilmsProdolg(current_films, films);
                                }
                                else
                                {
                                    std::cout << "\n\n\n\n\n\t\t\t\t\tВ системе отсутствуют фильмы" << std::endl;
                                }
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 9:
                            {
                                curr_user->showTicketsTable();
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 10:
                            {
                                std::cout << "\n\n\n\n\n\t\t\t\t\tКоличество ваших средств: "<<curr_user->getMoney() << std::endl;
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 11:
                            {
                                std::cout << "\n\n\n\n\n\n\n\t\t\t\t";
                                break;
                            }
                            default:
                            {
                                std::cout << "\n\n\n\n\n\t\t\t\t\t\t";
                                std::cout << "Неверный ввод" << std::endl;
                                std::cout << "\n\t\t\t\t\t";
                                system("pause");
                                system("cls");
                            }
                            }
                        } while (choose != 11);
                    }
                    else {
                        std::cout << "\n\n\n\n\n\n\t\t\t\t\tВы не смогли войти в систему" << std::endl;
                    }
                    std::cout << "\n";
                    std::cout << "\t\t\t\t\t";
                    system("pause");
                    system("cls");
                    break;
                }
                case 3:
                    std::cout << "\n\n\n\n\n\n\n\t\t\t\t";
                    break;
                default:
                    std::cout << "\n\n\n\n\n\t\t\t\t\t\t";
                    std::cout << "Неверный ввод" << std::endl;
                    std::cout << "\n\t\t\t\t\t";
                    system("pause");
                    system("cls");
                }
            } while (choice1 != 3);
            std::cout << "\n";
            std::cout << "\t\t\t\t\t\t";
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            int choice2{};
            do {
                system("cls");
                myNamespace::menuUserWorFirst();
                try {
                    std::cout << "\n\t\t\t\t\t\t";
                    if (!(std::cin >> choice2))
                        throw std::runtime_error("\n\n\n\t\t\t\t\t\tНеверный ввод данных");
                }
                catch (std::runtime_error errr) {

                    std::cout << errr.what() << std::endl;
                    std::cout << "\n\t\t\t\t\t\t";
                    system("pause");
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                    continue;
                }
                std::cin.clear();
                std::cin.ignore(1024, '\n');
                system("cls");
                switch (choice2)
                {
                case 1:
                {
                    Worker* a = myNamespace::registrationWorker(workers, codes);
                    if (a != NULL)
                    {
                        workers.push_back(a);
                        current_workers++;
                    }
                    std::cout << "\n";
                    std::cout << "\t\t\t\t\t";
                    system("pause");
                    system("cls");
                    break;
                }
                case 2:
                {

                    std::cout << "\n";
                    std::cout << "\t\t\t\t\t\t";
                    Person* bbb = NULL;
                    bbb = myNamespace::authorizationWorker(workers);
                    if (bbb != NULL)
                    {
                        Person* worrr = NULL;
                        std::cout << "\n\n\n\t\t\t\t\tВы успешно авторизовались!" << std::endl;
                        int choose{};
                        do {
                            system("cls");
                            std::cout << "\n\n\n";
                            myNamespace::menuWorkerFin();
                            try {
                                std::cout << "\n\t\t\t\t\t\t";
                                if (!(std::cin >> choose))
                                    throw std::runtime_error("\n\n\n\t\t\t\t\t\tНеверный ввод данных");
                            }
                            catch (std::runtime_error errr) {

                                std::cout << errr.what() << std::endl;
                                std::cout << "\n\t\t\t\t\t\t";
                                system("pause");
                                std::cin.clear();
                                std::cin.ignore(1024, '\n');
                                continue;
                            }

                            std::cin.clear();
                            std::cin.ignore(1024, '\n');
                            system("cls");
                            switch (choose)
                            {
                            case 1:
                            {
                                if (current_films > 0)
                                {
                                    myNamespace::showFilms(current_films, films);
                                    std::cout << "\n";
                                    std::cout << "\t\t\t\t\t";
                                    system("cls");

                                    std::string film_name;
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите название фильма, к которому хотите сеанс:" << std::endl;
                                    std::cout << "\t\t\t\t\t\t";
                                    std::getline(std::cin, film_name);
                                    system("cls");

                                    int fil_flag = 0;
                                    for (int i = 0; i < current_films; i++)
                                    {
                                        if (films[i]->getName() == film_name)
                                        {
                                            fil_flag++;
                                        }
                                    }
                                    if (fil_flag == 0)
                                    {
                                        std::cout << "\n\n\n\n\n\t\t\t\t\tВ системе отсутствуют фильмы c таким названием" << std::endl;
                                    }
                                    else
                                    {
                                        int sess_year{};
                                        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите год сеанса:" << std::endl;
                                        do {
                                            sess_year = myNamespace::checkNumber(sess_year);
                                            if (sess_year < 2024 || sess_year >2027)
                                            {
                                                std::cout << "\n\t\t\t\t\t\tНеверный ввод, попробуйте сначала" << std::endl;
                                            }
                                        } while (sess_year < 2024 || sess_year >2027);
                                        system("cls");

                                        int sess_month{};
                                        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите месяц сеанса:" << std::endl;
                                        do {
                                            sess_month = myNamespace::checkNumber(sess_month);
                                            if (sess_month < 0 || sess_month > 12)
                                            {
                                                std::cout << "\n\t\t\t\t\t\tНеверный ввод, попробуйте сначала" << std::endl;
                                            }
                                        } while (sess_month < 0 || sess_month > 12);
                                        system("cls");

                                        int sess_date{};
                                        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите день сеанса:" << std::endl;
                                        do {
                                            sess_date = myNamespace::checkNumber(sess_date);
                                            if (sess_date < 0 || sess_date > 31)
                                            {
                                                std::cout << "\n\t\t\t\t\t\tНеверный ввод, попробуйте сначала" << std::endl;
                                            }
                                        } while (sess_date < 0 || sess_date > 31);
                                        system("cls");

                                        std::string time_ses;
                                        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите время сеанса(от 12:00 до 00:00):" << std::endl;
                                        time_ses = myNamespace::containsOnlyLetters1(time_ses);
                                        system("cls");

                                        int sess_hall{};
                                        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите номер зала:" << std::endl;
                                        do {
                                            sess_hall = myNamespace::checkNumber(sess_hall);
                                            if (sess_hall < 0 || sess_hall > 5)
                                            {
                                                std::cout << "\n\t\t\t\t\t\tНеверный ввод, попробуйте сначала" << std::endl;
                                            }
                                        } while (sess_hall < 0 || sess_hall > 5);
                                        system("cls");

                                        int num_tick{};
                                        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите количество билетов на сеансе (кратное 10):" << std::endl;
                                        do {
                                            num_tick = myNamespace::checkNumber(num_tick);
                                            if (num_tick < 10 || num_tick > 100 || num_tick % 10 != 0)
                                            {
                                                std::cout << "\n\t\t\t\t\t\tНеверный ввод, попробуйте сначала" << std::endl;
                                            }
                                        } while (num_tick < 10 || num_tick > 100 || num_tick % 10 != 0);
                                        system("cls");

                                        float cost_tick{};
                                        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите стоимость билетов:" << std::endl;
                                        do {
                                            cost_tick = myNamespace::checkNumberfl(cost_tick);
                                            if (cost_tick < 0 || cost_tick > 1000)
                                            {
                                                std::cout << "\n\t\t\t\t\t\tНеверный ввод, попробуйте сначала" << std::endl;
                                            }
                                        } while (cost_tick < 0 || cost_tick > 1000);
                                        system("cls");

                                        std::vector<class Ticket<std::string>*> tick;

                                        for (int i = 1; i <= num_tick / 10; i++)
                                        {
                                            for (int j = 1; j < 11; j++)
                                            {
                                                std::string randomCharacters = myNamespace::generateRandomCharacters();
                                                Ticket<std::string>* a = new Ticket<std::string>(j, i, cost_tick, randomCharacters, film_name, iduser);
                                                tick.push_back(a);
                                            }
                                        }
                                        Session* b = new Session(sess_year, sess_month, sess_date, num_tick, time_ses, current_sessions+1, sess_hall, tick,film_name);
                                        current_sessions++;
                                        for (int i = 0; i < current_films; i++)
                                        {
                                            if (films[i]->getName() == film_name)
                                            {
                                                films[i]->addSession(b);
                                                std::cout << "\n\n\n\n\n\t\t\t\t\t\tСеанс успешно добавлен!" << std::endl;
                                                break;
                                            }
                                        }
                                    }

                                }
                                else
                                {
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tВ системе отсутствуют фильмы" << std::endl;
                                }
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 2:
                            {
                                int wor_cod{};

                                std::cout << "\n\n\n\n\n\t\t\t\t\tВведите код работника, под которым вошли:" << std::endl;

                                wor_cod = myNamespace::checkNumber(wor_cod);
                                system("cls");
                                std::string prev_pass;
                                std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите старый пароль:" << std::endl;
                                std::cout << "\t\t\t\t\t\t";
                                std::getline(std::cin, prev_pass);
                                system("cls");
                                if (bbb->getWorCode() == wor_cod && bbb->getPassword() == myNamespace::kodirovka(prev_pass))
                                {
                                    std::string new_pass;
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите новый пароль:" << std::endl;
                                    std::cout << "\t\t\t\t\t\t";
                                    std::getline(std::cin, new_pass);
                                    system("cls");
                                    std::string new_pass1;
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tПодтвердите новый пароль:" << std::endl;
                                    new_pass1 = myNamespace::hiddenPassword();
                                    system("cls");
                                    if (new_pass == new_pass1)
                                    {
                                        for (int i = 0; i < current_workers; i++)
                                        {
                                            if (workers[i]->getName() == bbb->getName() && workers[i]->getLogin() == bbb->getLogin()
                                                && workers[i]->getPassword() == bbb->getPassword() && workers[i]->getWorCode() == bbb->getWorCode())
                                            {
                                                bbb->setPassword(myNamespace::kodirovka(new_pass1));
                                                std::cout << "\n\n\n\n\n\t\t\t\t\tПароль изменен" << std::endl;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        std::cout << "\n\n\n\n\n\t\t\t\t\tПароли не совпали" << std::endl;
                                    }
                                }
                                else
                                {
                                    std::cout << "\n\n\n\n\n\t\t\t\t\tКакие-то данные введены неверно" << std::endl;
                                }
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 3:
                            {
                                if (current_films > 0)
                                {
                                    myNamespace::checkSessions(current_films, films);
                                }
                                else
                                {
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tВ системе отсутствуют фильмы" << std::endl;
                                }
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");

                                break;
                            }
                            case 4:
                            {
                                std::cout << "\n\n\n\n\n\n\n\t\t\t\t";
                                break;
                            }
                            default:
                            {
                                std::cout << "\n\n\n\n\n\t\t\t\t\t\t";
                                std::cout << "Неверный ввод" << std::endl;
                                std::cout << "\n\t\t\t\t\t";
                                system("pause");
                                system("cls");
                            }
                            }
                        } while (choose != 4);
                    }
                    else {
                        std::cout << "\n\n\n\n\n\n\t\t\t\t\tВы не смогли войти в систему" << std::endl;
                    }
                    std::cout << "\n";
                    std::cout << "\t\t\t\t\t";
                    system("pause");
                    system("cls");
                    break;
                }
                case 3:
                    std::cout << "\n\n\n\n\n\n\n\t\t\t\t";
                    break;
                default:
                    std::cout << "\n\n\n\n\n\t\t\t\t\t\t";
                    std::cout << "Неверный ввод" << std::endl;
                    std::cout << "\n\t\t\t\t\t";
                    system("pause");
                    system("cls");
                }
            } while (choice2 != 3);
            std::cout << "\n";
            std::cout << "\t\t\t\t\t\t";
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            int choice3{};
            do {
                system("cls");
                myNamespace::menuWorFirst();
                try {
                    std::cout << "\n\t\t\t\t\t\t";
                    if (!(std::cin >> choice3))
                        throw std::runtime_error("\n\n\n\t\t\t\t\t\tНеверный ввод данных");
                }
                catch (std::runtime_error errr) {

                    std::cout << errr.what() << std::endl;
                    std::cout << "\n\t\t\t\t\t\t";
                    system("pause");
                    std::cin.clear();
                    std::cin.ignore(1024, '\n');
                    continue;
                }
                std::cin.clear();
                std::cin.ignore(1024, '\n');
                system("cls");
                switch (choice3)
                {
                case 1:
                {
                    if (myNamespace::authorizationAdmin(admin1) == 1)
                    {
                        int choose{};
                        std::cout << "\n\n\n\t\t\t\t\t\tВы успешно авторизовались!" << std::endl;
                        do {
                            system("cls"); 
                            std::cout << "\n\n\n";
                            myNamespace::menuAdminFin();
                            try {
                                std::cout << "\n\t\t\t\t\t\t";
                                if (!(std::cin >> choose))
                                    throw std::runtime_error("\n\n\n\t\t\t\t\t\tНеверный ввод данных");
                            }
                            catch (std::runtime_error errr) {

                                std::cout << errr.what() << std::endl;
                                std::cout << "\n\t\t\t\t\t\t";
                                system("pause");
                                std::cin.clear();
                                std::cin.ignore(1024, '\n');
                                continue;
                            }

                            std::cin.clear();
                            std::cin.ignore(1024, '\n');
                            system("cls");
                            switch (choose)
                            {
                            case 1:
                            {
                                if (current_films < 11)
                                {
                                    std::string film_name;
                                    int corNam = 0;
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите название фильма:" << std::endl;
                                    do {
                                        std::cout << "\t\t\t\t\t\t";
                                        std::getline(std::cin, film_name);
                                        for (int i = 0; i < current_films; i++)
                                        {
                                            if (film_name == films[i]->getName())
                                            {
                                                corNam++;
                                            }
                                        }
                                        if (corNam > 0)
                                        {
                                            std::cout << "\n\t\t\t\t\t\tНеверный ввод, такой фильм уже есть" << std::endl;
                                        }
                                    } while (corNam > 0);
                                    system("cls");

                                    std::string ganre_film;
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите жанр фильма:" << std::endl;
                                    ganre_film = myNamespace::containsOnlyLetters(ganre_film);
                                    system("cls");

                                    std::string cat_age;
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите возрастной жанр:(0+,6+,12+,16+,18+)" << std::endl;
                                    do {
                                        std::cout << "\t\t\t\t\t\t";
                                        std::getline(std::cin, cat_age);
                                        if (cat_age != "0+" && cat_age != "6+" && cat_age != "12+" && cat_age != "16+" && cat_age != "18+")
                                        {
                                            std::cout << "\n\t\t\t\t\t\tНеверный ввод, попробуйте сначала" << std::endl;
                                        }
                                    } while (cat_age != "0+" && cat_age != "6+" && cat_age != "12+" && cat_age != "16+" && cat_age != "18+");
                                    system("cls");

                                    int hour_film{};
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите сколько фильм идет в часах(менее 5):" << std::endl;
                                    do {
                                        hour_film = myNamespace::checkNumber(hour_film);
                                        if (hour_film < 0 || hour_film > 5)
                                        {
                                            std::cout << "\n\t\t\t\t\t\tНеверный ввод, попробуйте сначала" << std::endl;
                                        }
                                    } while (hour_film < 0 || hour_film > 5);
                                    system("cls");

                                    int min_film{};
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите сколько фильм идет в минутах:" << std::endl;
                                    do {
                                        min_film = myNamespace::checkNumber(min_film);
                                        if (min_film < 0 || min_film > 59)
                                        {
                                            std::cout << "\n\t\t\t\t\t\tНеверный ввод, попробуйте сначала" << std::endl;
                                        }
                                    } while (min_film < 0 || min_film > 59);

                                    Film* fl = new Film(ganre_film, film_name, hour_film, min_film, cat_age);
                                    std::cout << "\n\n\t\t\t\t\t\tФильм успешно включен в прокат" << std::endl;
                                    films[current_films] = fl;
                                    current_films++;
                                }
                                else
                                {
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tМаксимальное количество фильмов в прокате" << std::endl;
                                }
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t   ";
                                system("pause");
                                system("cls");

                                break;
                            }
                            case 2:
                            {
                                if (current_films > 0)
                                {
                                    myNamespace::showFilms(current_films, films);
                                    std::string fil_del;
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите фильм, который хотите убрать из проката:" << std::endl;
                                    std::cout << "\n";
                                    std::cout << "\t\t\t\t\t";
                                    std::getline(std::cin, fil_del);
                                    int cur = method.deleteSmth(films, fil_del, current_films);
                                    if (cur >= 0)
                                    {
                                        for (int j = cur; j < current_films; j++)
                                        {
                                            films[j] = films[j + 1];
                                        }
                                        current_films--;
                                        std::cout << "\n\t\t\t\t\tУспешно удален" << std::endl;
                                    }
                                    else
                                    {
                                        std::cout << "\n\t\t\t\t\tОтсутствует фильм с таким названием" << std::endl;
                                    }
                                }
                                else
                                {
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tВ системе отсутствуют фильмы" << std::endl;
                                }
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 3:
                            {
                                if (workers.size() != 0)
                                {
                                    std::cout << "\t\t\t\t--------------------------------------------------------------\n";
                                    std::cout << "\t\t\t\t|                          РАБОТНИКИ                         |\n";
                                    std::cout << "\t\t\t\t--------------------------------------------------------------\n";
                                    std::cout << "\t\t\t\t" << '|' << std::setw(30) << std::left << "Имя " << '|' << std::setw(29) << "Код вхождения " << '|' << "\n";
                                    std::cout << "\t\t\t\t--------------------------------------------------------------\n";
                                    for (int i = 0; i < workers.size(); i++)
                                    {
                                        workers[i]->showData();
                                    }
                                    std::cout << "\n";
                                    std::cout << "\t\t\t\t\t";
                                    system("pause");
                                    system("cls");
                                    std::string name_work;
                                    std::cout << "\n\n\n\n\n\n\n\t\t\t\t\t";
                                    std::cout << "Введите имя работника, которого хотите исключить" << std::endl;
                                    std::cout << "\n";
                                    std::cout << "\t\t\t\t\t";
                                    std::getline(std::cin, name_work);

                                    int cur_w = current_workers - del_workers;
                                    if (method.deleteSmth(workers, name_work, cur_w) >= 0)
                                    {
                                        workers.erase(workers.begin() + method.deleteSmth(workers, name_work, cur_w));
                                        std::cout << "\n\t\t\t\t\tУспешно удален" << std::endl;
                                        del_workers++;
                                        current_workers--;
                                    }
                                    else
                                    {
                                        std::cout << "\n\t\t\t\t\tОтсутствует работник с таким именем" << std::endl;
                                    }
                                }
                                else
                                {
                                    std::cout << "\n\n\n\n\n\n\t\t\t\t\t\tОтсутствуют работники в системе" << std::endl;
                                }
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 4:
                            {
                                if (users.size() != 0)
                                {
                                    std::cout << "\t\t------------------------------------------------------------------------------------\n";
                                    std::cout << "\t\t|                                    ПОЛЬЗОВАТЕЛИ                                  |\n";
                                    std::cout << "\t\t------------------------------------------------------------------------------------\n";
                                    std::cout << "\t\t" << '|' << std::setw(30) << std::left << "Имя " << '|' << std::setw(20) << "Год рождения " << '|' << std::setw(12) << "Месяц рождения |" << std::setw(14) << "День рождения |\n";
                                    std::cout << "\t\t------------------------------------------------------------------------------------\n";
                                    for (int i = 0; i < users.size(); i++)
                                    {
                                        users[i]->showData();
                                    }
                                    std::cout << "\n";
                                    std::cout << "\t\t\t\t\t";
                                    system("pause");
                                    system("cls");
                                    std::string name_work;
                                    std::cout << "\n\n\n\n\n\n\n\t\t\t\t";
                                    std::cout << "Введите имя пользовтеля, которого хотите исключить" << std::endl;
                                    std::cout << "\n";
                                    std::cout << "\t\t\t\t\t";
                                    std::getline(std::cin, name_work);
                                    if (method.deleteSmth(users, name_work, current_users) >= 0)
                                    {
                                        users.erase(users.begin() + method.deleteSmth(users, name_work, current_users));
                                        std::cout << "\n\t\t\t\t\tУспешно удален" << std::endl;
                                        current_users--;
                                    }
                                    else
                                    {
                                        std::cout << "\n\t\t\t\t\tОтсутствует пользователь с таким именем" << std::endl;
                                    }
                                }
                                else
                                {
                                    std::cout << "\n\n\n\n\n\n\t\t\t\t\t\tОтсутствуют пользователи в системе" << std::endl;
                                }

                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 5:
                            {
                                if (current_films > 0)
                                {
                                    myNamespace::checkSessions(current_films, films);
                                }
                                else
                                {
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tВ системе отсутствуют фильмы" << std::endl;
                                }
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 6:
                            {
                                if (current_films > 0)
                                {
                                    myNamespace::checkSessionsData(current_films, films);
                                }
                                else
                                {
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tВ системе отсутствуют фильмы" << std::endl;
                                }
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 7:
                            {
                                if (current_films > 0)
                                {
                                    myNamespace::showFilmsProdolg(current_films, films);
                                }
                                else
                                {
                                    std::cout << "\n\n\n\n\n\t\t\t\t\tВ системе отсутствуют фильмы" << std::endl;
                                }
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 8:
                            {
                                if (current_films > 0)
                                {
                                    myNamespace::showFilms(current_films, films);
                                }
                                else
                                {
                                    std::cout << "\n\n\n\n\n\t\t\t\t\tВ системе отсутствуют фильмы" << std::endl;
                                }
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 9:
                            {
                                if (current_films > 0)
                                {
                                    myNamespace::searchFilm(current_films, films);
                                }
                                else
                                {
                                    std::cout << "\n\n\n\n\n\t\t\t\t\t\tВ системе отсутствуют фильмы" << std::endl;
                                }
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 10:
                            {
                                int sort{};
                                do {
                                    if (current_films > 0)
                                    {
                                        std::cout << "\n\n\n\t\t\t\t\t1. Сортировка по жанру" << std::endl;
                                        std::cout << "\t\t\t\t\t2. Сортировка по названию" << std::endl;
                                        std::cout << "\t\t\t\t\t3. Сортировка по продолжительности" << std::endl;
                                        std::cout << "\t\t\t\t\t4. Выход" << std::endl;
                                        std::cout << "\t\t\t\t\t Ваш выбор?\n" << std::endl;
                                        try {
                                            std::cout << "\n\t\t\t\t\t\t";
                                            if (!(std::cin >> sort))
                                                throw std::runtime_error("\n\n\n\t\t\t\t\t\tНеверный ввод данных");
                                        }
                                        catch (std::runtime_error errr) {

                                            std::cout << errr.what() << std::endl;
                                            std::cout << "\n\t\t\t\t\t\t";
                                            system("pause");
                                            std::cin.clear();
                                            std::cin.ignore(1024, '\n');
                                            continue;
                                        }
                                        system("cls");
                                        myNamespace::sortFilms(films, current_films, sort);
                                    }
                                    else
                                    {
                                        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВ системе отсутствуют фильмы" << std::endl;
                                    }
                                } while (sort != 4);
                                std::cout << "\n";
                                std::cout << "\t\t\t\t\t";
                                system("pause");
                                system("cls");
                                break;
                            }
                            case 11:
                            {
                                std::cout << "\n\n\n\n\n\n\n\t\t\t\t";
                                break;
                            }
                            default:
                            {
                                std::cout << "\n\n\n\n\n\t\t\t\t\t\t";
                                std::cout << "Неверный ввод" << std::endl;
                                std::cout << "\n\t\t\t\t\t";
                                system("pause");
                                system("cls");
                            }
                            }
                        } while (choose != 11);
                    }
                    else {
                        std::cout << "\n\n\n\n\n\n\t\t\t\t\tВы не смогли войти в систему" << std::endl;
                    }
                    std::cout << "\n";
                    std::cout << "\t\t\t\t\t";
                    system("pause");
                    system("cls");
                    break;
                }
                case 2:
                    std::cout << "\n\n\n\n\n\n\n\t\t";
                    break;
                default:
                    std::cout << "\n\n\n\n\n\t\t\t\t\t\t";
                    std::cout << "Неверный ввод" << std::endl;
                    std::cout << "\n\t\t\t\t";
                    system("pause");
                    system("cls");
                }
            } while (choice3 != 2);
            std::cout << "\n";
            std::cout << "\t\t\t\t\t";
            system("pause");
            system("cls");
            break;
        }
        case 4:
            std::cout << "\n\n\n\n\n\n\n\t\t\t\t";
            myNamespace::outputWorkers(workers);
            myNamespace::outputFilmsToFilms(films, current_films);
           /* myNamespace::outputSessionsToFilms(films, current_films);
            myNamespace::outputTicketsToFilms(films, current_films);*/
            break;
        default:
            std::cout << "\n\n\n\n\n\t\t\t\t\t\t";
            std::cout << "Неверный ввод" << std::endl;
            std::cout << "\n\t\t\t\t\t";
            system("pause");
            system("cls");
        }
    } while (choice != 4);
    return 0;
}