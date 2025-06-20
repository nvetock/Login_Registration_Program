#ifndef USER_ACCOUNT_H
#define USER_ACCOUNT_H

#include <string>

class UserAccount
{
public:

	UserAccount() {}

	UserAccount(std::string& username, std::string& password)
		: username{ username }, password{ password }
	{}

	~UserAccount() {}

	const std::string& getUsername() const;

	const bool verifyPassword(std::string& input_password) const;

	void setPassword(std::string& input_password);


private:
	std::string username{};
	std::string password{}; // this needs to be encrypted


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