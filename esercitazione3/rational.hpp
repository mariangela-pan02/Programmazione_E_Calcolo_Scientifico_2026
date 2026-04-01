#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <concepts>
#include <iostream>
#include <numeric>

template<typename I>
requires std::integral<I>
class rational
{
private:
    I num_;
    I den_;

    void simplify()
    {
        // Caso denominatore zero:
        // 0/0 = NaN
        // n/0 = Inf oppure -Inf
        if (den_ == 0) {
            if (num_ == 0) {
                return;
            }
            num_ = (num_ > 0) ? 1 : -1;
            return;
        }

        // Se il numeratore è zero, rappresento sempre 0/1
        if (num_ == 0) {
            den_ = 1;
            return;
        }

        // Rendo il denominatore positivo
        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }

        // Semplificazione
        I g = std::gcd(num_, den_);
        num_ /= g;
        den_ /= g;
    }

public:
    // Default
    rational() : num_(0), den_(1) {}

    // Costruttore user-defined
    rational(I n, I d) : num_(n), den_(d)
    {
        simplify();
    }

    I num() const { return num_; }
    I den() const { return den_; }

    bool is_nan() const
    {
        return num_ == 0 && den_ == 0;
    }

    bool is_inf() const
    {
        return num_ != 0 && den_ == 0;
    }

    bool is_zero() const
    {
        return num_ == 0 && den_ != 0;
    }

    // +=
    rational& operator+=(const rational& other)
    {
        if (is_nan() || other.is_nan()) {
            num_ = 0;
            den_ = 0;
            return *this;
        }

        if (is_inf() && other.is_inf()) {
            if (num_ != other.num_) {
                num_ = 0;
                den_ = 0; // +Inf + -Inf = NaN
            }
            return *this;
        }

        if (is_inf()) {
            return *this;
        }

        if (other.is_inf()) {
            num_ = other.num_;
            den_ = 0;
            return *this;
        }

        num_ = num_ * other.den_ + other.num_ * den_;
        den_ = den_ * other.den_;
        simplify();
        return *this;
    }

    // +
    rational operator+(const rational& other) const
    {
        rational temp = *this;
        temp += other;
        return temp;
    }

    // -=
    rational& operator-=(const rational& other)
    {
        *this += rational(-other.num_, other.den_);
        return *this;
    }

    // -
    rational operator-(const rational& other) const
    {
        rational temp = *this;
        temp -= other;
        return temp;
    }

    // *=
    rational& operator*=(const rational& other)
    {
        if (is_nan() || other.is_nan()) {
            num_ = 0;
            den_ = 0;
            return *this;
        }

        if ((is_zero() && other.is_inf()) || (is_inf() && other.is_zero())) {
            num_ = 0;
            den_ = 0; // 0 * Inf = NaN
            return *this;
        }

        if (is_inf() || other.is_inf()) {
            int sign1 = is_inf() ? num_ : (num_ > 0 ? 1 : -1);
            int sign2 = other.is_inf() ? other.num_ : (other.num_ > 0 ? 1 : -1);
            num_ = sign1 * sign2;
            den_ = 0;
            simplify();
            return *this;
        }

        num_ = num_ * other.num_;
        den_ = den_ * other.den_;
        simplify();
        return *this;
    }

    // *
    rational operator*(const rational& other) const
    {
        rational temp = *this;
        temp *= other;
        return temp;
    }

    // /=
    rational& operator/=(const rational& other)
    {
        if (is_nan() || other.is_nan()) {
            num_ = 0;
            den_ = 0;
            return *this;
        }

        // divisione per zero
        if (other.is_zero()) {
            if (is_zero()) {
                num_ = 0;
                den_ = 0; // 0/0 = NaN
            } else {
                num_ = (num_ > 0) ? 1 : -1;
                den_ = 0; // Inf
            }
            return *this;
        }

        if (is_inf() && other.is_inf()) {
            num_ = 0;
            den_ = 0; // Inf / Inf = NaN
            return *this;
        }

        if (other.is_inf()) {
            num_ = 0;
            den_ = 1; // finito / Inf = 0
            return *this;
        }

        if (is_inf()) {
            num_ = (num_ * other.num_ > 0) ? 1 : -1;
            den_ = 0;
            return *this;
        }

        num_ = num_ * other.den_;
        den_ = den_ * other.num_;
        simplify();
        return *this;
    }

    // /
    rational operator/(const rational& other) const
    {
        rational temp = *this;
        temp /= other;
        return temp;
    }
};

template<typename I>
requires std::integral<I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r)
{
    if (r.is_nan()) {
        os << "NaN";
    } else if (r.is_inf()) {
        if (r.num() > 0) {
            os << "Inf";
        } else {
            os << "-Inf";
        }
    } else {
        os << r.num() << "/" << r.den();
    }

    return os;
}

#endif