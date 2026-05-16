#include "builders.h"
#include "data.h"
#include "tests.cpp"
#include "ui/director.h"

#include <FL/Fl.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Tooltip.H>
#include <FL/Fl_Window.H>

int main(int argc, char **argv) {
  int width = 700;
  int height = 750;
  int x = 15;
  int divWidth = 660;

  Fl_Window window(width, height, "Tracker");
  Fl_Scroll sc(0, 0, width, height);

  sc.type(Fl_Scroll::VERTICAL);
  sc.scrollbar.color(sc.color());

  Fl_Pack pack(x, 0, divWidth, height);
  pack.spacing(16);

  Fl::visible_focus(0);
  Fl_Tooltip::font(FL_COURIER);
  Fl_Tooltip::color(fl_rgb_color(242, 240, 239));

  Director dir = Director(&pack);

  TextBuilder title(rect{.w = divWidth, .h = 250});
  dir.constructEntry(title);

  BtnBuilder btn(rect{.w = divWidth, .h = 95});
  dir.constructAddBtn(btn);

  // insertTest();

  pack.end();
  sc.end();
  window.end();
  window.show(argc, argv);

  return Fl::run();
}