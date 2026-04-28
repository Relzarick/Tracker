#include "methods.h"
#include "data.h"

#include "tests.cpp"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>

int main(int argc, char **argv)
{
  int window_h = 550;
  int window_w = 600;
  int header_h = 100;

  Fl_Window *window = new Fl_Window(window_w, window_h, "Test");
  renderTitle(window_w, header_h);
  renderInputs();

  window->end();
  window->show(argc, argv);

  start();
  return Fl::run();
}

void start()
{
  // testPrint();
}

void renderTitle(int width, int height)
{
  int x = 0, y = 0;

  auto createBox = [&]()
  {
    Fl_Box *title_header = new Fl_Box(x + 20, y + 5, width, height, "Tracking stuff...");

    title_header->labelfont(FL_BOLD + FL_ITALIC);
    title_header->labelsize(36);
  };

  background bg;
  createGroups(x, y, width, height, createBox, bg);
}

void renderInputs()
{
  int width = 300;
  int height = 450;
  int x = 0, y = 100;

  auto createBox = [&]()
  {
    Fl_Box *title_header = new Fl_Box(x, y, width, height, "Input here");

    title_header->labelfont(FL_BOLD + FL_ITALIC);
    title_header->labelsize(36);
  };

  background bg;
  createGroups(x, y, width, height, createBox, bg);
}
