#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>

#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"
#include "vec2.hpp"

#include <cmath>

int main(int argc, char* argv[])
{
    Window win{std::make_pair(800,800)};
    //origin_: middle of the clock
    Vec2 origin {400.0f, 400.0f};
    Circle outer{380.0f, origin, {0.1f, 0.1f, 0.1f}};
    Circle inner{7.0f, origin, {0.2f, 0.2f, 0.2f}};
    Circle hr{200.0f, origin, {1.0f, 0.0f, 0.0f}};
    Circle min{250.0f, origin, {0.0f, 1.0f, 0.0f}};
    Circle sec{300.0f, origin, {0.0f, 0.0f, 1.0f}};
    float passed = win.get_time();

    //only for the min/quart/hr marks
    int mod = 0;
    float ds = 20.0f;
    float th = 1.0f;

    while (!win.should_close()) {
        if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        win.close();
        }
        passed = win.get_time();

        //only for the min/quart/hr marks
        for (int i = 0; i < 60; i ++){
            if (mod % 5 == 0) {
                ds = 40.0f;
                th = 2.0f;
                if(mod % 15 == 0) {
                    mod = 0;
                    ds = 60.0f;
                    th = 3.0f;
                }
            }
            outer.line(win, 1.0f, i, th, ds);
            th = 1.0f;
            ds = 20.0f;
            mod++;
        }

        hr.line(win, 360.0f, passed, 4.0f);
        min.line(win, 60.0f, passed, 3.0f);
        sec.line(win, 1.0f, passed, 2.0f);
        outer.draw(win, false,  5.0f);
        inner.draw(win, false, 5.0f);
        win.update();
    }
    return 0;
}