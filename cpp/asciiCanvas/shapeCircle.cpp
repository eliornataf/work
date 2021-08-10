#include "canvas.hpp" /* Canvas Header */
#include "drawShape.hpp" /* Draw Shape Header */
#include "shape.hpp" /* Shape Header */
#include "shapeCircle.hpp" /* Shape Circle Header */
#include "point.hpp" /* Point Header */

ShapeCircle::ShapeCircle(const ascii::Point &a_point, const size_t &a_radius, const char &a_brush) 
: m_point(a_point)
, m_radius(a_radius) {
    this->m_brush = a_brush;
}

ShapeCircle::~ShapeCircle() {
}

ShapeCircle::ShapeCircle(const ShapeCircle &a_other) 
: m_point(a_other.m_point)
, m_radius(a_other.m_radius) {
    this->m_brush = a_other.m_brush;
    this->m_isFlippedHorizontally = a_other.m_isFlippedHorizontally;
    this->m_isFlippedVertically = a_other.m_isFlippedVertically;
    this->m_isFilled = a_other.m_isFilled;
}

ShapeCircle &ShapeCircle::operator=(const ShapeCircle &a_other) {
    this->m_point = a_other.m_point;
    this->m_radius = a_other.m_radius;
    this->m_brush = a_other.m_brush;
    this->m_isFlippedHorizontally = a_other.m_isFlippedHorizontally;
    this->m_isFlippedVertically = a_other.m_isFlippedVertically;
    this->m_isFilled = a_other.m_isFilled;

    return *this;
}

void ShapeCircle::Draw(ascii::Canvas &a_canvas) const {
    ascii::DrawCircle(a_canvas, this->m_brush, this->m_point, this->m_radius);

    if (this->m_isFilled) {
        for (size_t i = 1;i < this->m_radius;++i) {
             ascii::DrawCircle(a_canvas, this->m_brush, this->m_point, i);
        }
    }
}
