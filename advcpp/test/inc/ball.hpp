#ifndef BALL_HPP
#define BALL_HPP

namespace advcpp {

class Ball {
public:
    enum Color {
        BLACK = 0,
        RED,
        GREEN,
        BLUE,
        WHITE
    };

    Ball() = default;
    Ball(const Color &a_ballColor, const unsigned int a_radius);

    ~Ball() = default;

    Ball(const Ball &a_other) = default;
    Ball &operator=(const Ball &a_other) = default;

    bool operator<(const Ball &a_other);
    bool operator>(const Ball &a_other);
    bool operator==(const Ball &a_other);

    Color GetColor() const;
    unsigned int GetRadius() const;

private:
    Color m_ballColor = BLACK;
    unsigned int m_radius = 3;
};

} // advcpp

#endif // BALL_HPP
