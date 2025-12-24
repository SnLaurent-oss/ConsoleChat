#pragma once
#include <string>

class User
{
private:
    std::string _login;
    std::string _password;
    std::string _name;

public:
    User(const std::string& log,
        const std::string& pass,
        const std::string& name);

    bool checkLogin(const std::string& str) const;
    bool checkPassword(const std::string& pass) const;

    const std::string& getName() const;
    const std::string& getLogin() const;
};
