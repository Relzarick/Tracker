#include "data.h"
#include "database.h"
#include "director.h"
#include "startup.h"

#include "widgets/custom_widgets.h"
#include "widgets/styles.h"

#include <FL/Enumerations.H>
#include <FL/Fl.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Tooltip.H>
#include <FL/Fl_Window.H>

void addEntry(DB *db) {
  usrInput data{"apple", 0.6, 6,
                "Its an apple asdfasdf as asdjfhasld kfha sldjf hasldk "};

  db->insert(data);
}

void appSetting(Window *win) {
  Fl::focus(win);
  Fl::visible_focus(0);

  Fl_Tooltip::color(fl_rgb_color(242, 240, 239));
}

int main(int argc, char **argv) {
  int width = 700;
  int height = 750;
  int x = 15;

  Window window(width, height, "Tracker");
  Fl_Scroll sc(0, 0, width, height);

  appSetting(&window);

  sc.type(Fl_Scroll::VERTICAL);
  sc.scrollbar.color(sc.color());

  Fl_Pack pack(x, 0, divWidth, height);
  pack.spacing(16);

  DB db("DB test.db");
  Director dir = Director(&pack, &db);

  // addEntry(&db);
  fetchFromDB(&db, &dir);

  dir.constructAddBtn();
  // dir.constructInput();

  pack.end();
  sc.end();
  window.end();
  window.show(argc, argv);

  return Fl::run();
}