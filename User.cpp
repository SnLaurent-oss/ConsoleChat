#include "User.h"

User::User(const std::string& log,
    const std::string& pass,
    const std::string& name)
    : _login(log), _password(pass), _name(name) {
}

bool User::checkLogin(const std::string& str) const
{
    return _login == str;
}

bool User::checkPassword(const std::string& pass) const
{
    return _password == pass;
}

const std::string& User::getName() const
{
    return _name;
}

const std::string& User::getLogin() const
{
    return _login;
}
