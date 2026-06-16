#include "builders.h"

#include "custom_widgets.h"
#include "styles.h"
#include "ui_types.h"

InputBuilder::InputBuilder(const rect &rect) {
  base = rect;

  group = new Fl_Group(rect.x, rect.y, rect.w, rect.h);
  group->end();
}

Fl_Input *InputBuilder::setInput(const layout &layout) {
  auto input =
      new InputField(layout.pos.x, layout.pos.y, layout.pos.w, layout.pos.h);

  input->textsize(textSize);
  input->tooltip(layout.tooltip);

  return input;
}

Fl_Input *InputBuilder::SetMultilineInput(const layout &layout) {
  auto multiInput =
      new BigInputField(layout.pos.x, layout.pos.y, layout.pos.w, layout.pos.h);

  multiInput->textsize(textSize);
  multiInput->tooltip(layout.tooltip);

  return multiInput;
}

void InputBuilder::setBG(const std::optional<background> &bg) {
  group->color(bg->bg_color);
  group->box(bg->box_type);
}

Fl_Group *InputBuilder::getGroup() { return group; }
