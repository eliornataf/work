/*****************************************************************************
* File Name: Shape Rectangle
* Written by: Elior Nataf
* Date: 20/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __SHAPE_RECTANGLE_H__
#define __SHAPE_RECTANGLE_H__

/*------------------------------- Header Files ------------------------------*/

#include "canvas.hpp" /* Canvas Header */
#include "drawShape.hpp" /* Draw Shape Header */
#include "point.hpp" /* Point Header */
#include "shape.hpp" /* Shape Header */

/*-------------------------------- Structure -------------------------------*/

class ShapeRectangle : public Shape {
public:   
    // Constructor

    ShapeRectangle(const ascii::Point &a_pointNum, const size_t &a_width, const size_t &a_height, const char &a_brush);

    // Destructor

    ~ShapeRectangle();

    // Copy Constructor

    ShapeRectangle(const ShapeRectangle &a_other);

    // Assignment Operator

    ShapeRectangle &operator=(const ShapeRectangle &a_other);

    // Functions

    virtual void Draw(ascii::Canvas &a_canvas) const;

private:
    // Struct members

    ascii::Point m_pointNum; /* Top Left */
    size_t m_width;
    size_t m_height;
};

#endif /* __SHAPE_RECTANGLE_H__ */
