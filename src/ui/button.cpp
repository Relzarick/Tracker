#include "builders.h"
#include "data.h"

#include <optional>

#include <FL/Fl.H>
#include <FL/Fl_Group.H>

BtnBuilder::BtnBuilder(const rect &rect) {
  base = rect;

  group = new Fl_Group(rect.x, rect.y, rect.w, rect.h);
  group->end();
}

void BtnBuilder::setBtn(rect size) {
  group->begin();

  // btn->labelfont(settings.font);
  // btn->labelsize(settings.fontSize);
  // btn->box(FL_BORDER_FRAME);

  group->end();
}

void BtnBuilder::setBG(const std::optional<background> &bg) {
  group->color(bg->bg_color);
  group->box(bg->box_type);
};

Fl_Group *BtnBuilder::getGroup() { return group; }
