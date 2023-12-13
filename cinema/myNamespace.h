#pragma once
#include "User.h"
#include "Worker.h"
#include "Admin.h"
#include "Film.h"

class Method
{
public:
    template<typename T>
    int deleteSmth(T first, std::string second, int cur)
    {
        int flag = 0;
        int fl;
        if (cur > 0)
        {
            for (int i = 0; i < cur; i++)
            {
                if (first[i]->getName() == second)
                {
                    fl = i;
                    flag++;
                    break;
                }
            }
            if (flag == 0)
            {
                return -1;
            }
            else
            {
                return fl;
            }
        }
        else
        {
            return -1;
        }
    }
};

namespace myNamespace
{
    std::string hiddenPassword();
    User* registrationUser(std::vector<User*> users,int id);
    User* authorizationUser(std::vector<User*> users);
    Worker* registrationWorker(std::vector<Worker*> workers, int code[3]);
    Worker* authorizationWorker(std::vector<Worker*> workers);
    int kolb(std::string w);
    int checkLogUser(std::vector <User*> users, std::string kod);
    int checkLogWorker(std::vector <Worker*> workers, std::string kod);
    std::string containsOnlyLetters(std::string str);
    int checkNumber(int a);
    int authorizationAdmin(std::unique_ptr<Admin>& admin1);
    float checkNumberfl(float a);
    void showFilms(int current_films, std::array <Film*, 10> films);
    std::string generateRandomCharacters();
    std::string containsOnlyLetters1(std::string str);
    void checkSessions(int current_films, std::array <Film*, 10> films);
    Film* checkSessions1(int current_films, std::array <Film*, 10> films);
    void sortFilms(std::array<Film*, 10> films, int current_films, int a);
    void showFilmsProdolg(int current_films, std::array <Film*, 10> films);
    void searchFilm(int current_films, std::array <Film*, 10> films);
    void menuFull();
    void menuUserWorFirst();
    void menuWorFirst();
    void menuUserFin();
    void menuAdminFin();
    void menuWorkerFin();
    void outputTicketsToFilms(std::array <Film*, 10> films, int cur_films);
    std::vector<class Ticket<std::string>*> inputTicketsFromFile(std::vector<class Ticket<std::string>*> tickets);
    std::vector <Session*> inputSessionsFromFile(std::vector <Session*> sessions);
    void outputSessionsToFilms(std::array <Film*, 10> films, int cur_films);
    int inputFilmsFromFile(std::array <Film*, 10>& films);
    void outputFilmsToFilms(std::array <Film*, 10> films, int cur_films);
    std::string kodirovka(std::string text);
    void outputWorkers(std::vector<Worker*> workers);
    int inputWorkersFromFile(std::vector<Worker*>& workers);
    void outputUsers(std::vector<User*> users);
    int inputUsersFromFile(std::vector<User*>& users);
    void otchetFilms(int current_films, std::array <Film*, 10> films);

    void menuFull()
    {
        std::cout << "\n\n\n\n\n\n\t\t\t\t\t\tВозможные роли:" << std::endl;
        std::cout << "\t\t\t\t\t\t1. Пользователь" << std::endl;
        std::cout << "\t\t\t\t\t\t2. Работник" << std::endl;
        std::cout << "\t\t\t\t\t\t3. Администратор" << std::endl;
        std::cout << "\t\t\t\t\t\t4. Выход" << std::endl;
        std::cout << "\n\t\t\t\t\t\tСделайте свой выбор:" << std::endl;
    }

    void menuUserWorFirst()
    {
        std::cout << "\n\n\n\n\n\n\t\t\t\t\t\t1. Регистрация" << std::endl;
        std::cout << "\t\t\t\t\t\t2. Авторизация" << std::endl;
        std::cout << "\t\t\t\t\t\t3. Выход" << std::endl;
        std::cout << "\n\t\t\t\t\t\tСделайте свой выбор:" << std::endl;
    }

    void menuWorFirst()
    {
        std::cout << "\n\n\n\n\n\n\t\t\t\t\t\t1. Авторизация" << std::endl;
        std::cout << "\t\t\t\t\t\t2. Выход" << std::endl;
        std::cout << "\n\t\t\t\t\t\tСделайте свой выбор:" << std::endl;
    }

