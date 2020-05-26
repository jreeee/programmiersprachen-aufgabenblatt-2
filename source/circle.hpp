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
    Circle(float const f, Vec2 const& v, Color const& c);
    Circle(Vec2 const& v, float const f, Color const& c);
    Circle(float const f, Vec2 const& v, Color const& c, Color const& h);

    float circumference();
    void draw(Window const& w, bool highlight = false) const;

    private:
    Vec2 mid_;
    float rad_;
    Color col_;
    Color highlight_color_;
};

#endif