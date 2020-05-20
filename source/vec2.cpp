#include "vec2.hpp"
//#include "iostream"

Vec2& Vec2::operator+=(Vec2 const& rhs) {
    x+=rhs.x;
    y+=rhs.y;
    return *this;
}

Vec2& Vec2::operator+=(Vec2 const& rhs) {
    x-=rhs.x;
    y-=rhs.y;
    return *this;
}

Vec2& Vec2::operator*=(float rhs) {
    x*=rhs;
    y*=rhs;
    return *this;
}

Vec2& Vec2::operator/=(float rhs) {
    if (rhs == 0) {
        x=y=0;
    }
    else {
        x/=rhs;
        y/=rhs;
    }
    return *this;
}

Vec2& operator+(Vec2 const& lhs, Vec2 const& rhs) {
    return Vec2(lhs) += rhs;
}