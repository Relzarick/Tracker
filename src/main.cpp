#include "database.h"
#include "director.h"
#include "startup.h"

#include "Entries_mediator.h"
#include "widgets/custom_widgets.h"
#include "widgets/styles.h"

#include "FL/Fl_PNG_Image.H"
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Tooltip.H>

void appSetting(Window *win) {
  Fl::focus(win);
  Fl::visible_focus(0);

  Fl_Tooltip::color(fl_rgb_color(242, 240, 239));
}

int main(int argc, char **argv) {
  Fl_PNG_Image icon("assets/pfp.png");
  Window window(appWidth, appHeight, "Simple Inventory");
  Fl_Scroll sc(panelWidth, 0, appWidth - panelWidth, appHeight);

  appSetting(&window);

  sc.type(Fl_Scroll::VERTICAL);
  sc.scrollbar.color(sc.color());

  Fl_Pack pack(panelWidth + 12, 0, divWidth, appHeight);
  pack.spacing(16);

  DB db("DB test.db");
  EntriesMediator med(&db);
  Director dir(&pack, &med);

  fetchFromDB(&db, &dir);
  dir.constructAddBtn();

  window.icon(&icon);

  pack.end();
  sc.end();

  dir.constructSidePanel();
  window.end();
  window.show(argc, argv);

  return Fl::run();
}