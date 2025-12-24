#include "Chat.h"
#include <iostream>
#include <string>

void Chat::Registration()
{
    std::string login, password, name;
    std::cout << "Имя: ";
    std::cin >> name;
    std::cout << "Логин: ";
    std::cin >> login;
    std::cout << "Пароль: ";
    std::cin >> password;
    std::cout << std::endl;

    if (users.find([&](std::shared_ptr<User> u) { return u->checkLogin(login); }))
        throw UserAlreadyExists(login);

    users.add(std::make_shared<User>(login, password, name));
    std::cout << "Регистрация прошла успешно!" << std::endl;
}

void Chat::Avtorization()
{
    std::string login, password;
    std::cout << "Логин: ";
    std::cin >> login;
    std::cout << "Пароль: ";
    std::cin >> password;
    std::cout << std::endl;

    auto user = users.find([&](std::shared_ptr<User> u) {
        return u->checkLogin(login) && u->checkPassword(password);
        });

    if (!user)
        throw AuthorizationFailed();

    currentUser = user;
    std::cout << "Рады приветствовать Вас, " << currentUser->getName() << std::endl;
}

void Chat::logout()
{
    currentUser.reset();
    std::cout << "Будем рады видеть Вас снова!" << std::endl;
}

void Chat::sendMessage()
{
    if (!currentUser)
    {
        std::cout << "Необходимо авторизоваться" << std::endl;
        return;
    }

    std::string receiverLogin;
    std::cin.ignore();
    std::cout << "Кому (логин, пусто = рассылка всем): ";
    std::getline(std::cin, receiverLogin);

    if (!receiverLogin.empty())
    {
        auto receiver = users.find([&](std::shared_ptr<User> u) {
            return u->checkLogin(receiverLogin);
            });

        if (!receiver)
            throw UserNotFound(receiverLogin);

        if (receiverLogin == currentUser->getLogin())
        {
            std::cout << "Нельзя отправить сообщение самому себе!" << std::endl;
            return;
        }
    }

    std::string text;
    std::cout << "Текст сообщения: ";
    std::getline(std::cin, text);

    messages.add(std::make_shared<Message>(Message{ currentUser->getLogin(), receiverLogin, text }));
    std::cout << "Сообщение отправлено!" << std::endl;
}

void Chat::showMessages() const
{
    if (!currentUser)
    {
        std::cout << "Необходимо авторизоваться" << std::endl;
        return;
    }

    std::string me = currentUser->getLogin();

    for (int i = 0; i < messages.count(); i++)
    {
        auto msg = messages.get(i);
        if (msg->receiver.empty() || msg->receiver == me || msg->sender == me)
        {
            std::cout << "[" << msg->sender
                << " -> "
                << (msg->receiver.empty() ? "ALL" : msg->receiver)
                << "] "
                << msg->text << "\n";
        }
    }
}
