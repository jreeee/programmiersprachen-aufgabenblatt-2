#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include "circle.hpp"
#include "mat2.hpp"

#include <cmath>
#include <iostream>

Circle::Circle() {
    mid_ = {100.0f, 100.0f};
    rad_ = 50.0f;
    col_ = {};
    highlight_color_ = {1.0f, 0.0f, 0.0f};
}
Circle::Circle(float f, Vec2 const& v) {
    rad_ = f;
    mid_ = v;
    col_ = {};
    highlight_color_ = {1.0f, 0.0f, 0.0f};
}
Circle::Circle(Vec2 const& v, float f) {
    mid_ = v;
    rad_ = f;
    col_ = {};
    highlight_color_ = {1.0f, 0.0f, 0.0f};
}
Circle::Circle(float f, Vec2 const& v, Color const& c) {
    rad_ = f;
    mid_ = v;
    col_ = c;
    highlight_color_ = {1.0f, 0.0f, 0.0f};
}
Circle::Circle(Vec2 const& v, float f, Color const& c) {
    mid_ = v;
    rad_ = f;
    col_ = c;
    highlight_color_ = {1.0f, 0.0f, 0.0f};
}
Circle::Circle(float f, Vec2 const& v, Color const& c, Color const& h) {
    rad_ = f;
    mid_ = v;
    col_ = c;
    highlight_color_ = h;
}

float Circle::circumference() {
    return 2 * M_PI * abs(rad_);
}

void Circle::draw(Window const& w, bool const h) const {
    Color c_;
    h ? c_ = highlight_color_ : c_ = col_;
    const Vec2 origin_ {rad_, rad_};
    Vec2 v1_{origin_};
    Vec2 v2_{origin_};
    int i_ = 1;
    const int seg_ = 50;
    const float part_ = seg_ / (2 * M_PI);
    v2_ = v2_ + mid_;
    while (i_ <= seg_) {
        v1_ = v2_;
        v2_ = origin_;
        v2_ = make_rotation_mat2(i_ / part_) * v2_;
        v2_ = mid_ + v2_;
        w.draw_line(v1_.x, v1_.y, v2_.x, v2_.y, c_.red, c_.green, c_.blue, 1.0f);
        i_++;
    }
}