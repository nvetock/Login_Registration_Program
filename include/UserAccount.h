#ifndef USER_ACCOUNT_H
#define USER_ACCOUNT_H

#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <iomanip>

#include "Logger.h"

//#include <cryptlib.h>
//#include <modes.h>
//#include <aes.h>
//#include <filters.h>


class UserAccount
{


public:

	UserAccount() {}

	UserAccount(std::string& username, std::string& password)
		: username{ username }, password{ password }
	{}

	~UserAccount() {}

	const std::string& getUsername() const;

	bool verifyPassword(std::string& input_password);

	void setPassword(std::string& input_password);

private:
	std::string username{};
	std::string password{}; // this needs to be encrypted

	// Crypto++ members
	std::string password_ciphertext{};
	const std::string account_info_separator{":|:"};






	const std::string _password_database_path{ "FakeDB/accountinfo.txt" };


	bool setPasswordToFile(std::string& input_password);
	const std::string getPasswordFromFile() const;

	std::string encryptPassword(std::string& input_password);

	// lost woods
	//   
	//   
	//   
	//   book: memory lane - interactive map that grows / note taking section
	//   book - is the inventory system. Drawings and 'notes' are the items
	//   
	//   player movement - arrow keys and interaction key
	//   
	//   player - right hand  and   left hand
	//   spell per dungeon?
	//   
	//   
	//   
	//   

};

#endif