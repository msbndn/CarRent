#include "database.h"

int main() {
    while(true) {
        system("cls");

        std::cout << "1. Create account\n"
                << "2. Log in\n"
                << "3. Help\n"
                << "4. Back\n"
                << ">> ";

        int choice = 0;
        std::cin >> choice;

        switch (choice) {
        case 1:
            database::createAccount();
            break;
        case 2:
            // login();
            break;
        case 3:
            // help();
            break;
        case 4:
            return 0;
        
        default:
            std::cout << "Something was going wrong. Try again!" << std::endl;
            system("pause");
            break;
        }
    }

    return 0;
}