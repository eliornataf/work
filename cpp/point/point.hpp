/*****************************************************************************
* File Name: Point
* Written by: Elior Nataf
* Date: 2/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __POINT_H__
#define __POINT_H__

/*------------------------------- Header Files ------------------------------*/

/*-------------------------------- Structure -------------------------------*/

class Point {   
public:
    // Constructor

    Point();
    Point(double a_x, double a_y);
    Point(double a_x, double a_y, const char *a_name);

    // Copy Constructor

    Point(const Point &a_other);

    // Assignment Operator

    Point &operator=(const Point &a_other);

    // Destructor

    ~Point();

    // Functions

    double Length() const;
    double DistanceTo(const Point *a_point) const;
    void Move(const double a_deltaX, const double a_deltaY);

    void Print() const;
    void Print(const char a_prefix) const;
    void Print(const size_t a_numOfTimes) const;
    void Print(const char a_prefix, const size_t a_numOfTimes) const;

    Point operator+(const Point a_point) const;
    Point operator-(const Point a_point) const;
    Point operator*(const double a_factor) const;
    void operator*=(const double a_factor);

private:
    //  Constants

    static const size_t NAME_LENGTH = 47;

    //  Struct members

    double m_x;
    double m_y;
    char m_name[NAME_LENGTH + sizeof('\0')];
};

/*---------------------------------- Define ---------------------------------*/

/*-------------------------- Functions declarations -------------------------*/

#endif /* __POINT_H__ */
