#include "drawShape.hpp" /* Draw Shape Header */

char DrawShape::GetShapeBrush() const {
    return this->m_brush;
}
void DrawShape::SetShapeBrush(const char a_brush) {
    this->m_brush = a_brush;
}