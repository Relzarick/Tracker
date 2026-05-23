#include "helpers.h"
#include "builders.h"
#include "data.h"

#include <FL/Fl.H>
#include <FL/Fl_Input.H>

#include <vector>

void fetchFromDB(DB *db, Director *dir) {
  std::vector<dbOutput> dbList = db->fetchAll();

  if (dbList.size() == 0)
    return;

  for (const auto &entry : dbList) {
    TextBuilder builder(rect{.w = 660, .h = 250});
    dir->constructEntry(builder, entry);
  }
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