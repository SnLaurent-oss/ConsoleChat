#pragma once
#include <exception>
#include <string>

class ChatException : public std::exception
{
protected:
    std::string message;
public:
    ChatException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class UserAlreadyExists : public ChatException
{
public:
    UserAlreadyExists(const std::string& login)
        : ChatException("Пользователь с логином \"" + login + "\" уже существует!") {
    }
};

class UserNotFound : public ChatException
{
public:
    UserNotFound(const std::string& login)
        : ChatException("Пользователь с логином \"" + login + "\" не найден!") {
    }
};

class AuthorizationFailed : public ChatException
{
public:
    AuthorizationFailed() : ChatException("Неверный логин или пароль!") {}
};
