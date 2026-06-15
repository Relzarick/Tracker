#pragma once

#include "Entries_mediator.h"

#include <FL/Fl_Button.H>
#include <FL/Fl_Pack.H>

class Director {
public:
  Director(Fl_Pack *, EntriesMediator *);

  void constructEntry();
  void constructEntry(dbOutput);
  void constructInput();
  void constructAddBtn();

private:
  Fl_Pack *pack = nullptr;
  EntriesMediator *med = nullptr;

  void constructDeleteBtn(int);
  void handleInputCB(widgetsData &);
};

struct deleteData {
  EntriesMediator *med = nullptr;
  int entryId;
};