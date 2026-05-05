#include "builders.h"
#include "data.h"

#include <optional>

#include <FL/Fl.H>
#include <FL/Fl_Group.H>

BtnBuilder::BtnBuilder(rect size) {
  base = size;

  group = new Fl_Group(size.x, size.y, size.w, size.h);
  group->end();
}

void BtnBuilder::setBtn(rect size) {
  // create btn here with a set style
}

void BtnBuilder::setBG(const std::optional<background> &bg) {
  if (bg) {
    group->color(bg->bg_color);
    group->box(bg->box_type);
  }
};

Fl_Group *BtnBuilder::getGroup() { return group; }
