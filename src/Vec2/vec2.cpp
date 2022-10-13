#include <utility>
#include <cmath>
#include <iostream>
#include "vec2.h"

size_t Vec2Kernel::setX(size_t x)
{
    size_t old_x = x_;
    x_ = x;

    return old_x;
}

size_t Vec2Kernel::setY(size_t y)
{
    size_t old_y = y_;
    y_ = y;

    return old_y;    
}

std::ostream & operator<<(std::ostream &os, Vec2 &vec)
{
    os << "x = " << vec.getX() << ", y = " << vec.getY() << std::endl;
    
    return os;
}

bool Vec2::operator==(const Vec2 &vec) const
{
    return getX() == vec.getX() && getY() == vec.getY();
} 