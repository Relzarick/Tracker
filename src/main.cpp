#include "builders.h"
#include "data.h"

#include "tests.cpp"
#include "ui/director.h"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>

int main(int argc, char **argv) {
  int window_h = 750;

  Director dir = Director();
  contianerDimensions container{.w = 700};

  Fl_Window *window = new Fl_Window(container.w, window_h, "Test");

  TextBuilder title(rect{.x = 20, .y = 150, .w = 500, .h = 250});
  dir.constructEntry(title);

  // TextBuilder inputs(rect{.y = 200, .w = 350, .h = window_h - container.h});
  // inputs.setText(rect{.w = 350, .h = window_h - container.h}, "Input here");
  // inputs.setBG(bg);

  // insertTest();

  window->end();
  window->show(argc, argv);

  return Fl::run();
}
