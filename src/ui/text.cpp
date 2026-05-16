#include "builders.h"
#include "data.h"

#include <FL/Enumerations.H>
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>

#include <optional>

TextBuilder::TextBuilder(const rect &rect) {
  baseRect = rect;

  group = new Fl_Group(rect.x, rect.y, rect.w, rect.h);
  group->end();
}

void TextBuilder::setText(const char *label, const layout &settings) {
  int tw = baseRect.w, th = baseRect.h;
  textPos = {.x = settings.pos.x, .y = settings.pos.y};

  fl_font(settings.font, settings.fontSize);
  fl_measure(label, tw, th);
  Fl_Box *box = new Fl_Box(textPos.x, textPos.y, tw, th, label);

  if (settings.wrap)
    box->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_WRAP);

  box->labelfont(settings.font);
  box->labelsize(settings.fontSize);
  box->tooltip(settings.tooltip);
}

void TextBuilder::setBG(const std::optional<background> &bg) {
  group->color(bg->bg_color);
  group->box(bg->box_type);
}

Fl_Group *TextBuilder::getGroup() { return group; }