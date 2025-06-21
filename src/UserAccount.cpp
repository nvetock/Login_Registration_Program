#include "UserAccount.h"

UserAccount::UserAccount(
	const std::string& username, const std::string& password
) : _username{username}
{
	_password = hashPassword(password);
	saveAccount();
}

bool UserAccount::login(const std::string& username, const std::string& password) {
	std::string temp_user{ username };
	std::string temp_pass{ password };
	
	if (loadAccount(temp_user)) {
		if (username == _username && hashPassword(temp_pass) == _password) {
			return true;
		}
	}

	return false;
}

void UserAccount::logout() {
	
	if (!_accountExistsInDB) {
		saveAccount();
	}

	delete this;
}



void UserAccount::setUsername(std::string& username) {
	_username = username;
}

void UserAccount::setPassword(std::string& password){
	_password = password;
}



void UserAccount::saveAccount() const {

	if (!std::filesystem::is_directory("FakeDB")) {
		std::filesystem::create_directory("FakeDB");
	}

	std::ofstream accountFile("FakeDB/accountinfo.txt", std::ios::app);
	if (accountFile.is_open()) {

		accountFile << _username << ':' << _password << '\n' << std::endl;
		
		accountFile.close();
	}
}

bool UserAccount::loadAccount(std::string& user) {

	if (!std::filesystem::is_directory("FakeDB")) {
		return false;
	}

	std::ifstream accountFile("FakeDB/accountinfo.txt");
	if (accountFile.is_open()) {

		std::string line{ "" };

		while (std::getline(accountFile, line)) {
			size_t end_acc_index{ line.find(':') };

			if (line.substr(0, end_acc_index) == user) {
				setUsername(user);

				std::string temp_pass{ line.substr(end_acc_index + 1, line.length()) };
				setPassword(temp_pass);
				_accountExistsInDB = true;
				return true;
			}
		}

		accountFile.close();
		return false;
	}

}

std::string UserAccount::hashPassword(const std::string& password) const {
	
	std::string result{ "" };
	for (int i = 0; i < password.length(); ++i) {
		char temp_char = std::tolower(password[i]);

		// odd index are stored as uppercase
		if (i % 2) {
			temp_char = std::toupper(temp_char);
		}

		result += temp_char;
	}
	
	return result;
}
