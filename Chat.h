#pragma once
#include "User.h"
#include "Message.h"
#include "Storage.h"
#include "Exceptions.h"
#include <memory>
#include <string>
#include <iostream>

const int MAX_USERS = 5;
const int MAX_MESSAGES = 30;

class Chat
{
private:
    Storage<User, MAX_USERS> users;
    Storage<Message, MAX_MESSAGES> messages;
    std::shared_ptr<User> currentUser;

public:
    void Registration();
    void Avtorization();
    void logout();
    void sendMessage();
    void showMessages() const;
};
