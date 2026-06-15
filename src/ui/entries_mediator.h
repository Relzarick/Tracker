#pragma once

#include "database.h"
#include "ui_types.h"

#include "FL/Fl_Group.H"

#include <vector>

class EntriesMediator {
public:
  EntriesMediator(DB *);

  void updateDBField(Fl_Input *);

  void setEntryToList(widgetsData &);
  void removeEntryFromList(int);

  int returnLastEntry();
  Fl_Group *returnGroupPointer(int);

  int insertBlankEntry();

private:
  DB *db = nullptr;
  std::vector<widgetsData> entryList;

  widgetsData *retrieveEntry(Fl_Input *);
  void removeDBField(int);
};