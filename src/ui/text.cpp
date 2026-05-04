#include "builders.h"
#include "data.h"

#include <FL/Fl.H>
#include <FL/Fl_Group.H>

#include <optional>

TextBuilder::TextBuilder(int x, int y, int w, int h) {
  baseX = x;
  baseY = y;

  group = new Fl_Group(x, y, w, h);
  group->end();
}

void TextBuilder::setText(int x, int y, int w, int h, const char *label) {
  group->begin();
  Fl_Box *text = new Fl_Box(baseX + x, baseY + y, w, h, label);
  // create a struct for label fonts

  text->labelfont(FL_BOLD);
  text->labelsize(36);
  group->end();
}

void TextBuilder::setBG(const std::optional<background> &bg) {
  if (bg) {
    group->color(bg->bg_color);
    group->box(bg->box_type);
  }
}

Fl_Group *TextBuilder::getGroup() { return group; }
