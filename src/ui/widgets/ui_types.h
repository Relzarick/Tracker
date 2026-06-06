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

struct entryWidgetData { // no ownership semantics
  int id;
  Fl_Input *name;
  Fl_Input *price;
  Fl_Input *qty;
  Fl_Input *desc;
  Fl_Group *group;
};