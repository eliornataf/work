/*****************************************************************************
* File Name: Shape Circle
* Written by: Elior Nataf
* Date: 20/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __SHAPE_CIRCLE_H__
#define __SHAPE_CIRCLE_H__

/*------------------------------- Header Files ------------------------------*/

#include "canvas.hpp" /* Canvas Header */
#include "drawShape.hpp" /* Draw Shape Header */
#include "point.hpp" /* Point Header */
#include "shape.hpp" /* Shape Header */

/*-------------------------------- Structure -------------------------------*/

class ShapeCircle : public Shape {
public:   
    // Constructor

    ShapeCircle(const ascii::Point &a_point, const size_t &a_radius, const char &a_brush);

    // Destructor

    ~ShapeCircle();

    // Copy Constructor

    ShapeCircle(const ShapeCircle &a_other);

    // Assignment Operator

    ShapeCircle &operator=(const ShapeCircle &a_other);

    // Functions

    virtual void Draw(ascii::Canvas &a_canvas) const;

private:
    // Struct members

    ascii::Point m_point;
    size_t m_radius;
};

#endif /* __SHAPE_CIRCLE_H__ */
