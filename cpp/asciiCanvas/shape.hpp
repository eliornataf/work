/*****************************************************************************
* File Name: Shape
* Written by: Elior Nataf
* Date: 20/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __SHAPE_H__
#define __SHAPE_H__

/*------------------------------- Header Files ------------------------------*/

#include "drawShape.hpp" /* Draw Shape Header */

/*-------------------------------- Structure -------------------------------*/

class Shape : public DrawShape {
public:   
    // Constructor

    Shape();

    // Destructor

    virtual ~Shape();

    // Copy Constructor

    Shape(const Shape &a_other);

    // Assignment Operator

    Shape &operator=(const Shape &a_other);

    // Functions

    bool IsFlippedHorizontally() const;
    bool IsFlippedVertically() const;
    bool IsFilled() const;

    void FlipUnFlipHorizontally();
    void FlipUnFlipVertically();
    void FilledUnFilled();

protected:
    bool m_isFlippedHorizontally;
    bool m_isFlippedVertically;
    bool m_isFilled;
};

#endif /* __SHAPE_H__ */
