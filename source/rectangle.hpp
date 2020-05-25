#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rectangle {

    public:
    Rectangle();
    Rectangle(Vec2 const& v1, Vec2 const& v2);
    float circumference();

    private:
    Vec2 min_;
    Vec2 max_;
};

#endif