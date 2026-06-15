#pragma once

#include "database.h"
#include "ui_types.h"

#include <FL/Fl_Input.H>
#include <vector>

class InputMediator {
public:
  InputMediator(DB *db);

  void updateDBField(Fl_Input *field);
  void setEntryToList(widgetsData entry);
  int insertBlankEntry();

  DB *getDB();

private:
  DB *db = nullptr;
  std::vector<widgetsData> entryList;

  int retrieveEntryId(Fl_Input *pointer);
};