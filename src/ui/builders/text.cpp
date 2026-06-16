#include "builders.h"
#include "styles.h"

#include <FL/fl_draw.H>

TextBuilder::TextBuilder(const rect &rect) {
  base = rect;

  group = new Fl_Group(rect.x, rect.y, rect.w, rect.h);
  group->end();
}

Fl_Box *TextBuilder::setText(const char *label, const layout &layout) {
  int tw = base.w, th = base.h;
  textPos = {layout.pos.x, layout.pos.y};

  fl_font(FL_HELVETICA, textSize);
  fl_measure(label, tw, th);

  Fl_Box *box = new Fl_Box(textPos.x, textPos.y, tw, th);
  box->copy_label(label);

  box->labelsize(textSize);
  box->tooltip(layout.tooltip);

  // td enforce min width

  return box;
}

void TextBuilder::setBG(const std::optional<background> &bg) {
  group->color(bg->bg_color);
  group->box(bg->box_type);
}

Fl_Group *TextBuilder::getGroup() { return group; }