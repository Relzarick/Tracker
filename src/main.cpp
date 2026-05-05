#include "builders.h"
#include "data.h"

#include "tests.cpp"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>

int main(int argc, char **argv) {
  int window_h = 750;

  contianerDimensions container;
  container.w = 700;
  background bg;

  Fl_Window *window = new Fl_Window(container.w, window_h, "Test");

  rect titleRect{.w = container.w, .h = container.h};
  rect titleTextRect{.w = container.w, .h = container.h};

  TextBuilder title(titleRect);
  title.setText(titleTextRect, "Tracking stuff...");
  title.setBG(bg);

  rect inputRect{.y = 200, .w = 350, .h = window_h - container.h};
  rect inputTextRect{.w = 350, .h = window_h - container.h};

  TextBuilder inputs(inputRect);
  inputs.setText(inputTextRect, "Input here");
  inputs.setBG(bg);

  insertTest();

  window->end();
  window->show(argc, argv);

  return Fl::run();
}
