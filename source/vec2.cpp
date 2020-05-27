#include "vec2.hpp"

#include <iostream>

Vec2& Vec2::operator+=(Vec2 const& v) {
    x_ += v.x_;
    y_ += v.y_;
    return *this;
}

Vec2& Vec2::operator-=(Vec2 const& v) {
    x_ -= v.x_;
    y_ -= v.y_;
    return *this;
}

Vec2& Vec2::operator*=(float s) {
    x_ *= s;
    y_ *= s;
    return *this;
}

Vec2& Vec2::operator/=(float s) {
    if (s == 0.0f) {
        std::cout << "ERROR: division by zero (Vec2)\n";
    }
    else {
        x_ /= s;
        y_ /= s;
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