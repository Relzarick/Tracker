#pragma once

#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>

struct background {
  Fl_Color bg_color = FL_WHITE;
  Fl_Boxtype box_type = FL_ROUNDED_BOX;
};

struct rect {
  int x = 0;
  int y = 0;
  int w = 0;
  int h = 0;
};

struct layout {
  const char *tooltip;
  int fontSize = 22;
  rect pos;
};

struct widgetsData { // no ownership semantics??
  int id = 0;
  Fl_Input *name = nullptr;
  Fl_Input *price = nullptr;
  Fl_Input *qty = nullptr;
  Fl_Input *desc = nullptr;
  Fl_Group *group = nullptr;
};