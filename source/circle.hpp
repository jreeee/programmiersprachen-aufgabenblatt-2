#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle {

    public:
    Circle();
    Circle(float f, Vec2 const& v);
    Circle(Vec2 const& v, float f);

    float circumference();

    private:
    Vec2 mid_;
    float rad_;
};

#endif