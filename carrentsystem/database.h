#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>


namespace database {
    const std::string mainPath = "C:\\users\\calri\\projects\\carrentsystem\\";
    const std::string usersPath = "C:\\users\\calri\\projects\\carrentsystem\\users\\";

    void createAccount();
    bool isUsernameExists(const std::string &username);
}

#endif