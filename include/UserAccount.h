#ifndef USERACCOUNT_H
#define USERACCOUNT_H

#include <string>
#include <fstream>
#include <ostream>
#include <istream>
#include <filesystem>

class UserAccount {
public:
    UserAccount() {}
    UserAccount(const std::string& username, const std::string& password);
    ~UserAccount() {};

    bool login(const std::string& username, const std::string& password);
    void logout();

    std::string& getUsername() { return _username; }
    std::string& getPassword() { return _password; }
private:
    std::string _username{};
    std::string _password{};
    bool _accountExistsInDB{ false };

    void setUsername(std::string& username);
    void setPassword(std::string& password);

    void saveAccount() const;
    bool loadAccount(std::string& user);
    std::string hashPassword(const std::string& password) const;

};

#endif