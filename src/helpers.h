#pragma once

#include "database.h"
#include "director.h"

#include <FL/Enumerations.H>
#include <FL/Fl_Input_.H>
#include <FL/Fl_Window.H>

void fetchFromDB(DB *db, Director *dir);
void createInput();

class InputField : public Fl_Input {
public:
  InputField(int x, int y, int w, int h) : Fl_Input(x, y, w, h) {
    box(FL_FLAT_BOX);
    cursor_color(FL_WHITE);
  };

  int handle(int event) override {
    switch (event) {
    case FL_FOCUS: // show cursor
      box(FL_BORDER_BOX);
      cursor_color(FL_BLACK);
      redraw();

      return Fl_Input::handle(event);

    case FL_UNFOCUS: // hide cursor
      box(FL_FLAT_BOX);
      cursor_color(FL_WHITE);
      redraw();

      return Fl_Input::handle(event);
    }

    return Fl_Input::handle(event);
  }
};

class Window : public Fl_Window {
public:
  Window(int w, int h, const char *title) : Fl_Window(w, h, title) {};

  int handle(int event) override {
    switch (event) {
    case FL_PUSH: // click anywhere
      Fl::focus(this);

      return Fl_Window::handle(event);
    }

    return Fl_Window::handle(event);
  }
};