#include "builders.h"
#include "data.h"

#include <FL/Enumerations.H>
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>

#include <optional>
#include <print>

TextBuilder::TextBuilder(const rect &size) {
  base = size;

  group = new Fl_Group(size.x, size.y, size.w, size.h);
  group->clip_children(1);
  group->end();
}

void TextBuilder::setText(const rect &offset, const char *label) {
  group->begin();

  int tw = 0, th = 0;
  textPos = {.x = base.x + offset.x, .y = base.y + offset.y};

  determinePos(tw, th, label);

  Fl_Box *box = new Fl_Box(textPos.x, textPos.y, base.w, base.h, label);

  box->align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_WRAP);
  box->labelfont(FL_BOLD);
  box->labelsize(22);
  // box->box(FL_BORDER_FRAME);

  group->end();
}

void TextBuilder::determinePos(int &tw, int &th, const char *label) {
  fl_font(FL_BOLD, 24);
  fl_measure(label, tw, th);

  std::print("PX:      w={} h={}\n", tw, th);
  std::print("POS:     x={} y={}\n", textPos.x, textPos.y);
  std::print("NEW POS: x={} y={}\n\n", textPos.x + tw, textPos.y + th);

  // calc textPos + offset = next available space
  // ? work on making it auto adjust
}

void TextBuilder::setBG(const std::optional<background> &bg) {
  group->color(bg->bg_color);
  group->box(bg->box_type);
}

Fl_Group *TextBuilder::getGroup() { return group; }