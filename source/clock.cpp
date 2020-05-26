#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"
#include "vec2.hpp"

int main(int argc, char* argv[])
{
    Window win{std::make_pair(800,800)};
    //origin_: middle of the clock
    Vec2 origin_ {400.0f, 400.0f};
    Circle outer_{380.0f, origin_, {0.1f, 0.1f, 0.1f}};
    Circle inner_{20.0f, origin_, {0.2f, 0.2f, 0.2f}};
    Circle hr_{200.0f, origin_, {1.0f, 0.0f, 0.0f}};
    Circle min_{250.0f, origin_, {0.0f, 1.0f, 0.0f}};
    Circle sec_{300.0f, origin_, {0.0f, 0.0f, 1.0f}};
    float passed = win.get_time();

    while (!win.should_close()) {
        if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        win.close();
        }
        passed = win.get_time();
        hr_.line(win, 360.0f, passed, 4.0f);
        min_.line(win, 60.0f, passed, 3.0f);
        sec_.line(win, 1.0f, passed, 2.0f);
        outer_.draw(win);
        inner_.draw(win);
        win.update();
    }
    return 0;
}