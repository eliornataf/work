/*****************************************************************************
* File Name: Draw Shape
* Written by: Elior Nataf
* Date: 20/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __DRAW_SHAPE_H__
#define __DRAW_SHAPE_H__

/*------------------------------- Header Files ------------------------------*/

#include "canvas.hpp" /* Canvas Header */

/*-------------------------------- Structure -------------------------------*/

class DrawShape {
public:   
    // Constructor

    DrawShape() = default;

    // Destructor

    ~DrawShape() = default;

    // Copy Constructor

    DrawShape(const DrawShape &a_other) = default;

    // Assignment Operator

    DrawShape &operator=(const DrawShape &a_other) = default;

    // Functions

    char GetShapeBrush() const;
    void SetShapeBrush(const char a_brush);
    virtual void Draw(ascii::Canvas &a_canvas) const = 0;

protected:
    // Struct members

    char m_brush;
};

#endif /* __DRAW_SHAPE_H__ */
