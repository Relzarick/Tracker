#include "builders.h"
#include "data.h"

#include <optional>

#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>

BtnBuilder::BtnBuilder(const rect &rect) {
  base = rect;

  group = new Fl_Group(rect.x, rect.y, rect.w, rect.h);
  group->end();
}

void BtnBuilder::setBtn(const layout &settings) {
  Fl_Button *btn = new Fl_Button(base.x, base.y, base.w, base.h);
  this->btn = btn;

  btn->box(FL_ROUNDED_BOX);
  btn->down_box(FL_ROUNDED_BOX);

  btn->color(FL_WHITE);
  btn->selection_color(fl_rgb_color(242, 240, 239));
}

void BtnBuilder::setBG(const std::optional<background> &bg) {
  group->color(bg->bg_color);
  group->box(bg->box_type);
};

Fl_Group *BtnBuilder::getGroup() { return group; }
Fl_Button *BtnBuilder::getBtn() { return btn; }