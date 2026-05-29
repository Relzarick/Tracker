#include "builders.h"
#include "data.h"
#include "helpers.h"

#include <FL/Enumerations.H>
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>

InputBuilder::InputBuilder(const rect &rect) {
  base = rect;

  group = new Fl_Group(rect.x, rect.y, rect.w, rect.h);
  group->end();
}

void InputBuilder::setBG(const std::optional<background> &bg) {
  group->color(bg->bg_color);
  group->box(bg->box_type);
}

Fl_Input *InputBuilder::setInput(const layout &layout) {
  auto input =
      new InputField(layout.pos.x, layout.pos.y, layout.pos.w, layout.pos.h);

  input->labelsize(layout.fontSize);
  input->tooltip(layout.tooltip);

  return input;
}

Fl_Group *InputBuilder::getGroup() { return group; }
