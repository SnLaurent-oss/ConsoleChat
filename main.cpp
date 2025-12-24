#include "Chat.h"
#include "Exceptions.h"
#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Chat chat;
    int command;

    while (true)
    {
        std::cout << "\nДля выбора действия введите следующие цифры:\n"
            << "1. Регистрация\n"
            << "2. Авторизация\n"
            << "3. Отправить сообщение\n"
            << "4. Показать сообщение\n"
            << "5. Выйти из профиля\n"
            << "0. Выйти из чата\n> ";

        std::cin >> command;

        try
        {
            switch (command)
            {
            case 1:
                chat.Registration();
                break;
            case 2:
                chat.Avtorization();
                break;
            case 3:
                chat.sendMessage();
                break;
            case 4:
                chat.showMessages();
                break;
            case 5:
                chat.logout();
                break;
            case 0:
                return 0;
            default:
                std::cout << "Введена неверная цифра!\n";
            }
        }
        catch (const ChatException& e)
        {
            std::cout << "Ошибка: " << e.what() << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "Стандартная ошибка: " << e.what() << std::endl;
        }
    }
}
