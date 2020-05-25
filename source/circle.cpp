#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include "circle.hpp"

#include <cmath>

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