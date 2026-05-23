#pragma once

#include "builders.h"
#include "data.h"
#include "database.h"

#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Pack.H>
#include <Fl/Fl_Button.H>
#include <vector>

class Director {
public:
  Director(Fl_Pack *pack, DB *db);

  void constructEntry(TextBuilder &builder, dbOutput data);
  void constructEntry(TextBuilder &builder);

  void constructAddBtn(BtnBuilder &builder);
  void setEntryList(entryWidgetData data);

  int getEntryId();

private:
  Fl_Pack *pack = nullptr;
  DB *db = nullptr;

  std::vector<entryWidgetData> entryList;
};

struct addBtnData {
  Director *dir;
  Fl_Button *btn;
};
