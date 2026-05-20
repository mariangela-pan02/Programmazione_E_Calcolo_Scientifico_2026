#pragma once

#include <queue>

template<typename T>
class fifo
{
private:
    std::queue<T> q;

public:
    fifo() = default;

    void put(const T& value)
    {
        q.push(value);
    }

    T get()
    {
        T value = q.front();

        q.pop();

        return value;
    }

    bool empty() const
    {
        return q.empty();
    }
};
