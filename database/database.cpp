#include "database.h"


bool database::isFileExists(const std::string &filename) {
    bool isOpen = false;

    std::ifstream datafile(usersPath + filename);
    isOpen = datafile.is_open();
    datafile.close();

    return isOpen;
}

void database::changeLoggedUser(const std::string &username) {
    std::ofstream datafile("loggedUser.txt", std::ios::trunc);

    if(datafile.is_open()) {
        datafile << username;
        datafile.close();
    }
}

std::string database::getLoggedUsername() {
    std::ifstream datafile("loggedUser.txt");

    std::string username;
    if(datafile.is_open()) {
        std::getline(datafile, username);
        datafile.close();
    }

    return username;
}

void database::addUserBalance(const unsigned int &userBalance){
    unsigned int prevBalance = getUserBalance();
    std::fstream datafile(usersPath + getLoggedUsername() + ".txt", std::ios::trunc);
    std::string tempLine;

    if(datafile.is_open()) {
        datafile << getLoggedUsername() << std::endl;
        datafile << prevBalance + userBalance;

        datafile.close();
    }
}

unsigned int database::getUserBalance() {
    std::ifstream datafile(usersPath + getLoggedUsername() + ".txt");

    unsigned int balance = 0;
    if(datafile.is_open()) {
        std::string tempLine;
        
        std::getline(datafile, tempLine);
        std::getline(datafile, tempLine);

        if(tempLine.empty()) {
            balance = 0;
        }else {
            balance = stoi(tempLine);
        }

        datafile.close();
    }

    return balance;
}

bool database::applyPassword(const std::string &aplPassword) {
    std::ifstream datafile(usersPath + getLoggedUsername() + ".txt");

    std::string userPassword;
    if(datafile.is_open()) {
        std::getline(datafile, userPassword);

        datafile.close();
    }

    return userPassword == aplPassword;
}

void database::signUp() {
    std::string username, password;

    system("cls"); 
    std::cout << "\e[1;37mLogin: \e[0m";
    std::cin >> username;

    if(database::isFileExists(username + ".txt")) {
        std::cout << "\n\e[1;31mUser signed up!\e[0m\n\n";
        
        system("pause");
        return;
    }

    std::cout << "\e[1;37mPassword: \e[0m";
    std::cin >> password;

    std::ofstream datafile(usersPath + username + ".txt");
    if(datafile.is_open()) {
        datafile << password << std::endl;
        datafile << "0";
        datafile.close();
        std::cout << "\n\e[1;32mSuccessful sign up!\e[0m\n\n";
    }else {
        std::cout << "\n\e[1;31mSomething was going wrong.\e[0m\n\n";
        system("pause");
        return;
    }

    system("pause");
}

void database::logIn() {
    std::string username, password;
    std::string applyPassword;

    system("cls");
    std::cout << "\e[1;37mLogin: \e[0m";
    std::cin >> username;
    std::cout << "\e[1;37mPassword: \e[0m";
    std::cin >> password;

    std::ifstream datafile(usersPath + username + ".txt");
    if(datafile.is_open()) {
        std::getline(datafile, applyPassword);

        if(password == applyPassword) {
            database::changeLoggedUser(username);
            std::cout << "\n\e[1;92mSuccessful log in!\e[0m\n\n"; 
        }else {
            std::cout << "\n\e[1;31mInvalid user data.\e[0m\n\n"; 
        }

        datafile.close();
    }else {
        std::cout << "\n\e[1;31mInvalid user data.\e[0m\n\n";
    }

    system("pause");
}

void database::logOut() {
    std::ofstream datafile("loggedUser.txt", std::ios::out | std::ios::trunc);
    datafile.close();
}