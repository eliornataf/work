#include "canvas.hpp" /* Canvas Header */
#include "drawShape.hpp" /* Draw Shape Header */
#include "shape.hpp" /* Shape Header */
#include "shapeRectangle.hpp" /* Shape Rectangle Header */
#include "point.hpp" /* Point Header */

ShapeRectangle::ShapeRectangle(const ascii::Point &a_pointNum, const size_t &a_width, const size_t &a_height, const char &a_brush)
: m_pointNum(a_pointNum)
, m_width(a_width) 
, m_height(a_height) {
    this->m_brush = a_brush;
}

ShapeRectangle::~ShapeRectangle() {
}

ShapeRectangle::ShapeRectangle(const ShapeRectangle &a_other) 
: m_pointNum(a_other.m_pointNum)
, m_width(a_other.m_width)
, m_height(a_other.m_height) {
    this->m_brush = a_other.m_brush;
    this->m_isFlippedHorizontally = a_other.m_isFlippedHorizontally;
    this->m_isFlippedVertically = a_other.m_isFlippedVertically;
    this->m_isFilled = a_other.m_isFilled;
}

ShapeRectangle &ShapeRectangle::operator=(const ShapeRectangle &a_other) {
    this->m_pointNum = a_other.m_pointNum;
    this->m_width = a_other.m_width;
    this->m_height = a_other.m_height;
    this->m_brush = a_other.m_brush;
    this->m_isFlippedHorizontally = a_other.m_isFlippedHorizontally;
    this->m_isFlippedVertically = a_other.m_isFlippedVertically;
    this->m_isFilled = a_other.m_isFilled;

    return *this;
}

void ShapeRectangle::Draw(ascii::Canvas &a_canvas) const {
    ascii::Point topLeft = this->m_pointNum;
    ascii::Point topRight(this->m_pointNum.GetX() + this->m_width, this->m_pointNum.GetY());
    ascii::Point buttonLeft(this->m_pointNum.GetX(), this->m_pointNum.GetY() + this->m_height);
    ascii::Point buttonRight(this->m_pointNum.GetX() + this->m_width, this->m_pointNum.GetY() + this->m_height);

    if (this->m_isFlippedHorizontally) {
        topRight = topLeft;
        buttonRight = buttonLeft;
        topLeft = ascii::Point(topRight.GetX() -this->m_width, topRight.GetY());
        buttonLeft = ascii::Point(buttonRight.GetX() - this->m_width, buttonRight.GetY());
    }
    else if (this->m_isFlippedVertically) {
        buttonLeft = topLeft;
        buttonRight = topRight;
        topLeft = ascii::Point(buttonLeft.GetX(), buttonLeft.GetY() - this->m_height);
        topRight = ascii::Point(buttonRight.GetX(), buttonRight.GetY() - this->m_height);
    }
    else if (this->m_isFilled) {
        for (int i = 0; i < this->m_height - 1;++i) {
            ascii::DrawLine(a_canvas, this->m_brush, ascii::Point(topLeft.GetX() + 1, topLeft.GetY() + 1 + i), ascii::Point(topRight.GetX() - 1, topRight.GetY() + 1 + i));
        }
    }
    
    ascii::DrawLine(a_canvas, this->m_brush, topRight, buttonRight);
    ascii::DrawLine(a_canvas, this->m_brush, buttonRight, buttonLeft);
    ascii::DrawLine(a_canvas, this->m_brush, buttonLeft, topLeft);
    ascii::DrawLine(a_canvas, this->m_brush, topLeft, topRight);
}