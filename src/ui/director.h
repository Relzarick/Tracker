#pragma once

#include "builders.h"

#include <FL/Fl_Pack.H>
#include <Fl/Fl_Button.H>

class Director {
public:
  Director(Fl_Pack *pack);
  void constructEntry(TextBuilder &builder);
  void constructAddBtn(BtnBuilder &builder);

private:
  Fl_Pack *pack = nullptr;
};

struct addBtnData {
  Director *dir;
  Fl_Button *btn;
};