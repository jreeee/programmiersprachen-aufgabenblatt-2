#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include "circle.hpp"
#include "mat2.hpp"

#include <cmath>
#include <iostream>

Circle::Circle() {
    mid_ = {0.0f, 0.0f};
    rad_ = 50.0f;
    col_ = {};
}
Circle::Circle(float f, Vec2 const& v) {
    rad_ = f;
    mid_ = v;
    col_ = {};
}
Circle::Circle(Vec2 const& v, float f) {
    mid_ = v;
    rad_ = f;
    col_ = {};
}
Circle::Circle(float f, Vec2 const& v, Color const& c) {
    rad_ = f;
    mid_ = v;
    col_ = c;
}
Circle::Circle(Vec2 const& v, float f, Color const& c) {
    mid_ = v;
    rad_ = f;
    col_ = c;
}

float Circle::circumference() {
    return 2 * M_PI * abs(rad_);
}

void Circle::draw(Window const& w) const {
    Vec2 v1_{0.0f, rad_};
    Vec2 v2_{v1_};
    int i_ = 0;
    const int seg_ = 50;
    const float part_ = M_PI / seg_;
    Mat2 rotm_{make_rotation_mat2(1/seg_)};

    while (i_ <= seg_) {
        i_++;
        rotm_ = make_rotation_mat2(i_ / part_);
        std::cout << i_ / part_ << " | " << i_ << " | " << seg_;
        v1_ = v2_;
        v2_ = rotm_ * v2_;
        w.draw_line(v1_.x, v1_.y, v2_.x, v2_.y, col_.red, col_.green, col_.blue, 1.0f);
    }
}