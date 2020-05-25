#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include "rectangle.hpp"

#include <cmath>

Rectangle::Rectangle() {
    min_ = {0.0f, 0.0f};
    max_ = {50.0f, 50.0f};
    col_ = {};
}
Rectangle::Rectangle(Vec2 const& v1, Vec2 const& v2) {
    min_ = v1;
    max_ = v2;
    col_ = {};
}
Rectangle::Rectangle(Vec2 const& v1, Vec2 const& v2, Color const& c) {
    min_ = v1;
    max_ = v2;
    col_ = c;
}
Rectangle::Rectangle(Color const& c, Vec2 const& v1, Vec2 const& v2) {
    min_ = v1;
    max_ = v2;
    col_ = c;
}

float Rectangle::circumference() {
    float xlen_ = abs(max_.x - min_.x);
    float ylen_ = abs(max_.y - min_.y);
    return 2 * (xlen_ + ylen_);
}

