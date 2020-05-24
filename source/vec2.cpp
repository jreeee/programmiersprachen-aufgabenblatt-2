#include "vec2.hpp"

Vec2& Vec2::operator+=(Vec2 const& rhs) {
    x+=rhs.x;
    y+=rhs.y;
    return *this;
}

Vec2& Vec2::operator-=(Vec2 const& rhs) {
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

Vec2 operator+(Vec2 const& u, Vec2 const& v) {
    return Vec2(u) += v;
}

Vec2 operator-(Vec2 const& u, Vec2 const& v) {
    return Vec2(u) -= v;
}

Vec2 operator*(Vec2 const& u, float s) {
    return Vec2(u) *= s;
}

Vec2 operator/(Vec2 const& u, float s) {
    return Vec2(u) /= s;
}

Vec2 operator*(float s, Vec2 const& v) {
    return Vec2(v) *= s;
}