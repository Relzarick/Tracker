#include "builders.h"
#include "data.h"

#include <FL/Fl.H>
#include <FL/Fl_Group.H>

#include <optional>

TextBuilder::TextBuilder(rect size) {
  base = size;

  group = new Fl_Group(size.x, size.y, size.w, size.h);
  group->end();
}

void TextBuilder::setText(rect rect, const char *label) {
  group->begin();
  Fl_Box *text =
      new Fl_Box(base.x + rect.x, base.y + rect.y, rect.w, rect.h, label);
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
