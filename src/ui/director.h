#pragma once

#include "input_mediator.h"

#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Pack.H>
#include <Fl/Fl_Button.H>

class Director {
public:
  Director(Fl_Pack *pack, InputMediator *med);

  void constructEntry(dbOutput data);
  void constructEntry();
  void constructAddBtn();
  void constructInput();

private:
  Fl_Pack *pack = nullptr;
  InputMediator *med = nullptr;

  void handleInputCB(entryWidgetData widget);
};

struct addBtnData {
  Director *dir;
  Fl_Button *btn;
};
