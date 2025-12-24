#pragma once
#include <string>

struct Message
{
    std::string sender;   // логин отправителя
    std::string receiver; // логин получателя, пусто = всем
    std::string text;     // текст сообщения
};
