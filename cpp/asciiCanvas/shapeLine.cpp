#include "canvas.hpp" /* Canvas Header */
#include "drawShape.hpp" /* Draw Shape Header */
#include "shape.hpp" /* Shape Header */
#include "shapeLine.hpp" /* Shape Line Header */
#include "point.hpp" /* Point Header */

ShapeLine::ShapeLine(const ascii::Point &a_pointNum1, const ascii::Point &a_pointNum2, const char &a_brush) 
: m_pointNum1(a_pointNum1)
, m_pointNum2(a_pointNum2) {
    this->m_brush = a_brush;
}

ShapeLine::~ShapeLine() {
}

ShapeLine::ShapeLine(const ShapeLine &a_other) 
: m_pointNum1(a_other.m_pointNum1)
, m_pointNum2(a_other.m_pointNum2) {
    this->m_brush = a_other.m_brush;
    this->m_isFlippedHorizontally = a_other.m_isFlippedHorizontally;
    this->m_isFlippedVertically = a_other.m_isFlippedVertically;
    this->m_isFilled = a_other.m_isFilled;
}

ShapeLine &ShapeLine::operator=(const ShapeLine &a_other) {
    this->m_pointNum1 = a_other.m_pointNum1;
    this->m_pointNum2 = a_other.m_pointNum2;
    this->m_brush = a_other.m_brush;
    this->m_isFlippedHorizontally = a_other.m_isFlippedHorizontally;
    this->m_isFlippedVertically = a_other.m_isFlippedVertically;
    this->m_isFilled = a_other.m_isFilled;

    return *this;
}

void ShapeLine::Draw(ascii::Canvas &a_canvas) const {
    if (this->m_isFlippedHorizontally || this->m_isFlippedVertically) {
        ascii::Point pointNum1AfterFlip(this->m_pointNum2.GetX(), this->m_pointNum1.GetY());
        ascii::Point pointNum2AfterFlip(this->m_pointNum1.GetX(), this->m_pointNum2.GetY()); 

        ascii::DrawLine(a_canvas, this->m_brush, pointNum1AfterFlip, pointNum2AfterFlip);
    } 
    else {
        ascii::DrawLine(a_canvas, this->m_brush, this->m_pointNum1, this->m_pointNum2);
    }
}