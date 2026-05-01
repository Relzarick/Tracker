#include "data.h"
#include "methods.h"

#include <FL/Fl.H>
#include <FL/Fl_Group.H>

#include <functional>
#include <optional>

GroupBuilder::GroupBuilder(int x, int y, int width, int height)
{
  baseX = x;
  baseY = y;

  group = new Fl_Group(x, y, width, height);
  group->end();
}

void GroupBuilder::setText(int x, int y, int width, int height, std::string label)
{
  storedLabel = label;

  group->begin();
  Fl_Box *text = new Fl_Box(baseX + x, baseY + y, width, height, storedLabel.c_str());
  // create a struct for label fonts

  text->labelfont(FL_BOLD + FL_ITALIC);
  text->labelsize(36);
  group->end();
}

void GroupBuilder::setBG(std::optional<background> bg)
{
  if (bg)
  {
    group->color(bg->bg_color);
    group->box(bg->box_type);
  }
}