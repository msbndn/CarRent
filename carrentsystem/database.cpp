#include "database.h"

void database::CreateAccount() {
    std::string username, password, passwordConfirmation;
    std::string newAccountBalance = "0";
    
    system("cls");
    std::cout << "Create username: ";
    std::cin >> username;

    if (IsUsernameExists(username)) {
        std::cout << "\nUsername already in use. Try again!\n" << std::endl;
        system("pause");
        return;
    }

    std::cout << "Create password: ";
    std::cin >> password;
    std::cout << "Apply password: ";
    std::cin >> passwordConfirmation;

    if (passwordConfirmation == password) {
        std::ofstream usernamefile (usersPath + username + ".txt");

        if(usernamefile.is_open()) {
            usernamefile << password << std::endl;
            usernamefile << newAccountBalance << std::endl;
            usernamefile.close();
        }

        std::cout << "\nSuccessful sign up!\n" << std::endl;
    } else {
        std::cout << "\nPasswords are different. Try again!\n" << std::endl;
    }

    system("pause");
}

bool database::IsUsernameExists(const std::string &username) {
    std::ifstream usernamefile (usersPath + username + ".txt");

    return usernamefile.is_open();   
}

bool database::Login() {
    system("cls");

    std::string username, password;

    std::cout << "username: ";
    std::cin >> username;
    std::cout << "password: ";
    std::cin >> password;
    
    if (!IsUsernameExists(username) || !IsPasswordCorrect(username, password)) {
        std::cout << "Invalid username or password!" << std::endl;
        system("pause");
        return false;
    }

    LogInUsername(username);

    return true;
}

bool database::IsPasswordCorrect(const std::string &username, const std::string &enteredPassword) {
    std::ifstream usernamefile (usersPath + username + ".txt");

    bool isCorrect = false;
    if (usernamefile.is_open()) {
        std::string password;
        std::getline(usernamefile, password);

        isCorrect = (enteredPassword == password);

        usernamefile.close();
    }

    return isCorrect;
}

void database::LogInUsername(const std::string &username) {
    std::fstream loggedInUserFile (addFilesPath + "loggedInUser.txt");

    if (loggedInUserFile.is_open()) {
        loggedInUserFile << username << std::endl;

        loggedInUserFile.close();
    }
}

std::string database::GetLoggedUsername() {
    std::fstream loggedInUserFile (addFilesPath + "loggedInUser.txt");

    std::string username;
    if (loggedInUserFile.is_open()) {
        std::getline(loggedInUserFile, username);

        loggedInUserFile.close();
    }

    return username;
}

void database::Logout() {
    std::ofstream loggedInUserFile (addFilesPath + "loggedInUser.txt");

    if (loggedInUserFile.is_open()) {
        loggedInUserFile.clear();

        loggedInUserFile.close();
    }
}

void database::Help() {
    system("cls");
    
    std::fstream helpFile (mainPath + "about.txt");

    if (helpFile.is_open()) {
        std::string line;

        while (std::getline(helpFile, line)) {
            std::cout << line << std::endl;
        }

        helpFile.close();
    }

    std::cout << "\n";
    system("pause");
}

void database::RefillBalance() {
    system("cls");

    int refillAmount;
    std::cout << "Enter amount: ";
    std::cin >> refillAmount;

    if (refillAmount == 0) { 
        return; 
    }

    std::string password;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (!IsPasswordCorrect(GetLoggedUsername(), password)) {
        std::cout << "Incorrect password!" << std::endl;
        system("pause");
        return;
    }

    refillAmount += GetLoggedUserBalance();

    ChangeUserBalance(refillAmount);
}

int database::GetLoggedUserBalance() {
    std::ifstream userFile (usersPath + GetLoggedUsername() + ".txt");
    
    std::string line;
    if (userFile.is_open()) {
        for (int i = 0; i < 2; i++) {
            std::getline(userFile, line);
        }

        userFile.close();
    }

    return std::stoi(line);
}

void database::ChangeUserBalance(const int &balance) {
    std::string passwordLine;

    std::ifstream userfile (usersPath + GetLoggedUsername() + ".txt");

    if (userfile.is_open()) {
        std::getline(userfile, passwordLine);

        userfile.close();
    }

    std::ofstream userfile2 (usersPath + GetLoggedUsername() + ".txt", std::ios::trunc);

    if (userfile2.is_open()) {
        userfile2 << passwordLine << std::endl;
        userfile2 << std::to_string(balance) << std::endl;

        userfile.close();
    }
}