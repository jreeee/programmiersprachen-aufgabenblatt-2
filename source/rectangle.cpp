#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include "rectangle.hpp"
#include <iostream>

#include <cmath>

Rectangle::Rectangle() {
    min_ = {0.0f, 0.0f};
    max_ = {50.0f, 50.0f};
    col_ = {};
    highlight_color_ = {0.0f, 1.0f, 0.0f};
}
Rectangle::Rectangle(Vec2 const& v1, Vec2 const& v2) {
    min_ = v1;
    max_ = v2;
    highlight_color_ = {0.0f, 1.0f, 0.0f};
}
Rectangle::Rectangle(Vec2 const& v1, Vec2 const& v2, Color const& c) {
    min_ = v1;
    max_ = v2;
    col_ = c;
    highlight_color_ = {0.0f, 1.0f, 0.0f};
}

Rectangle::Rectangle(Vec2 const& v1, Vec2 const& v2, Color const& c, Color const& h) {
    min_ = v1;
    max_ = v2;
    col_ = c;
    highlight_color_ = h;
}

float Rectangle::circumference() {
    float xlen_ = abs(max_.x - min_.x);
    float ylen_ = abs(max_.y - min_.y);
    return 2 * (xlen_ + ylen_);
}

void Rectangle::draw(Window const& w, bool const h) const {
    Color c_;
    h ? c_ = highlight_color_ : c_ = col_;
    w.draw_line(max_.x, max_.y, max_.x, min_.y, c_.red, c_.green, c_.blue, 1.0f);
    w.draw_line(max_.x, min_.y, min_.x, min_.y, c_.red, c_.green, c_.blue, 1.0f);
    w.draw_line(min_.x, min_.y, min_.x, max_.y, c_.red, c_.green, c_.blue, 1.0f);
    w.draw_line(min_.x, max_.y, max_.x, max_.y, c_.red, c_.green, c_.blue, 1.0f);
}

bool Rectangle::is_inside(Vec2 const& v_) {
    Vec2 a_{max_}, b_{min_};
    if (max_.x < min_.x) {
        a_.x = min_.x;
        b_.x = max_.x;
    }
    if (max_.y < min_.y) {
        a_.y = min_.y;
        b_.y = max_.y;
    }
    if ((a_.x < v_.x || b_.x > v_.x) || (a_.y < v_.y || b_.y > v_.y)) return false;
    return true;
}