#pragma once

#include "input_mediator.h"

#include <FL/Fl_Pack.H>
#include <Fl/Fl_Button.H>

class Director {
public:
  Director(Fl_Pack *, InputMediator *);

  void constructEntry();
  void constructEntry(dbOutput);
  void constructInput();
  void constructAddBtn();
  void constructDeleteBtn();

private:
  Fl_Pack *pack = nullptr;
  InputMediator *med = nullptr;

  void handleInputCB(entryWidgetData);
};