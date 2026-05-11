#include "builders.h"
#include "data.h"
#include "methods.h"

#include <FL/Fl.H>
#include <FL/Fl_Input.H>

#include <print>

using std::print;

void insertTest() {
  // testPrint();
  createInput();
  createDB();
}

void testPrint() {
  product test;
  test.name = "apple";
  test.description = "testing";
  test.price = 22.0;
  test.qty = 22;

  test.adv = advanceInfo{year_month_day{year{2020}, month{9}, day{29}},
                         year_month_day{year{2022}, month{3}, day{19}}};

  print("Tracker APP\n");
  printP(test);
}

void printP(const product &p) {
  print("[{}] {} | qty: {} | ${:.2f}", p.name, *p.description, p.qty, p.price);

  if (p.adv) {
    if (p.adv->purchase)
      std::print(" | purchased: {}", *p.adv->purchase);
    if (p.adv->expiry)
      std::print(" | expires: {}", *p.adv->expiry);
  }

  print("\n");
}

void createInput() {
  rect size{500, 450, 100, 100};
  TextBuilder *title = new TextBuilder(size);
  background bg;
  title->setBG(bg);

  Fl_Input *input = new Fl_Input(170, 350, 100, 40, "label");
  input->when(FL_WHEN_ENTER_KEY);

  static std::string stored; // dont want this

  input->callback(
      [](Fl_Widget *w, void *data) {
        Fl_Input *input = (Fl_Input *)w;
        TextBuilder *title = (TextBuilder *)data;

        stored = input->value();

        rect r{.w = 100, .h = 100};

        // title->setText(r, stored.c_str());
        title->getGroup()->redraw();
      },
      title);
}