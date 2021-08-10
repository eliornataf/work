#include "shape.hpp" /* Shape Header */

Shape::Shape() 
: m_isFlippedHorizontally(false)
, m_isFlippedVertically(false)
, m_isFilled(false) {
}

Shape::~Shape() {
}

Shape::Shape(const Shape &a_other) 
: m_isFlippedHorizontally(a_other.m_isFlippedHorizontally)
, m_isFlippedVertically(a_other.m_isFlippedVertically)
, m_isFilled(a_other.m_isFilled) {
}

Shape &Shape::operator=(const Shape &a_other) {
    this->m_isFlippedHorizontally = a_other.m_isFlippedHorizontally;
    this->m_isFlippedVertically = a_other.m_isFlippedVertically;
    this->m_isFilled = a_other.m_isFilled;

    return *this;
}

bool Shape::IsFlippedHorizontally() const {
    return this->m_isFlippedHorizontally;
}

bool Shape::IsFlippedVertically() const {
    return this->m_isFlippedVertically;
}

bool Shape::IsFilled() const {
    return this->m_isFilled;
}

void Shape::FlipUnFlipHorizontally() {
    this->m_isFlippedHorizontally = !this->m_isFlippedHorizontally;
}

void Shape::FlipUnFlipVertically() {
    this->m_isFlippedVertically = !this->m_isFlippedVertically;
}

void Shape::FilledUnFilled() {
    this->m_isFilled = !this->m_isFilled;
}