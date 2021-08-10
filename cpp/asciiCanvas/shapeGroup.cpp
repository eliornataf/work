#include <list> /* list */
#include "drawShape.hpp" /* Draw Shape Header */
#include "shapeGroup.hpp" /* Shape Group Header */

ShapeGroup::ShapeGroup(const char &a_groupBrush)
: m_shapes() {
    this->m_brush = a_groupBrush;
}

ShapeGroup::~ShapeGroup() {
    std::list<Shape*>::iterator currIter = this->m_shapes.begin();
    std::list<Shape*>::iterator endIter = this->m_shapes.end();

    for (;currIter != endIter;++currIter) {
        delete *currIter;
    }
}

ShapeGroup::ShapeGroup(const ShapeGroup &a_other) 
: m_shapes(a_other.m_shapes) {
    this->m_brush = a_other.m_brush;    
}

ShapeGroup &ShapeGroup::operator=(const ShapeGroup &a_other) {
    std::list<Shape*>::iterator currIter = this->m_shapes.begin();
    std::list<Shape*>::iterator endIter = this->m_shapes.end();

    for (;currIter != endIter;++currIter) {
        delete *currIter;
    }

    this->m_shapes = a_other.m_shapes;
    this->m_brush = a_other.m_brush;

    return *this;
}

void ShapeGroup::AddToGroup(Shape *a_shape) {   
    this->m_shapes.push_back(a_shape);
}

void ShapeGroup::FlipUnFlipGroupItemHorizontally() {
    std::list<Shape*>::iterator currIter = this->m_shapes.begin();
    std::list<Shape*>::iterator endIter = this->m_shapes.end();

    for (;currIter != endIter;++currIter) {
        Shape *currShape = *currIter;
        currShape->FlipUnFlipHorizontally();
    }
}

void ShapeGroup::FlipUnFlipGroupItemVertically() {
    std::list<Shape*>::iterator currIter = this->m_shapes.begin();
    std::list<Shape*>::iterator endIter = this->m_shapes.end();

    for (;currIter != endIter;++currIter) {
        Shape *currShape = *currIter;
        currShape->FlipUnFlipVertically();
    }
}

void ShapeGroup::FilledUnFilledGroup() {
    std::list<Shape*>::iterator currIter = this->m_shapes.begin();
    std::list<Shape*>::iterator endIter = this->m_shapes.end();

    for (;currIter != endIter;++currIter) {
        Shape *currShape = *currIter;
        currShape->FilledUnFilled();
    }
}

void ShapeGroup::Draw(ascii::Canvas &a_canvas) const {
    std::list<Shape*>::const_iterator currIter = this->m_shapes.begin();
    std::list<Shape*>::const_iterator endIter = this->m_shapes.end();

    for (;currIter != endIter;++currIter) {
        Shape *currShape = *currIter;
        char currShapeOriginalBrush = currShape->GetShapeBrush();
        currShape->SetShapeBrush(this->m_brush);
        currShape->Draw(a_canvas);
        currShape->SetShapeBrush(currShapeOriginalBrush);
    }
}