#include <iostream>
#include <string>

#include "InputValidation.h"
#include "UserAccount.h"
#include "Logger.h"

Logger mylog("Logs/main.log");

int main() {


    std::string username{ "John2" };
    std::string password{ "pass" };
    UserAccount user2{ username, password };

    UserAccount user{ };
    if (user.login(username, password)) {

        std::cout << "Logged in as: " << user.getUsername() << " | " << user.getPassword() << std::endl;
    }
    else {
        std::cout << "An account for: " << username << " does not exist, or the password entered was incorrect." << std::endl;
    }


    return 0;
}