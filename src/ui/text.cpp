#include "builders.h"
#include "data.h"

#include <FL/Enumerations.H>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>

#include <optional>

TextBuilder::TextBuilder(const rect &rect) {
  base = rect;

  group = new Fl_Group(rect.x, rect.y, rect.w, rect.h);
  group->end();
}

Fl_Box *TextBuilder::setText(const char *label, const layout &layout) {
  int tw = base.w, th = base.h;
  textPos = {.x = layout.pos.x, .y = layout.pos.y};

  fl_font(FL_COURIER, layout.fontSize);
  fl_measure(label, tw, th);
  Fl_Box *box = new Fl_Box(textPos.x, textPos.y, tw, th);
  box->copy_label(label);

  if (layout.wrap)
    box->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_WRAP);

  box->labelsize(layout.fontSize);
  box->tooltip(layout.tooltip);
  box->box(FL_BORDER_FRAME); // testing

  // td if test is too short it will still wrap
  // td enforce min width

  return box;
}

void TextBuilder::setBG(const std::optional<background> &bg) {
  group->color(bg->bg_color);
  group->box(bg->box_type);
}

Fl_Group *TextBuilder::getGroup() { return group; }