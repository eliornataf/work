/*****************************************************************************
* File Name: Fraction
* Written by: Elior Nataf
* Date: 10/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __FRACTION_H__
#define __FRACTION_H__

/*------------------------------- Header Files ------------------------------*/

#include <ostream> /* std::ostream */

/*-------------------------------- Structure -------------------------------*/

template <typename T>
class Fraction {
public:   
    // Friend

    template <typename X> friend std::ostream &operator<<(std::ostream &a_os, const Fraction<X> &a_fraction);
    template <typename X> friend Fraction<X> operator*(const int &a_num, const Fraction<X> &a_fraction);
    template <typename X> friend Fraction<X> operator*(const double &a_num, const Fraction<X> &a_fraction);
    template <typename X> friend Fraction<X> operator/(const int &a_num, const Fraction<X> &a_fraction);
    template <typename X> friend Fraction<X> operator/(const double &a_num, const Fraction<X> &a_fraction);
    // template <typename X> friend Fraction<X> operator+(const int &a_num, const Fraction<X> &a_fraction);
    // template <typename X> friend Fraction<X> operator+(const double &a_num, const Fraction<X> &a_fraction);
    // template <typename X> friend Fraction<X> operator-(const int &a_num, const Fraction<X> &a_fraction);
    // template <typename X> friend Fraction<X> operator-(const double &a_num, const Fraction<X> &a_fraction);

    // Constructor

    explicit Fraction(const T &a_numerator, const T &a_denominator);

    // Destructor

    ~Fraction();

    // Copy Constructor

    Fraction(const Fraction<T> &a_other);

    // Assignment Operator

    Fraction<T> &operator=(const Fraction<T> &a_other);

    // Functions    

    Fraction<T> &operator+=(const Fraction<T> &a_other);
    Fraction<T> &operator-=(const Fraction<T> &a_other);
    Fraction<T> &operator*=(const Fraction<T> &a_other);
    Fraction<T> &operator/=(const Fraction<T> &a_other);

    Fraction<T> operator*(const Fraction<T> &a_other) const;
    Fraction<T> operator*(const int &a_number) const;
    Fraction<T> operator*(const double &a_number) const;

    Fraction<T> operator/(const Fraction<T> &a_other) const;
    Fraction<T> operator/(const int &a_number) const;
    Fraction<T> operator/(const double &a_number) const;

    Fraction<T> operator+(const Fraction<T> &a_other) const;
    // Fraction<T> operator+(const int &a_number) const;
    // Fraction<T> operator+(const double &a_number) const;

    Fraction<T> operator-(const Fraction<T> &a_other) const;
    // Fraction<T> operator-(const int &a_number) const;
    // Fraction<T> operator-(const double &a_number) const;

    Fraction<T> operator-() const;

    explicit operator double();

    void Print() const;

private:
    //  Struct members

    T m_numerator;
    T m_denominator;
};

#endif /* __FRACTION_H__ */
