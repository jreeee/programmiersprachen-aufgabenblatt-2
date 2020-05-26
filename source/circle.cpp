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
    highlight_color_ = {1.0f, 0.0f, 0.0f};
}

Circle::Circle(float f, Vec2 const& v, Color const& c) {
    rad_ = f;
    mid_ = v;
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
    float r_ = sqrt((rad_ / 2) * (rad_ / 2) * 2 );
    const Vec2 origin_ {r_, r_};
    Vec2 v1_{origin_};
    Vec2 v2_{origin_};
    int i_ = 1;
    const int seg_ = 200;
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

bool Circle::is_inside(Vec2 const& v) {
    Vec2 vdist_ = mid_ - v;
    float dist_ = sqrt((vdist_.x * vdist_.x) + (vdist_.y * vdist_.y));
    return (dist_ <= rad_ ? true : false);
}

void Circle::line(Window const& w, float time, float passed, float thickness) {
    float r_ = sqrt((rad_ / 2) * (rad_ / 2) * 2 );
    const Vec2 origin_ {r_, r_};
    Vec2 v1_{origin_};
    const float zero_ = (3.0f / 4.0f) * M_PI;
    const float part_ = 60 / (2 * M_PI);
    v1_ = make_rotation_mat2(((passed / time) / -part_) + zero_) * v1_ ;
    v1_ = mid_ + v1_;
    w.draw_line(v1_.x, v1_.y, mid_.x, mid_.y, col_.red, col_.green, col_.blue, thickness);
}