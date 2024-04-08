#include "database.h"

void help();
// void rentCar();
void refillBalance();

int main() {
    while(true) {
        if(database::getLoggedUsername().empty()) {
            std::cout << std::endl;
            system("cls");
            std::cout << "\e[1;33m  --Car Rent--  \e[0m\n\n";

            std::cout << "\e[1;37m1. Sign up\e[0m\n"
                    << "\e[1;37m2. Log in\e[0m\n"
                    << "\e[1;37m3. Help\e[0m\n"
                    << "\e[1;37m4. exit\e[0m\n"
                    << "\e[1;37m>> \e[0m";

            char choice = 0;
            std::cin >> choice;
            choice = atoi(&choice);

            switch (choice) {
            case 1:
                database::signUp();
                break;
            case 2:
                database::logIn();
                break;
            case 3:
                help();
                break;
            case 4:
                return 0;

            default:
                std::cout << "\e[1;31mSomething was going wrong. Try again.\e[0m\n";
            }
        }else {
            std::cout << std::endl;
            system("cls");
            std::cout << "\e[1;33m  --Car Rent--  \e[0m\n\n";

            std::cout << database::getLoggedUsername() << "\n"
                    << "\e[1;37mBalance: \e[0m" << database::getUserBalance() << "\e[1;37m$\e[0m\n\n"
                    << "\e[1;37m1. Rent car\e[0m\n" 
                    << "\e[1;37m2. Refill balance\e[0m\n" 
                    << "\e[1;37m3. Log out\e[0m\n" 
                    << "\e[1;37m4. Help\e[0m\n" 
                    << "\e[1;37m5. exit\e[0m\n"
                    << "\e[1;37m>> \e[0m";

            
            char choice = 0;
            std::cin >> choice;
            choice = atoi(&choice);

            switch (choice) {
            case 1:
                // rentCar();
                break;
            case 2:
                refillBalance();
                break;
            case 3:
                database::logOut();
                break;
            case 4:
                help();
                break;
            case 5:
                return 0;

            default:
                std::cout << "\e[1;31mSomething was going wrong. Try again.\e[0m\n";
            }
        }
    }

    return 0;
}


void help() {
    system("cls");

    std::ifstream helpfile(mainPath + "carrentHelp.txt");
    if(helpfile.is_open()){
        std::string line;
        while(std::getline(helpfile, line)) {
            std::cout << line << std::endl;
        }

        helpfile.close();
    }

    std::cout << std::endl;
    system("pause");
} 


/* 
void rentCar() {

} 
*/


void refillBalance() {
    unsigned int requestedAmount = 0;

    system("cls");
    std::cout << "\e[1;37mEnter amount of money:\n>> \e[0m";
    std::cin >> requestedAmount;

    database::addUserBalance(requestedAmount);

    std::string password;
    std::cout << "\n\e[1;37mApply your password\n>> \e[0m";
    std::cin >> password;
    
    if (database::applyPassword(password)) {
        std::cout << "\e[1;92m\n\nSuccessful refill!\e[0m\n\n";
        system("pause");
    }else {
        std::cout << "\e[1;31m\n\nSomething was going wrong. Try again.\e[0m\n\n";
        system("pause");
    }

} 

// refillbalance
// showing balance
// carbase in database.dir
