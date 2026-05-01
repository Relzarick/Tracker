#include "data.h"
#include "methods.h"

#include <FL/Fl.H>
#include <FL/Fl_Group.H>

#include <optional>

TextBuilder::TextBuilder(int x, int y, int width, int height)
{
  baseX = x;
  baseY = y;

  group = new Fl_Group(x, y, width, height);
  group->end();
}

void TextBuilder::setText(int x, int y, int width, int height, const char *label)
{
  group->begin();
  Fl_Box *text = new Fl_Box(baseX + x, baseY + y, width, height, label);
  // create a struct for label fonts
  // breaks encapsulation, use vector
  // breaks if pass in runtime str

  text->labelfont(FL_BOLD);
  text->labelsize(36);
  group->end();
}

void TextBuilder::setBG(std::optional<background> bg)
{
  if (bg)
  {
    group->color(bg->bg_color);
    group->box(bg->box_type);
  }
}