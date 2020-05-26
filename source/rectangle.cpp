#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include "rectangle.hpp"

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
    col_ = {};
    highlight_color_ = {0.0f, 1.0f, 0.0f};
}
Rectangle::Rectangle(Vec2 const& v1, Vec2 const& v2, Color const& c) {
    Rectangle{v1, v2};
    col_ = c;
}
Rectangle::Rectangle(Color const& c, Vec2 const& v1, Vec2 const& v2) {
    Rectangle{v1, v2, c};
}
Rectangle::Rectangle(Vec2 const& v1, Vec2 const& v2, Color const& c, Color const& h) {
    Rectangle{v1, v2, c};
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
    Vec2 v1_, v2_;
    max_.x >= min_.x ? v1_.x = max_.x, v2_.x = min_.x : v1_.x = min_.x, v2_.x = max_.x ;
    max_.y >= min_.y ? v1_.y = max_.y, v2_.y = min_.y : v1_.y = min_.y, v2_.y = max_.y ;
    if ((v1_.x > v_.x || v2_.x < v_.x) || (v1_.y > v_.y || v2_.y < v_.y)) return false;
    return true;
}