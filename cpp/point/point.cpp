#include <cstdio> /* printf */
#include <math.h> /* sqrt */
#include <stdexcept> /* throw */
#include <string.h> /* strlen */
#include "point.hpp" /* Point Header */

Point::Point()
: m_x(0)
, m_y(0) {
}

Point::Point(const double a_x, const double a_y)
: m_x(a_x)
, m_y(a_y) {
    this->m_name[0] = '\0';
}

Point::Point(const double a_x, const double a_y, const char *a_name) 
: m_x(a_x)
, m_y(a_y) {
    !a_name ? throw std::invalid_argument("a_name is NULL pointer") : a_name;

    strcpy(this->m_name, a_name);
}

Point::Point(const Point &a_other) 
: m_x(a_other.m_x)
, m_y(a_other.m_y) {
    strncpy(this->m_name, a_other.m_name, NAME_LENGTH);
    strcat(this->m_name, "a");
    this->m_name[NAME_LENGTH] = '\0';
}

Point &Point::operator=(const Point &a_other) {
    this->m_x = a_other.m_x;
    this->m_y = a_other.m_y;
    strncpy(this->m_name, a_other.m_name, NAME_LENGTH);
    this->m_name[NAME_LENGTH] = '\0';

    return *this;
}

Point::~Point() {
}

double Point::Length() const {
    return sqrt( (this->m_x * this->m_x) + (this->m_y * this->m_y) );
}

double Point::DistanceTo(const Point *a_point) const {
    !a_point ? throw std::invalid_argument("a_point is NULL pointer") : a_point;
    
    double d_x = (this->m_x - a_point->m_x);
    double d_y = (this->m_y - a_point->m_y);

    return sqrt( (d_x * d_x) + (d_y * d_y) );
}

void Point::Move(const double a_deltaX, const double a_deltaY) {
    this->m_x += a_deltaX;
    this->m_y += a_deltaY;
}

void Point::Print() const {
    if (strlen(this->m_name))
    {
        printf("%s: ", this->m_name);
    }

    printf("(%.0f, %.0f)", this->m_x, this->m_y);
}

void Point::Print(const char a_prefix) const {
    if (strlen(this->m_name))
    {
        printf("%s: ", this->m_name);
    }

    printf("%c (%.0f, %.0f)", a_prefix, this->m_x, this->m_y);
}

void Point::Print(const size_t a_numOfTimes) const {
    if (strlen(this->m_name))
    {
        printf("%s: ", this->m_name);
    }

    for (size_t i = 0; i < a_numOfTimes;++i)
    {
        printf("(%.0f, %.0f) ", this->m_x, this->m_y);
    }
}

void Point::Print(const char a_prefix, const size_t a_numOfTimes) const {
    if (strlen(this->m_name))
    {
        printf("%s: ", this->m_name);
    }

    for (size_t i = 0; i < a_numOfTimes;++i)
    {
        printf("%c (%.0f, %.0f) ", a_prefix, this->m_x, this->m_y);
    }
}

Point Point::operator+(const Point a_point) const {
    return Point(this->m_x + a_point.m_x, this->m_y + a_point.m_y);
}

Point Point::operator-(const Point a_point) const {
    return Point(this->m_x - a_point.m_x, this->m_y - a_point.m_y);
}

Point Point::operator*(const double a_factor) const {
    return Point(this->m_x * a_factor, this->m_y * a_factor);
}

void Point::operator*=(const double a_factor) {
    this->m_x *= a_factor;
    this->m_y *= a_factor;
}