#include "ball.hpp" // Ball Header

using namespace advcpp;

Ball::Ball(const Color &a_ballColor, const unsigned int a_radius)
: m_ballColor(a_ballColor)
, m_radius(a_radius) {
}

bool Ball::operator<(const Ball &a_other) 
{
    return this->m_radius < a_other.m_radius;
}

bool Ball::operator>(const Ball &a_other) 
{
    return this->m_radius > a_other.m_radius;
}

bool Ball::operator==(const Ball &a_other) 
{
    return this->m_radius == a_other.m_radius && this->m_ballColor == a_other.m_ballColor;
}

Ball::Color Ball::GetColor() const {
    return this->m_ballColor;
}

unsigned int Ball::GetRadius() const {
    return this->m_radius;
}