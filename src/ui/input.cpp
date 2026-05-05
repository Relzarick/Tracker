#include "builders.h"
#include "data.h"

#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>

InputBuilder::InputBuilder(rect size) {
  base = size;

  group = new Fl_Group(size.x, size.y, size.w, size.h);

  // Fl_Input *input = new Fl_Input(170, 350, 100, 40); // set predefined size
  // input->when(FL_WHEN_ENTER_KEY);
  group->end();
}

void InputBuilder::setBG(const std::optional<background> &bg) {
  if (bg) {
    group->color(bg->bg_color);
    group->box(bg->box_type);
  }
}

Fl_Input *InputBuilder::getInput() { return input; }

Fl_Group *InputBuilder::getGroup() { return group; }
