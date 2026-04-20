#include "methods.h"
#include "data.h"

#include "tests.cpp"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>

int main(int argc, char **argv)
{
  int window_h = 450;
  int window_w = 550;
  int header_h = 100;

  Fl_Window *window = new Fl_Window(window_w, window_h, "Test");

  Fl_Group *header_div = new Fl_Group(0, 0, window_w, header_h);
  Fl_Box *title_header = new Fl_Box(20, 5, window_w, header_h, "Tracker stuff...");

  title_header->labelfont(FL_BOLD + FL_ITALIC);
  title_header->labelsize(36);

  header_div->end();

  window->end();
  window->show(argc, argv);

  start();
  return Fl::run();
}

void start()
{
  // testPrint();
}
