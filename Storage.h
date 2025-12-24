#pragma once
#include <memory>
#include <stdexcept>

template <typename T, int MAX_SIZE>
class Storage
{
private:
    std::shared_ptr<T> items[MAX_SIZE];
    int itemsCount = 0;

public:
    void add(std::shared_ptr<T> item)
    {
        if (itemsCount >= MAX_SIZE)
            throw std::overflow_error("Превышен лимит хранения!");
        items[itemsCount++] = item;
    }

    std::shared_ptr<T> get(int index) const
    {
        if (index < 0 || index >= itemsCount)
            throw std::out_of_range("Индекс вне диапазона");
        return items[index];
    }

    int count() const { return itemsCount; }

    template <typename Func>
    std::shared_ptr<T> find(Func f) const
    {
        for (int i = 0; i < itemsCount; ++i)
        {
            if (f(items[i]))
                return items[i];
        }
        return nullptr;
    }
};
