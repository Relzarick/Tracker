#include "helpers.h"
#include "builders.h"
#include "data.h"

#include <FL/Fl.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>

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
  // Fl_Multiline_Input *multiInput = new Fl_Multiline_Input(100, 400, 500, 80);

  // multiInput->callback([](Fl_Widget *w, void *data) {
  //   auto *input = static_cast<Fl_Multiline_Input *>(w);
  // });

  // make background all invsis
  // remove the cursor line when typing
  // auto adjust acording to text? (set min width)
}