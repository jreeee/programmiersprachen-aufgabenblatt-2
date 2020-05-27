#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>

#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"
#include "vec2.hpp"

#include <cmath>
#include <array>

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  Rectangle r1 {};
  Rectangle r2 {{60.0f, 40.0f},{120.0f, 120.0f}};
  Rectangle r3 {{600.0f, 200.0f},{700.0f, 300.0f},{0.8f, 0.4f, 0.3f},{0.4f, 0.2f, 0.0f}};
  Rectangle r4 {{300.0f, 600.0f},{500.0f, 550.0f},{0.2f, 0.1f, 0.4f},{0.5f, 0.6f, 0.7f}};
  Rectangle r5 {{450.0f, 100.0f},{400.0f, 200.0f},{0.1f, 0.5f, 0.5f},{0.6f, 0.7f, 0.1f}};
  std::array<Rectangle, 5> ar{r1, r2, r3, r4, r5};
  Circle c1 {};
  Circle c2 {21.0f,{}};
  Circle c3 {270.0f,{500.0f, 300.0f},{0.3f, 0.5f, 0.9f},{0.9f, 0.3f, 0.5f}};
  Circle c4 {150.0f,{700.0f, 600.0f},{0.4f, 0.6f, 0.2f}, {1.0f, 0.f, 1.0f}};
  Circle c5 {34.0f,{600.0f, 200.0f},{0.1, 0.6f, 0.3f},{0.1f, 0.9f, 0.6f}};
  std::array<Circle, 5> ac{c1,c2,c3,c4,c5};
  bool in = false;

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }
    
    auto mouse = win.mouse_position();
    Vec2 mp{float(mouse.first), float(mouse.second)};
    for(unsigned int i = 0; i < ac.size(); i++) {
      in = ac[i].is_inside(mp);
      ac[i].draw(win, in);
      in = ar[i].is_inside(mp);
      ar[i].draw(win, in);
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

    win.update();
  }

  return 0;
}
