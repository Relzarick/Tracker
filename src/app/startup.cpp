#include "data.h"
#include "database.h"
#include "director.h"

#include <FL/Fl.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>

#include <vector>

void fetchFromDB(DB *db, Director *dir) {
  std::vector<dbOutput> dbList = db->fetchAll();

  if (dbList.size() == 0)
    return;

  for (const auto &entry : dbList)
    dir->constructEntry(entry);
}