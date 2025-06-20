#include "UserAccount.h"


const std::string& UserAccount::getUsername() const { return username; }

bool UserAccount::verifyPassword(std::string& input_password) {
	
	std::string encryptedPassword{ encryptPassword(input_password) };

	if (encryptedPassword == getPasswordFromFile()) {
		return true;
	}

	return false;
}

void UserAccount::setPassword(std::string& input_password) {
	setPasswordToFile(input_password);
}



/// Private
/*
std::string UserAccount::encryptPassword(std::string& plaintext) {
	
	std::string ciphertext{};

	CryptoPP::AES::DEFAULT_KEYLENGTH;

	CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
	CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption{ aesEncryption, iv };

	// Create CipherText
	CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink{ ciphertext });
	stfEncryptor.Put(reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.length() + 1);
	stfEncryptor.MessageEnd();

	if (ciphertext == "") {
		std::cerr << "Error: Ciphertext is empty.";
	}

	return ciphertext;
}
*/

std::string& UserAccount::encryptPassword(std::string& plaintext) {

	std::string ciphertext{};

	return plaintext;

}


bool UserAccount::setPasswordToFile(std::string& input_password) {

	std::string encryptedPassword{ encryptPassword(input_password) };
	
	// Store ciphertext in FakeDB/accountinfo.txt with username.
	// 
	// First check if the directory folder exists, make one if not
	if (!std::filesystem::is_directory("FakeDB")) {
		std::filesystem::create_directory("FakeDB");
	}
	
	std::ofstream accountFile(_password_database_path, std::ios::app);
	if (accountFile.is_open()) {

		accountFile << username << account_info_separator << encryptedPassword << '\n' << std::endl;

		accountFile.close();

		return true;
	}
	else {
		std::cerr << "Error: Unable to open accountinfo file: "
			<< _password_database_path << std::endl;
	}

	return false;
}



const std::string UserAccount::getPasswordFromFile() const {

	std::ifstream accountFile(_password_database_path);
	if (accountFile.is_open()) {

		std::string line{""};
		while (std::getline(accountFile, line)) {
			size_t end_account_index{ line.find(account_info_separator) };
			
			std::string temp_account{ line.substr(0, end_account_index) };

			if (username == temp_account) {
				accountFile.close();
				return line.substr(end_account_index + account_info_separator.length() - 1, line.length());
			}
		}

		accountFile.close();
	}
	std::cout << "No matching password found. Returning empty.\n";
	return "";
}