#pragma once

#include "builders.h"
#include "iBuilder.h"

#include <FL/Fl_Pack.H>
#include <FL/Fl_Scroll.H>

class Director {
public:
  Director(Fl_Pack *pack, Fl_Scroll *scroll);
  void constructEntry(TextBuilder &builder);
  void constructAddBtn(BtnBuilder &builder);

private:
  IBuilder *builder = nullptr;
  Fl_Pack *pack = nullptr;
  Fl_Scroll *scroll = nullptr;
};