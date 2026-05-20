#pragma once

#include <stack>

template<typename T>
class lifo
{
private:
    std::stack<T> s;

public:
    lifo() = default;

    void put(const T& value)
    {
        s.push(value);
    }

    T get()
    {
        T value = s.top();

        s.pop();

        return value;
    }

    bool empty() const
    {
        return s.empty();
    }
};
