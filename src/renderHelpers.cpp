#include "data.h"

#include <FL/Fl.H>
#include <FL/Fl_Group.H>

#include <functional>
#include <optional>

void createGroups(int x, int y, int width, int height, const std::function<void()> &content, std::optional<background> bg = std::nullopt)
{
  Fl_Group *group = new Fl_Group(x, y, width, height);

  content();

  if (bg)
  {
    group->color(bg->bg_color);
    group->box(bg->box_type);
  }

  group->end();
}