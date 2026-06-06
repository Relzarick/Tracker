#pragma once

#include <FL/Enumerations.H>
#include <FL/Fl.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>

class InputField : public Fl_Input {
public:
  InputField(int x, int y, int w, int h) : Fl_Input(x, y, w, h) {
    box(FL_FLAT_BOX);
    cursor_color(FL_WHITE);
  };

  int handle(int event) override {
    switch (event) {
    case FL_FOCUS: // show cursor
      renderInput(FL_BORDER_BOX, FL_BLACK);

      return Fl_Input::handle(event);

    case FL_UNFOCUS: // hide cursor
      renderInput(FL_FLAT_BOX, FL_WHITE);

      return Fl_Input::handle(event);

    case FL_KEYBOARD: // prevent input auto focus
      if (Fl::event_key() == FL_Enter)
        Fl::focus(Fl_Widget::window());

      return Fl_Input::handle(event);
    }

    return Fl_Input::handle(event);
  }

private:
  void renderInput(Fl_Boxtype boxType, Fl_Color cursorColor) {
    box(boxType);
    cursor_color(cursorColor);
    redraw();
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