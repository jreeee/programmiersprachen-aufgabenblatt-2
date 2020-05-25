#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include "circle.hpp"

#include <cmath>

Circle::Circle() {
    mid_ = {0.0f, 0.0f};
    rad_ = 50.0f;
}
Circle::Circle(float f, Vec2 const& v) {
    rad_ = f;
    mid_ = v;
}
Circle::Circle(Vec2 const& v, float f) {
    mid_ = v;
    rad_ = f;
}

float Circle::circumference() {
    return 2 * M_PI * abs(rad_);
}