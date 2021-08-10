/*****************************************************************************
* File Name: Shape Group
* Written by: Elior Nataf
* Date: 20/5/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __SHAPE_GROUP_H__
#define __SHAPE_GROUP_H__

/*------------------------------- Header Files ------------------------------*/

#include <list> /* list */
#include "shape.hpp" /* Shape Header */

/*-------------------------------- Structure -------------------------------*/

class ShapeGroup : public DrawShape {
public:   
    // Constructor

    ShapeGroup(const char &a_groupBrush);

    // Destructor

    ~ShapeGroup();

    // Copy Constructor

    ShapeGroup(const ShapeGroup &a_other);

    // Assignment Operator

    ShapeGroup &operator=(const ShapeGroup &a_other);

    // Functions

    void AddToGroup(Shape *a_shape);

    void FlipUnFlipGroupItemHorizontally();
    void FlipUnFlipGroupItemVertically();
    void FilledUnFilledGroup();

    virtual void Draw(ascii::Canvas &a_canvas) const;

private:
    // Struct members

    std::list<Shape*> m_shapes;
};

#endif /* __GROUP_H__ */
