/*****************************************************************************
* File Name: Shape Line
* Written by: Elior Nataf
* Date: 20/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __SHAPE_LINE_H__
#define __SHAPE_LINE_H__

/*------------------------------- Header Files ------------------------------*/

#include "canvas.hpp" /* Canvas Header */
#include "drawShape.hpp" /* Draw Shape Header */
#include "point.hpp" /* Point Header */
#include "shape.hpp" /* Shape Header */

/*-------------------------------- Structure -------------------------------*/

class ShapeLine : public Shape {
public:   
    // Constructor

    ShapeLine(const ascii::Point &a_pointNum1, const ascii::Point &a_pointNum2, const char &a_brush);

    // Destructor

    ~ShapeLine();

    // Copy Constructor

    ShapeLine(const ShapeLine &a_other);

    // Assignment Operator

    ShapeLine &operator=(const ShapeLine &a_other);

    // Functions

    virtual void Draw(ascii::Canvas &a_canvas) const;

private:
    // Struct members

    ascii::Point m_pointNum1;
    ascii::Point m_pointNum2;
};

#endif /* __SHAPE_LINE_H__ */
