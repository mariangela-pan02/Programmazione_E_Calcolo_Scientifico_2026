#pragma once

#include <iostream>

class unidirected_edge
{
private:
    int from_;
    int to_;

public:
    unidirected_edge(int a, int b)
    {
        if (a < b)
        {
            from_ = a;
            to_ = b;
        }
        else
        {
            from_ = b;
            to_ = a;
        }
    }

    int from() const
    {
        return from_;
    }

    int to() const
    {
        return to_;
    }

    bool operator<(const unidirected_edge& other) const
    {
        if (from_ != other.from_)
        {
            return from_ < other.from_;
        }

        return to_ < other.to_;
    }

    bool operator==(const unidirected_edge& other) const
    {
        return from_ == other.from_ &&
               to_ == other.to_;
    }
};

inline std::ostream& operator<<(std::ostream& os,
                                const unidirected_edge& e)
{
    os << "(" << e.from()
       << ", "
       << e.to()
       << ")";

    return os;
}