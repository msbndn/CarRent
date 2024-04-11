#include "database.h"

void database::createAccount() {
    std::string username, password, sPassword;
    std::string newAccountBalance = "0";
    
    system("cls");
    std::cout << "Create username: ";
    std::cin >> username;

    if(isUsernameExists(username)) {
        std::cout << "\nUsername already in use. Try again!\n" << std::endl;
        system("pause");
        return;
    }

    std::cout << "Create password: ";
    std::cin >> password;
    std::cout << "Apply password: ";
    std::cin >> sPassword;

    if(password == sPassword) {
        std::ofstream userfile(usersPath + username + ".txt");

        if(userfile.is_open()) {
            userfile << password << std::endl;
            userfile << newAccountBalance << std::endl;
            userfile.close();
        }

        std::cout << "\nSuccessful sign up!\n" << std::endl;
    }else {
        std::cout << "\nPasswords are different. Try again!\n" << std::endl;
    }

    system("pause");
}

bool database::isUsernameExists(const std::string &username) {
    std::ifstream userfile(usersPath + username + ".txt");

    bool isExists = false;

    if(userfile.is_open()) { 
        isExists = true; 
        userfile.close();    
    }
    
    return isExists;   
}