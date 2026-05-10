#include "builders.h"
#include "data.h"

#include <FL/Enumerations.H>
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>

#include <optional>
#include <print>

TextBuilder::TextBuilder(rect size) {
  base = size;

  group = new Fl_Group(size.x, size.y, size.w, size.h);
  group->clip_children(1);
  group->end();
}

void TextBuilder::setText(rect offset, const char *label) {
  group->begin();

  int tw = 0, th = 0;
  textPos = {.x = base.x + offset.x, .y = base.y + offset.y};

  determinePos(tw, th, label);

  Fl_Box *text = new Fl_Box(textPos.x, textPos.y, base.w, base.h, label);

  text->align(FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE);
  text->labelfont(FL_BOLD);
  text->labelsize(24);

  group->end();
}

void TextBuilder::determinePos(int &tw, int &th, const char *label) {
  fl_font(FL_BOLD, 24);
  fl_measure(label, tw, th);

  std::print("PX:      w={} h={}\n", tw, th);
  std::print("POS:     x={} y={}\n", textPos.x, textPos.y);
  std::print("NEW POS: x={} y={}\n\n", textPos.x + tw, textPos.y + th);

  // calc textPos + offset = next available space

  // There should be set positions, setText take a string that specifies where
  // to place. caller dont determine where it is located
}

void TextBuilder::setBG(const std::optional<background> &bg) {
  if (bg) {
    group->color(bg->bg_color);
    group->box(bg->box_type);
  }
}

Fl_Group *TextBuilder::getGroup() { return group; }