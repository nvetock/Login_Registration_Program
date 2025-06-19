#include <iostream>
#include <string>
#include  <limits>


#include "Logger.h"

// Intentionally global logger.
Logger mylog{ "Logs/new_log_test.log" };

void ignoreLine() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int min_accountInputLength{ 8 };
int max_accountInputLength{ 32 };


std::string getWelcomeInput() {
	std::string user_input{};
	
	while (true) {
		std::cout << "Are you 'New' or 'Returning'?\nEnter one of the options: ";

		// First check if the input fails
		if (!(std::cin >> user_input)) {
			std::cout << "\nInvalid input...\n\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			continue; // restart the while loop
		}

		// Second. Make sure there isn't unextracted input in the input buffer
		if (!std::cin.eof() && std::cin.peek() != '\n') {
			std::cout << "\nInput must not include any spaces...\n\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			
			continue; // restart the while loop
		}

		// Third. Check if the input starts with an alpha char
		if (!std::isalpha(user_input[0])) {
			std::cout << "\nInput must start with a letter.\n\n";
			continue;
		}

		// Fourth. Check that the lowercase words match required words
		std::string lower_input{};
		for (int i = 0; i < user_input.length(); ++i) {
			lower_input += std::tolower(user_input[i], std::locale());
		}

		if (lower_input != "new" && lower_input != "returning" && lower_input != "return") {
			std::cout << "\nYou entered: "<< lower_input << " | Please enter 'New' or 'Returning'...\n\n";
			continue;
		}
		
		if (lower_input == "new") {
			std::cout << "\nLet's setup a new account!\n\n";
		}
		else {
			std::cout << "\nWelcome back!\n\n";
		}

		user_input = lower_input; // Ensure the lowercase version is being returned at end
		break;
	}

	return user_input; // Input was successful
}


std::string getUserInput(std::string_view displayMessage) {
	while (true) {
		std::string user_input{};
		std::cout << displayMessage;

		// First check if the input fails
		if (!(std::cin >> user_input)) {
			std::cout << "Invalid input...\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			continue; // restart the while loop
		}

		// Second. Make sure there isn't unextracted input in the input buffer
		if (!std::cin.eof() && std::cin.peek() != '\n') {
			std::cout << "Input must not include any spaces...\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			continue; // restart the while loop
		}

		// Third. Check if the input starts with an alpha char
		if (!std::isalpha(user_input[0])) {
			std::cout << "Input must start with a letter.\n";
			continue;
		}

		return user_input; // Input was successful
	}
}



int main()
{
	std::cout << "Welcome to 'make a username, or login, and that's it simulator\n\n" << std::endl;

	std::string user_input{ getWelcomeInput() };
	
	if (user_input == "new") {
		// Create New Account
	}

	// Base Sign on Function


	return 0;
}