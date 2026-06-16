#include "builders.h"

#include <optional>

#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>

BtnBuilder::BtnBuilder(const rect &rect) {
  base = rect;

  group = new Fl_Group(rect.x, rect.y, rect.w, rect.h);
  group->end();
}

Fl_Button *BtnBuilder::setBtn(int height) {
  btn = new Fl_Button(base.x, base.y, base.w, height);

  btn->box(FL_ROUNDED_BOX);
  btn->down_box(FL_ROUNDED_BOX);

  btn->color(FL_WHITE);
  btn->selection_color(fl_rgb_color(242, 240, 239));

  return btn;
}

void BtnBuilder::setBG(const std::optional<background> &bg) {
  btn->box(bg->box_type);
  btn->down_box(bg->box_type);
  btn->down_color(bg->bg_color);
};

Fl_Group *BtnBuilder::getGroup() { return group; }