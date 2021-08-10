#include <iostream> /* cout */
#include <stdexcept> /* throw */
#include "fraction.hpp" /* Fraction Header */
#include <numeric> /* lcm */

/*******************************************************
****************** Friend Functions *******************
*******************************************************/

template <typename T>
static T CheckDenominatorInput(const T &a_denominator) {
    if (!a_denominator) {
        throw std::logic_error("Divide by zero");
    }

    return a_denominator;
}

/*******************************************************
****************** Friend Functions *******************
*******************************************************/

// operator<<

template <typename X>
std::ostream &operator<<(std::ostream &a_os, const Fraction<X> &a_fraction) {
    a_os << ((double)a_fraction.m_numerator / (double)a_fraction.m_denominator);

    return a_os;
}

// operator*

template <typename X>
Fraction<X> operator*(const int &a_number, const Fraction<X> &a_fraction) {
    return a_fraction * a_number;
}

template <typename X>
Fraction<X> operator*(const double &a_number, const Fraction<X> &a_fraction) {
    return a_fraction * a_number;
}

// operator/

template <typename X>
Fraction<X> operator/(const int &a_number, const Fraction<X> &a_fraction) {
    return Fraction<X>((a_number * a_fraction.m_denominator), (1 * a_fraction.m_numerator));
}

template <typename X>
Fraction<X> operator/(const double &a_number, const Fraction<X> &a_fraction) {
    return Fraction<X>((a_number * a_fraction.m_denominator), (1.0 * a_fraction.m_numerator));
}

// operator+

// template <typename X>
// Fraction<X> operator+(const int &a_number, const Fraction<X> &a_fraction) {
//     return a_fraction + a_number;
// }

// template <typename X>
// Fraction<X> operator+(const double &a_number, const Fraction<X> &a_fraction) {
//     return a_fraction + a_number;
// }

// operator-

// template <typename X>
// Fraction<X> operator-(const int &a_number, const Fraction<X> &a_fraction) {
//     return -a_fraction + a_number;
// }

// template <typename X>
// Fraction<X> operator-(const double &a_number, const Fraction<X> &a_fraction) {
//     return -a_fraction + a_number;
// }

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

// Constructor

template <typename T>
Fraction<T>::Fraction(const T &a_numerator, const T &a_denominator) 
: m_numerator(a_numerator)
, m_denominator(CheckDenominatorInput<T>(a_denominator)) {
}

// Destructor

template <typename T>
Fraction<T>::~Fraction() {
}

// Copy Constructor

template <typename T>
Fraction<T>::Fraction(const Fraction<T> &a_other)
: m_numerator(a_other.m_numerator)
, m_denominator(CheckDenominatorInput(a_other.m_denominator)) {
}

// Assignment Operator

template <typename T>
Fraction<T> &Fraction<T>::operator=(const Fraction<T> &a_other) {
    this->m_numerator = a_other.m_numerator;
    this->m_denominator = a_other.m_denominator;

    return *this;
}

// operator+=

template <typename T>
Fraction<T> &Fraction<T>::operator+=(const Fraction<T> &a_other) {
     return *this = *this + a_other;
}

// operator-=

template <typename T>
Fraction<T> &Fraction<T>::operator-=(const Fraction<T> &a_other) {
    return *this = *this - a_other;
}

// operator*=

template <typename T>
Fraction<T> &Fraction<T>::operator*=(const Fraction<T> &a_other) {
     return *this = *this * a_other;
}

// operator/=

template <typename T>
Fraction<T> &Fraction<T>::operator/=(const Fraction<T> &a_other) {
     return *this = *this / a_other;
}

// operator*

template <typename T>
Fraction<T> Fraction<T>::operator*(const Fraction<T> &a_other) const { 
    return Fraction<T>(this->m_numerator * a_other->m_numerator, this->m_denominator * a_other->m_denominator);
}

template <typename T>
Fraction<T> Fraction<T>::operator*(const int &a_number) const {
    return Fraction<T>(this->m_numerator * a_number, this->m_denominator);
}

template <typename T>
Fraction<T> Fraction<T>::operator*(const double &a_number) const {
    return Fraction<T>(this->m_numerator * a_number, this->m_denominator);
}

// operator/

template <typename T>
Fraction<T> Fraction<T>::operator/(const Fraction<T> &a_other) const { 
    return Fraction<T>(this->m_numerator * a_other->m_denominator, this->m_denominator * a_other->m_numerator);
}

template <typename T>
Fraction<T> Fraction<T>::operator/(const int &a_number) const {
    CheckDenominatorInput(a_number);

    Fraction<T>((this->m_numerator * 1), (this->m_denominator * a_number));
}

template <typename T>
Fraction<T> Fraction<T>::operator/(const double &a_number) const {
    CheckDenominatorInput(a_number);

    Fraction<T>((this->m_numerator * 1.0), (this->m_denominator * a_number));
}

// operator+

template <typename T>
Fraction<T> Fraction<T>::operator+(const Fraction<T> &a_other) const {
    T lcm = std::lcm(this->m_denominator, a_other.m_denominator);
    T thisDenominatorMultiplyToLCM = lcm / this->m_denominator;
    T otherDenominatorMultiplyToLCM = lcm / a_other.m_denominator;

    return Fraction<T>(this->m_numerator * thisDenominatorMultiplyToLCM + a_other.m_numerator * otherDenominatorMultiplyToLCM, lcm);
}

// template <typename T>
// Fraction<T> Fraction<T>::operator+(const int &a_number) const {
//     return *this + Fraction<T>(a_number, 1);
// }

// template <typename T>
// Fraction<T> Fraction<T>::operator+(const double &a_number) const {
//     return *this + Fraction<T>(a_number, 1.0);
// }

// operator-

template <typename T>
Fraction<T> Fraction<T>::operator-(const Fraction<T> &a_other) const {
    return -(a_other) + *this;
}

// template <typename T>
// Fraction<T> Fraction<T>::operator-(const int &a_number) const {
//     return *this - Fraction<T>(a_number, 1);
// }

// template <typename T>
// Fraction<T> Fraction<T>::operator-(const double &a_number) const {
//     return *this - Fraction<T>(a_number, 1.0);
// }

// double()

template <typename T>
Fraction<T>::operator double() {
    return (double)(double)(this->m_numerator) / (double)(this->m_denominator);
}

// Print

template <typename T>
void Fraction<T>::Print() const {
    std::cout << this->m_numerator << "/" << this->m_denominator;
}