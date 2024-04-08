#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const std::string mainPath = "C:\\Users\\calri\\projects\\CarRent\\";
const std::string helpPath = "C:\\Users\\calri\\projects\\CarRent\\helpFiles\\";
const std::string usersPath = "C:\\Users\\calri\\projects\\CarRent\\users\\";

namespace database {
    bool isFileExists(const std::string &filename);
    void changeLoggedUser(const std::string &username);
    std::string getLoggedUsername();
    void addUserBalance(const unsigned int &userBalance);
    unsigned int getUserBalance();
    bool applyPassword(const std::string &aplPassword);
    void signUp();
    void logIn();
    void logOut();
}

#endif