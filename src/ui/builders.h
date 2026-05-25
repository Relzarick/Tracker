#pragma once

#include "data.h"
#include "iBuilder.h"

#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>

#include <FL/Fl_Input.H>
#include <optional>

class TextBuilder : public IBuilder {
public:
  TextBuilder(const rect &groupRect);
  Fl_Group *getGroup() override;

  void setBG(const std::optional<background> &bg) override;
  Fl_Box *setText(const char *label, const layout &settings);

private:
  rect base;
  rect textPos;
  Fl_Group *group = nullptr;
};

class BtnBuilder : public IBuilder {
public:
  BtnBuilder(const rect &groupRect);
  Fl_Group *getGroup() override;
  Fl_Button *setBtn();

  void setBG(const std::optional<background> &bg) override;

private:
  rect base;
  Fl_Group *group = nullptr;
};

class InputBuilder : public IBuilder {
public:
  InputBuilder(const rect &groupRect);
  Fl_Group *getGroup() override;
  Fl_Input *setInput(const layout &settings);

  void setBG(const std::optional<background> &bg) override;

private:
  rect base;
  Fl_Group *group = nullptr;
};