    void menuUserFin()
    {
        std::cout << "\t\t\t\t\t1. Ввести количество средств, которое пользователь может потратить" << std::endl;
        std::cout << "\t\t\t\t\t2. Изучить сеансы" << std::endl;
        std::cout << "\t\t\t\t\t3. Купить билет" << std::endl;
        std::cout << "\t\t\t\t\t4. Поиск фильма по названию" << std::endl;
        std::cout << "\t\t\t\t\t5. Сортировка фильмов" << std::endl;
        std::cout << "\t\t\t\t\t6. Поиск сеансов по дате" << std::endl;
        std::cout << "\t\t\t\t\t7. Изучить список доступных в прокате фильмов" << std::endl;
        std::cout << "\t\t\t\t\t8. Отфильтровать фильмы по продолжительности" << std::endl;
        std::cout << "\t\t\t\t\t9. Изучить список купленных билетов" << std::endl;
        std::cout << "\t\t\t\t\t10. Изучить количество средств на счету" << std::endl;
        std::cout << "\t\t\t\t\t11. Выход" << std::endl;
        std::cout << "\n\t\t\t\t\tСделайте свой выбор:" << std::endl;
    }

    void menuAdminFin()
    {
        std::cout << "\t\t\t\t\t\t1. Включить фильм в прокат" << std::endl;
        std::cout << "\t\t\t\t\t\t2. Убрать фильм из проката" << std::endl;
        std::cout << "\t\t\t\t\t\t3. Уволить сотрудника" << std::endl;
        std::cout << "\t\t\t\t\t\t4. Исключить пользователя из системы" << std::endl;
        std::cout << "\t\t\t\t\t\t5. Изучить сеансы" << std::endl;
        std::cout << "\t\t\t\t\t\t6. Поиск сеансов по дате" << std::endl;
        std::cout << "\t\t\t\t\t\t7. Отфильтровать фильмы по продолжительности" << std::endl;
        std::cout << "\t\t\t\t\t\t8. Изучить список доступных в прокате фильмов" << std::endl;
        std::cout << "\t\t\t\t\t\t9. Поиск фильма по названию" << std::endl;
        std::cout << "\t\t\t\t\t\t10. Сортировка фильмов" << std::endl;
        std::cout << "\t\t\t\t\t\t11. Выход" << std::endl;
        std::cout << "\n\t\t\t\t\t\tСделайте свой выбор:" << std::endl;
    }

    void menuWorkerFin()
    {
        std::cout << "\t\t\t\t\t1. Добавить сеанс к фильму" << std::endl;
        std::cout << "\t\t\t\t\t2. Изменение пароля" << std::endl;
        std::cout << "\t\t\t\t\t3. Изучить сеансы" << std::endl;
        std::cout << "\t\t\t\t\t4. Выход" << std::endl;
        std::cout << "\n\t\t\t\t\tСделайте свой выбор:" << std::endl;
    }

