#include "methods.h"
#include "data.h"

#include "tests.cpp"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>

int main(int argc, char **argv)
{
  int window_h = 750;

  contianerDimensions container;
  container.w = 700;

  Fl_Window *window = new Fl_Window(container.w, window_h, "Test");

  background bg;
  GroupBuilder title(0, 0, container.w, container.h);
  title.setText(0, 0, container.w, container.h, "Tracking stuff...");
  title.setBG(bg);

  GroupBuilder inputs(0, 200, 350, window_h - container.h);
  inputs.setText(0, 0, 350, window_h - container.h, "Input here");
  inputs.setBG(bg);

  window->end();
  window->show(argc, argv);

  start();
  return Fl::run();
}

void start()
{
  // testPrint();
}