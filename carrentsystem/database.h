#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>


namespace database {
    const std::string mainPath = "C:\\users\\calri\\projects\\carrentsystem\\";
    const std::string usersPath = "C:\\users\\calri\\projects\\carrentsystem\\users\\";
    const std::string addFilesPath = "C:\\users\\calri\\projects\\carrentsystem\\additionalFiles\\";

    void CreateAccount();
    bool IsUsernameExists(const std::string &username);
    bool Login();
    bool IsPasswordCorrect(const std::string &username, const std::string &enteredPassword);
    void LogInUsername(const std::string &username);
    std::string GetLoggedUsername();
    void Logout();
    void Help();
    void RefillBalance();
    int GetLoggedUserBalance();
    void ChangeUserBalance(const int &balance);
}

#endif