    float checkNumberfl(float a) {
        while (true) {

            std::cout << "\t\t\t\t\t\t\t";
            std::cin >> a;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                std::cout << "\t\t\t\t\t\t\t";
                std::cout << "Неверный ввод." << std::endl;
                continue;
            }
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            if (std::cin.gcount() > 1) {
                std::cout << "\t\t\t\t\t\t\t";
                std::cout << "Неверный ввод." << std::endl;
                continue;
            }
            break;
        }
        return a;
    }

    std::string hiddenPassword() {
        char c;
        std::string password = "";
        std::cout << "\t\t\t\t\t\t";
        while (true) {
            c = _getch();
            if (c == 13) {
                break;
            }
            else if (c == 8 && password.size()) {
                password.pop_back();
                std::cout << '\b' << ' ' << '\b';
            }
            else if (c != 8) {
                std::cout << '*';
                password.push_back(c);
            }
        }
        std::cout << '\n';
        return password;
    }

    User* registrationUser(std::vector<User*> users, int id)
    {
        std::string kod;
        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите логин:" << std::endl;
        do {
            std::cout << "\t\t\t\t\t\t";
            std::getline(std::cin, kod);
        } while (!checkLogUser(users, kod) || kolb(kod) < 8);
        system("cls");

        std::string pass;
        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите пароль:" << std::endl;
        do {
            pass = hiddenPassword();
        } while (kolb(pass) < 8);
        system("cls");
        std::string name_pers;
        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите вашу фамилию и имя:" << std::endl;
        do {
            name_pers = containsOnlyLetters(name_pers);
            if (name_pers == "\0")
            {
                std::cout << "\n\n\t\t\t\t\t\tНеверный ввод данных" << std::endl;
            }
        } while (name_pers == "\0");

        system("cls");
        std::string email_pers;
        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите ваш email:" << std::endl;
        std::cout << "\t\t\t\t\t\t";
        std::getline(std::cin, email_pers);

        system("cls");
        int year{};
        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите ваш год рождения:" << std::endl;
        do {
            year = checkNumber(year);
            if (year < 1900 || year>2023)
            {
                std::cout << "\n\n\t\t\t\t\t\tНеверный ввод данных" << std::endl;
            }
        } while (year < 1900 || year>2023);

        system("cls");
        int month{};
        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите ваш месяц рождения:" << std::endl;
        do {
            month = checkNumber(month);
            if (month < 0 || month>12)
            {
                std::cout << "\n\n\t\t\t\t\t\tНеверный ввод данных" << std::endl;
            }
        } while (month < 0 || month>12);

        system("cls");
        int date{};
        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите ваш день рождения:" << std::endl;
        do {
            date = checkNumber(date);
            if (date < 0 || date>31)
            {
                std::cout << "\n\n\t\t\t\t\t\tНеверный ввод данных" << std::endl;
            }
        } while (date < 0 || date>31);

        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВы успешно зарегистрировались" << std::endl;

        User* pers = new User(name_pers, kod, kodirovka(pass), email_pers, year, month, date, 0,id);
        return pers;
    }
    User* authorizationUser(std::vector<User*> users)
    {
        std::string checklog;
        std::string checkpass;
        int flag = 0;
        User* a = NULL;
        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите логин:" << std::endl;
        do {
            std::cout << "\t\t\t\t\t\t";
            std::getline(std::cin, checklog);
        } while (kolb(checklog) < 8);
        system("cls");

        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите пароль" << std::endl;
        do {
            checkpass = hiddenPassword();

        } while (kolb(checkpass) < 8);
        system("cls");

        for (int i = 0; i < users.size(); i++)
        {
            if (users[i]->getLogin() == checklog && users[i]->getPassword() == kodirovka(checkpass))
            {
                a = users[i];
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            return a;
        }
        else
        {
            return a;
        }
        system("cls");

    }

    Worker* registrationWorker(std::vector<Worker*> workers, int code[3])
    {
        std::string kod;
        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите логин:" << std::endl;
        do {
            std::cout << "\t\t\t\t\t\t";
            std::getline(std::cin, kod);
        } while (!checkLogWorker(workers, kod) || kolb(kod) < 8);
        system("cls");

        std::string pass;
        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите пароль:" << std::endl;
        do {
            pass = hiddenPassword();
        } while (kolb(pass) < 8);
        system("cls");
        std::string name_wor;
        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите вашу фамилию и имя:" << std::endl;
        do {
            name_wor = containsOnlyLetters(name_wor);
            if (name_wor == "\0")
            {
                std::cout << "\n\n\t\t\t\t\t\tНеверный ввод данных" << std::endl;
            }
        } while (name_wor == "\0");

        system("cls");
        int spec_code{};
        int flag = 0;
        std::cout << "\n\n\n\n\n\t\t\t\t\tВведите специальный код, подтверждающий, что вы работник:\n\n";
        spec_code = checkNumber(spec_code);
        for (int i = 0; i < 3; i++)
        {
            if (spec_code == code[i])
            {
                flag++;
                break;
            }
        }
        if (flag == 1)
        {
            std::cout << "\n\n\n\n\n\t\t\t\t\tВы успешно зарегистрировались" << std::endl;
            Worker* pers = new Worker(kod, kodirovka(pass), name_wor, spec_code);
            return pers;

        }
        else
        {
            std::cout << "\t\t\t\t\tК сожалению код не подходит(" << std::endl;
            return NULL;
        }

    }
    Worker* authorizationWorker(std::vector<Worker*> workers)
    {
        std::string checklog;
        std::string checkpass;
        std::string name_wor;
        int flag = 0;
        Worker* a = NULL;

        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите имя и фамилию:" << std::endl;
        do {
            name_wor = containsOnlyLetters(name_wor);
            if (name_wor == "\0")
            {
                std::cout << "\n\n\t\t\t\t\t\tНеверный ввод данных" << std::endl;
            }
        } while (name_wor == "\0");
        system("cls");

        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите логин:" << std::endl;
        do {
            std::cout << "\t\t\t\t\t\t";
            std::getline(std::cin, checklog);
        } while (kolb(checklog) < 8);
        system("cls");
        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите пароль" << std::endl;
        do {
            checkpass = hiddenPassword();

        } while (kolb(checkpass) < 8);
        system("cls");
        std::string pas = kodirovka(checkpass);
        for (int i = 0; i < workers.size(); i++)
        {
            if (workers[i]->getLogin() == checklog && workers[i]->getPassword() == pas && workers[i]->getName() == name_wor)
            {
                a = workers[i];
                flag++;
                break;
            }
        }
        if (flag == 1)
        {
            return a;
        }
        else
        {
            return a;
        }
    }

    int kolb(std::string w)
    {
        int q = 0;
        for (int i = 0; w[i] != '\0'; i++)
        {
            q++;
        }
        if (q < 8)
        {
            std::cout << "\n\t\t\t\t\t";
            std::cout << "Маленькое количество символов" << std::endl;
        }
        return q;
    }

    int checkLogUser(std::vector <User*> users, std::string kod)
    {
        int a = 0;
        for (int i = 0; i < users.size(); i++)
        {
            if (kod == users[i]->getLogin())
            {
                a++;
                std::cout << "\t\t\t\t\t\t";
                std::cout << "Такой логин уже существует" << std::endl;

            }
        }
        if (a == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int checkLogWorker(std::vector <Worker*> workers, std::string kod)
    {
        int a = 0;
        for (int i = 0; i < workers.size(); i++)
        {
            if (kod == workers[i]->getLogin())
            {
                a++;
                std::cout << "\t\t\t\t\t\t";
                std::cout << "Такой логин уже существует" << std::endl;
            }
        }
        if (a == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    std::string containsOnlyLetters(std::string str) {
        while (true) {
            std::cout << "\t\t\t\t\t\t";
            std::getline(std::cin, str);
            if (str.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯйцукенгшщзхъфывапролджэячсмитьбюёqwertyuiopasdfghjklzxcvbnm ") ==
                std::string::npos) {
                break;
            }
            else {
                std::cout << "\t\t\t\t\t\t";
                std::cout << "\n\t\t\t\t\tНеверно введенные данные. Try again." << std::endl;
                continue;
            }

        }
        return str;
    }

    std::string containsOnlyLetters1(std::string str) {
        while (true) {
            std::cout << "\t\t\t\t\t\t";
            std::getline(std::cin, str);
            if (str.find_first_not_of("1234567890 :") ==
                std::string::npos) {
                break;
            }
            else {
                std::cout << "\t\t\t\t\t\t";
                std::cout << "\n\t\t\t\t\tНеверно введенные данные. Try again." << std::endl;
                continue;
            }

        }
        return str;
    }

    int checkNumber(int a) {
        while (true) {
            std::cout << "\t\t\t\t\t\t";
            std::cin >> a;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                std::cout << "\t\t\t\t\t\t\t";
                std::cout << "Неверный ввод." << std::endl;
                continue;
            }
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            if (std::cin.gcount() > 1) {
                std::cout << "\t\t\t\t\t\t\t";
                std::cout << "Неверный ввод." << std::endl;
                continue;
            }
            break;
        }
        return a;
    }

    int authorizationAdmin(std::unique_ptr<Admin>& admin1)
    {
        std::string checklog;
        std::string checkpass;
        std::string name_wor;
        std::string checkCode{};
        int flag = 0;

        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите имя и фамилию:" << std::endl;
        do {
            name_wor = containsOnlyLetters(name_wor);
            if (name_wor == "\0")
            {
                std::cout << "\n\n\t\t\t\t\t\tНеверный ввод данных" << std::endl;
            }
        } while (name_wor == "\0");
        system("cls");

        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите логин:" << std::endl;
        do {
            std::cout << "\t\t\t\t\t\t";
            std::getline(std::cin, checklog);
        } while (kolb(checklog) < 8);
        system("cls");

        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите пароль" << std::endl;
        do {
            checkpass = hiddenPassword();
        } while (kolb(checkpass) < 8);
        system("cls");

        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите код" << std::endl;
        do {
            checkCode = hiddenPassword();
        } while (kolb(checkpass) < 8);

        if (admin1->getName() == name_wor && admin1->getLogin() == checklog && admin1->getPassword() == kodirovka(checkpass)
            && admin1->getAdminCode() == checkCode)
        {
            flag++;
        }
        system("cls");
        return flag;
    }

    void showFilms(int current_films, std::array <Film*, 10> films)
    {
        if (current_films > 0)
        {
            std::cout << "\t\t---------------------------------------------------------------------------------------------\n";
            std::cout << "\t\t|                                         ФИЛЬМЫ                                            |\n";
            std::cout << "\t\t---------------------------------------------------------------------------------------------\n";
            std::cout << "\t\t" << '|' << std::setw(30) << std::left << "Название " << '|' << std::setw(20) << "Жанр " << '|' << std::setw(15) << "Категория" << "|" << std::setw(12) << "Часы" << "|" << std::setw(10) << "Минуты" << "| \n";
            std::cout << "\t\t---------------------------------------------------------------------------------------------\n";
            for (int i = 0; i < current_films; i++)
            {
                films[i]->showData();
            }
            std::cout << "\n";
            std::cout << "\t\t\t\t\t";
            system("pause");
            system("cls");
        }
        else
        {
            std::cout << "\n\n\n\n\n\t\t\t\t\t\tВ системе отсутствуют фильмы" << std::endl;
        }
    }

    std::string generateRandomCharacters() {
        std::string result;
        const std::string characters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const int length = 10;

        srand(time(0));

        for (int i = 0; i < length; i++) {
            int randomIndex = rand() % characters.length();
            result += characters[randomIndex];
        }

        return result;
    }

    void checkSessions(int current_films, std::array <Film*, 10> films)
    {
        myNamespace::showFilms(current_films, films);
        std::cout << "\n";
        std::cout << "\t\t\t\t\t";
        system("cls");

        std::string film_name;
        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите название фильма, на который хотите просмотреть сеансы:" << std::endl;
        std::cout << "\t\t\t\t\t\t";
        std::getline(std::cin, film_name);
        system("cls");

        int flaggg = 0;
        for (int i = 0; i < current_films; i++)
        {
            if (film_name == films[i]->getName())
            {
                flaggg++;
                films[i]->showSessions();
                break;
            }
        }
        if (flaggg == 0)
        {
            std::cout << "\n\n\n\n\n\t\t\t\t\tОтсутствует фильм с таким названием в системе" << std::endl;
        }
    }

    Film* checkSessions1(int current_films, std::array <Film*, 10> films)
    {
        myNamespace::showFilms(current_films, films);
        std::cout << "\n";
        std::cout << "\t\t\t\t\t";
        system("cls");

        std::string film_name;
        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите название фильма, на который хотите просмотреть сеансы:" << std::endl;
        std::cout << "\t\t\t\t\t\t";
        std::getline(std::cin, film_name);
        system("cls");

        int flaggg = 0;
        for (int i = 0; i < current_films; i++)
        {
            if (film_name == films[i]->getName())
            {
                flaggg++;
                films[i]->showSessionsSpecial();
                return films[i];
                break;
            }
        }
        if (flaggg == 0)
        {
            std::cout << "\n\n\n\n\n\t\t\t\tОтсутствует фильм с таким названием в системе" << std::endl;
            return NULL;
        }
    }

    void checkHall(Session* a, float cost)
    {
        int flag = 0;
        std::vector<class Ticket<std::string>*> tick = a->getVect();
        for (int row = 1; row <= (a->getCollTick() / 10); ++row) {
            std::cout << "Ряд " << row << ": ";
            for (int seat = 1; seat <= 10; ++seat) {
                if (tick[flag]->getUserId() == 0)
                {
                    std::cout << row << "(" << seat << ")" << " ";
                }
                else
                {
                    std::cout << "X" << " ";
                }
                flag++;
            }
            std::cout << "\n";
        }

        std::cout << "\nГде 'X' - место занято, а стоимость билета - " << cost << "\n";
    }

    void sortFilms(std::array<Film*, 10> films, int current_films, int a) {
        std::array<Film*, 10> film = films;
        if (a == 1) {
            for (int i = 0; i < current_films - 1; i++) {
                for (int j = 0; j < current_films - i - 1; j++) {
                    if (film[j]->getGanre() > film[j + 1]->getGanre()) {
                        Film* temp = film[j];
                        film[j] = film[j + 1];
                        film[j + 1] = temp;
                    }
                }
            }
            showFilms(current_films, film);
        }
        else if (a == 2) {
            for (int i = 0; i < current_films - 1; i++) {
                for (int j = 0; j < current_films - i - 1; j++) {
                    if (film[j]->getName() > film[j + 1]->getName()) {
                        Film* temp = film[j];
                        film[j] = film[j + 1];
                        film[j + 1] = temp;
                    }
                }
            }
            showFilms(current_films, film);
        }
        else if (a == 3) {
            for (int i = 0; i < current_films - 1; i++) {
                for (int j = 0; j < current_films - i - 1; j++) {
                    if (film[j]->getHour() > film[j + 1]->getHour()) {
                        Film* temp = films[j];
                        film[j] = film[j + 1];
                        film[j + 1] = temp;
                    }
                    else if (film[j]->getHour() == film[j + 1]->getHour() && film[j]->getMinute() > film[j + 1]->getMinute())
                    {
                        Film* temp = films[j];
                        film[j] = film[j + 1];
                        film[j + 1] = temp;
                    }
                }
            }
            showFilms(current_films, film);
        }
    }

    void showFilmsProdolg(int current_films, std::array <Film*, 10> films)
    {
        if (current_films > 0)
        {
            std::cout << "\n\n\n\n\t\t\t\t\tВведите максимальное количество часов" << std::endl;
            int hourflm{};
            hourflm = checkNumber(hourflm);
            system("cls");
            std::cout << "\n\n\n\n\t\t\t\t\tВведите максимальное количество минут" << std::endl;
            int min{};
            min = checkNumber(min);
            system("cls");
            std::cout << "\t\t---------------------------------------------------------------------------------------------\n";
            std::cout << "\t\t|                                         ФИЛЬМЫ                                            |\n";
            std::cout << "\t\t---------------------------------------------------------------------------------------------\n";
            std::cout << "\t\t" << '|' << std::setw(30) << std::left << "Название " << '|' << std::setw(20) << "Жанр " << '|' << std::setw(15) << "Категория" << "|" << std::setw(12) << "Часы" << "|" << std::setw(10) << "Минуты" << "| \n";
            std::cout << "\t\t---------------------------------------------------------------------------------------------\n";
            for (int i = 0; i < current_films; i++)
            {
                if (films[i]->getHour() < hourflm)
                {
                    films[i]->showData();
                }
                else if (films[i]->getHour() == hourflm && films[i]->getMinute() <= min)
                {
                    films[i]->showData();
                }

            }
            std::cout << "\n";
            std::cout << "\t\t\t\t\t";
            system("pause");
            system("cls");
        }
        else
        {
            std::cout << "\n\n\n\n\n\t\t\t\t\t\tВ системе отсутствуют фильмы" << std::endl;
        }
    }

    void searchFilm(int current_films, std::array <Film*, 10> films)
    {
        Film* sear = NULL;
        if (current_films > 0)
        {
            std::string film_name;
            int corNam = 0;
            std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите название фильма:" << std::endl;
            std::cout << "\t\t\t\t\t\t";
            std::getline(std::cin, film_name);
            system("cls");
            for (int i = 0; i < current_films; i++)
            {
                if (films[i]->getName() == film_name)
                {
                    sear = films[i];
                }
            }
            if (sear != NULL)
            {
                std::cout << "\t\t---------------------------------------------------------------------------------------------\n";
                std::cout << "\t\t|                                         ФИЛЬМЫ                                            |\n";
                std::cout << "\t\t---------------------------------------------------------------------------------------------\n";
                std::cout << "\t\t" << '|' << std::setw(30) << std::left << "Название " << '|' << std::setw(20) << "Жанр " << '|' << std::setw(15) << "Категория" << "|" << std::setw(12) << "Часы" << "|" << std::setw(10) << "Минуты" << "| \n";
                std::cout << "\t\t---------------------------------------------------------------------------------------------\n";
                sear->showData();
            }
            else
            {
                std::cout << "\n\n\n\n\n\t\t\t\t\tВ системе отсутствует фильм c таким названием" << std::endl;
            }
            std::cout << "\n";
            std::cout << "\t\t\t\t\t";
            system("pause");
            system("cls");
        }
        else
        {
            std::cout << "\n\n\n\n\n\t\t\t\t\t\tВ системе отсутствуют фильмы" << std::endl;
        }
    }

    void checkSessionsData(int current_films, std::array <Film*, 10> films)
    {
        int year{};
        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите год:" << std::endl;
        year = checkNumber(year);
        system("cls");

        int month{};
        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите месяц:" << std::endl;
        month = checkNumber(month);
        system("cls");

        int day{};
        std::cout << "\n\n\n\n\n\t\t\t\t\t\tВведите день:" << std::endl;
        day = checkNumber(day);
        system("cls");

        std::cout << "\t--------------------------------------------------------------------------------------------------\n";
        std::cout << "\t|                                              СЕАНСЫ                                            |\n";
        std::cout << "\t--------------------------------------------------------------------------------------------------\n";
        std::cout << "\t" << '|' << std::setw(10) << std::left << "Год " << '|' << std::setw(10) << "Месяц " << '|' << std::setw(10) << "День" << "|" << std::setw(13) << "Время начала " << "|"
            << std::setw(7) << "Зал " << "|" << std::setw(15) << "Кол-во билетов" << "|" << std::setw(25) << "Название фильма" << "| \n";
        std::cout << "\t--------------------------------------------------------------------------------------------------\n";
        int flaggg = 0;
        for (int i = 0; i < current_films; i++)
        {
            std::vector<Session*> sess = films[i]->getSess();
            if (sess.size() != 0)
            {
                for (int j = 0; j < sess.size(); j++)
                {
                    if (sess[j]->getYear() == year && sess[j]->getMonth() == month && sess[j]->getDay() == day)
                    {
                        sess[j]->showDataForCheck();
                    }
                }
            }
        }
    }

    void outputFilmsToFilms(std::array <Film*, 10> films, int cur_films)
    {
        std::ofstream file("film.txt");
        if (file.is_open()) {
            for (int i = 0; i < cur_films; i++)
            {
                file << films[i];
            }
            file.close();
        }
        else {
            std::cout << "Файл не открыт" << std::endl;
        }

    }
    int inputFilmsFromFile(std::array <Film*, 10>& films)
    {
        int cur_films = 0;
        std::ifstream inputFile("film.txt", std::ios::app); // открываем файл для чтения

        while (!inputFile.eof()) {
            Film* film = new Film();
            if (inputFile >> film)
            {
                if (!film->getCategory().size()) { break; }
                films[cur_films] = film;
                cur_films++;
            }
        }

        inputFile.close();
        return cur_films;
    }

    void outputSessionsToFilms(std::array <Film*, 10> films, int cur_films)
    {
        std::ofstream file("sessions.txt");
        if (file.is_open()) {
            for (int i = 0; i < cur_films; i++)
            {
                for (int j = 0; j < films[i]->getSess().size(); j++)
                {
                    file << films[i]->getSess()[j];
                }
            }
            file.close();
        }
        else {
            std::cout << "Файл не открыт" << std::endl;
        }

    }
    std::vector <Session*> inputSessionsFromFile(std::vector <Session*> sessions)
    {
        std::ifstream inputFile("sessions.txt", std::ios::app); // открываем файл для чтения

        while (!inputFile.eof()) {
            Session* sess = new Session();
            if (inputFile >> sess)
            {
                sessions.push_back(sess);
            }
        }
        inputFile.close();
        return sessions;
    }

    void outputTicketsToFilms(std::array <Film*, 10> films, int cur_films)
    {
        std::ofstream file("ticket.txt");
        if (file.is_open()) {
            for (int i = 0; i < cur_films; i++)
            {
                for (int j = 0; j < films[i]->getSess().size(); j++)
                {
                    for (int k = 0; k<films[i]->getSess()[j]->getVect().size(); k++)
                    {
                        file << films[i]->getSess()[j]->getVect()[k];
                    }
                }
            }
            file.close();
        }
        else {
            std::cout << "Файл не открыт" << std::endl;
        }

    }
    std::vector<class Ticket<std::string>*> inputTicketsFromFile(std::vector<class Ticket<std::string>*> tickets)
    {
        std::ifstream inputFile("ticket.txt", std::ios::app);

        while (!inputFile.eof()) {
            Ticket<std::string>* a = new Ticket<std::string>();
            if (inputFile >> a)
            {
                tickets.push_back(a);
            }
        }

        inputFile.close();
        return tickets;
    }

    std::string kodirovka(std::string text)
    {
        for (int i = 0; i < size(text); i++)
        {
            --text[i];
        }
        return text;
    }

    void outputWorkers(std::vector<Worker*> workers)
    {
        std::ofstream file("workers.txt");
        if (file.is_open()) {
            for (int i = 0; i < workers.size(); i++)
            {
                file << workers[i]->getLogin() << "\t" << workers[i]->getPassword() <<"\t" << workers[i]->getWorCode() << "\n" << workers[i]->getName() << std::endl;
            }
            file.close();
        }
        else {
            std::cout << "Файл не открыт" << std::endl;
        }

    }
    int inputWorkersFromFile(std::vector<Worker*>& workers)
    {
        int cur_workers = 0;
        std::ifstream inputFile("workers.txt", std::ios::app); // открываем файл для чтения

        while (!inputFile.eof()) {
            Worker* pers = new Worker();
            if (inputFile >> pers)
            {
                if (!pers->getName().size()) { break; }
                workers.push_back(pers);
                cur_workers++;
            }
        }
        return cur_workers;
        inputFile.close();
    }

    void outputUsers(std::vector<User*> users)
    {
        std::ofstream file("users.txt");
        if (file.is_open()) {
            for (int i = 0; i < users.size(); i++)
            {
                file << users[i]->getYear() << '\t' << users[i]->getMoney() << '\t' << users[i]->getMonth() << '\t' << users[i]->getDay() << '\t' << users[i]->getId() << '\t' << users[i]->getEmail() << '\t' << users[i]->getLogin() << '\t' << users[i]->getPassword() << '\n' << users[i]->getName() << std::endl;
            }
            file.close();
        }
        else {
            std::cout << "Файл не открыт" << std::endl;
        }

    }
    int inputUsersFromFile(std::vector<User*>& users)
    {
        int cur_workers = 0;
        std::ifstream inputFile("users.txt", std::ios::app); // открываем файл для чтения

        while (!inputFile.eof()) {
            User* pers = new User();
            if (inputFile >> pers)
            {
                if (!pers->getName().size()) { break; }
                users.push_back(pers);
                cur_workers++;
            }
        }
        return cur_workers;
        inputFile.close();
    }

    void otchetFilms(int current_films, std::array <Film*, 10> films)
    {
        std::ofstream file("otchet.txt");
        if (file.is_open()) 
        {
            file << "\t\t---------------------------------------------------------------------------------------------\n";
            file << "\t\t|                                         ФИЛЬМЫ                                            |\n";
            file << "\t\t---------------------------------------------------------------------------------------------\n";
            file << "\t\t" << '|' << std::setw(30) << std::left << "Название " << '|' << std::setw(20) << "Жанр " << '|' << std::setw(15) << "Категория" << "|" << std::setw(12) << "Часы" << "|" << std::setw(10) << "Минуты" << "| \n";
            file << "\t\t---------------------------------------------------------------------------------------------\n";
            for (int i = 0; i < current_films; i++)
            {
                file << "\t\t" << '|' << std::setw(30) << std::left << films[i]->getName() << '|' << std::setw(20)
                    << films[i]->getGanre() << '|' << std::setw(15) << films[i]->getCategory() << "|" << std::setw(12) << films[i]->getHour() << "|" << std::setw(10) << films[i]->getMinute() << "|" << std::endl;
                file << "\t\t---------------------------------------------------------------------------------------------\n";
            }
            file.close();
        }
        else {
            std::cout << "Файл не открыт" << std::endl;
        }
    }
}
