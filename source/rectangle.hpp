#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rectangle {

    public:
    Rectangle();
    Rectangle(Vec2 const& v1, Vec2 const& v2);
    Rectangle(Vec2 const& v1, Vec2 const& v2, Color const& c);
    Rectangle(Color const& c, Vec2 const& v1, Vec2 const& v2);
    Rectangle(Vec2 const& v1, Vec2 const& v2, Color const& c, Color const& h);
    
    float circumference() const;
    void draw(Window const& w, bool highlight = false) const;
    bool is_inside(Vec2 const& v) const;

    private:
    Vec2 min_;
    Vec2 max_;
    Color col_;
    Color highlight_color_;
};

#endif