#include "custom_widgets.h"

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

InputField::InputField(int x, int y, int w, int h) : Fl_Input(x, y, w, h) {
  box(FL_FLAT_BOX);
  cursor_color(FL_WHITE);
}

int InputField::handle(int event) {
  switch (event) {
  case FL_FOCUS: // show cursor
    styleInput(FL_BORDER_BOX, FL_BLACK);

    return Fl_Input::handle(event);

  case FL_UNFOCUS: // hide cursor
    styleInput(FL_FLAT_BOX, FL_WHITE);

    return Fl_Input::handle(event);

  case FL_KEYBOARD: // prevent input auto focus
    if (Fl::event_key() == FL_Enter)
      Fl::focus(Fl_Widget::window());
  }

  return Fl_Input::handle(event);
}

void InputField::styleInput(Fl_Boxtype boxType, Fl_Color cursorColor) {
  box(boxType);
  cursor_color(cursorColor);
  redraw();
}

BigInputField::BigInputField(int x, int y, int w, int h)
    : Fl_Multiline_Input(x, y, w, h) {
  box(FL_FLAT_BOX);
  cursor_color(FL_WHITE);
};

int BigInputField::handle(int event) {
  switch (event) {
  case FL_FOCUS: // show cursor
    styleInput(FL_BORDER_BOX, FL_BLACK);

    return Fl_Multiline_Input::handle(event);

  case FL_UNFOCUS: // hide cursor
    styleInput(FL_FLAT_BOX, FL_WHITE);

    return Fl_Multiline_Input::handle(event);

  case FL_KEYBOARD: // handle Keyboard Inputs && prevents auto focus
    return KeyboardInputs(event);
  }

  return Fl_Multiline_Input::handle(event);
}

void BigInputField::styleInput(Fl_Boxtype boxType, Fl_Color cursorColor) {
  box(boxType);
  cursor_color(cursorColor);
  redraw();
}

int BigInputField::KeyboardInputs(int event) {
  int key = Fl::event_key();

  if (Fl::event_length() > 0 && key != FL_Enter && key != FL_BackSpace)
    return handleFormat(event);

  if (key == FL_Enter && Fl::event_state(FL_SHIFT)) {
    const char *val = value();
    int lines = std::count(val, val + strlen(val), '\n');

    if (lines + 1 >= maxRows)
      return 1;

  } else if (key == FL_Enter) {
    Fl::focus(Fl_Widget::window());
    return 1;
  }

  return Fl_Input::handle(event);
}

int BigInputField::handleFormat(int event) {
  int cursorPos = insert_position();

  std::string row;
  std::vector<std::string> rows;

  const char *val = value();
  std::string desc(val);
  std::istringstream stream(desc);

  while (std::getline(stream, row))
    rows.push_back(row);

  if (rows.empty())
    return Fl_Input::handle(event);

  int rowPos = std::count(val, val + cursorPos, '\n');

  if (rowPos >= rows.size())
    rowPos = rows.size() - 1;

  int rowSize = rows[rowPos].size();

  if (rowSize >= lineSize && rows.size() < maxRows) {
    std::ostringstream stream;

    for (int i = 0; i < rows.size(); i++) {
      stream << rows[i];
      stream << '\n';
    }

    value(stream.str().c_str());
    position(cursorPos + 1);

  } else if (rowSize >= lineSize)
    return 1;

  // * 50 char limit but char are diff sizes result in diff max length
  // td Could measure the rowSize against width

  return Fl_Input::handle(event);
}

Window::Window(int w, int h, const char *title) : Fl_Window(w, h, title) {};

int Window::handle(int event) {
  switch (event) {
  case FL_PUSH: // click anywhere
    Fl::focus(this);

    return Fl_Window::handle(event);
  }

  return Fl_Window::handle(event);
}
