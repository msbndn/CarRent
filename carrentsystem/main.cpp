#include "database.h"

int main() {
    bool isUserLogged = false;
    
    if (!database::GetLoggedUsername().empty()) {
        isUserLogged = true;
    }

    while(true) {
        system("cls");
        
        std::cout << "  -- Car Rent System --\n\n";

        if (!isUserLogged) {
            std::cout << "1. Create account\n"
                    << "2. Log in\n"
                    << "3. Help\n"
                    << "4. Back\n"
                    << ">> ";

            int choice = 0;
            std::cin >> choice;

            switch (choice) {
            case 1:
                database::CreateAccount();
                break;
            case 2:
                isUserLogged = database::Login();
                break;
            case 3:
                database::Help();
                break;
            case 4:
                return 0;
            
            default:
                std::cout << "Something was going wrong. Try again!" << std::endl;
                system("pause");
                break;
            }
        } else {
            if (!database::IsUsernameExists(database::GetLoggedUsername())) {
                database::Logout();
                continue;
            }

            std::cout << database::GetLoggedUsername() << "\n"
                    << "Balance: " << database::GetLoggedUserBalance() << "$\n\n"
                    << "1. Rent car\n"
                    << "2. Refill balance\n"
                    << "3. Log out\n"
                    << "4. Help\n"
                    << "5. Back\n"
                    << ">> ";

            int choice = 0;
            std::cin >> choice;

            switch (choice) {
            case 1:
                // Rent Car
                break;
            case 2:
                database::RefillBalance();
                break;
            case 3:
                database::Logout();
                isUserLogged = false;
                break;
            case 4:
                database::Help();
                break;
            case 5:
                return 0;
            
            default:
                std::cout << "Something was going wrong. Try again!" << std::endl;
                system("pause");
                break;
            }
        }
    }

    return 0;
}