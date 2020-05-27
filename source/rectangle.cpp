#include "rectangle.hpp"

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

#include <iostream>
#include <cmath>

Rectangle::Rectangle() {
    min_ = {0.0f, 0.0f};
    max_ = {50.0f, 50.0f};
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
    float xlen = abs(max_.x_ - min_.x_);
    float ylen = abs(max_.y_ - min_.y_);
    return 2 * (xlen + ylen);
}

void Rectangle::draw(Window const& w, bool const h) const {
    Color c;
    h ? c = highlight_color_ : c = col_;
    w.draw_line(max_.x_, max_.y_, max_.x_, min_.y_, c.r_, c.g_, c.b_, 1.0f);
    w.draw_line(max_.x_, min_.y_, min_.x_, min_.y_, c.r_, c.g_, c.b_, 1.0f);
    w.draw_line(min_.x_, min_.y_, min_.x_, max_.y_, c.r_, c.g_, c.b_, 1.0f);
    w.draw_line(min_.x_, max_.y_, max_.x_, max_.y_, c.r_, c.g_, c.b_, 1.0f);
}

bool Rectangle::is_inside(Vec2 const& v_) {
    //a_ and b_ make sure that a_ is actually max_ and b_ is actually min_
    Vec2 a{max_}, b{min_};
    if (max_.x_ < min_.x_) {
        a.x_ = min_.x_;
        b.x_ = max_.x_;
    }
    if (max_.y_ < min_.y_) {
        a.y_ = min_.y_;
        b.y_ = max_.y_;
    }
    if ((a.x_ < v_.x_ || b.x_ > v_.x_) || (a.y_ < v_.y_ || b.y_ > v_.y_)) return false;
    return true;
}