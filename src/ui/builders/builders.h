#pragma once

#include "iBuilder.h"
#include "widgets/ui_types.h"

#include <FL/Fl_Button.H>

#include <optional>

class TextBuilder : public IBuilder {
public:
  TextBuilder(const rect &);
  Fl_Group *getGroup() override;

  void setBG(const std::optional<background> &) override;
  Fl_Box *setText(const char *, const layout &);

private:
  rect base;
  rect textPos;
  Fl_Group *group = nullptr;
};

class BtnBuilder : public IBuilder {
public:
  BtnBuilder(const rect &);
  Fl_Group *getGroup() override;
  Fl_Button *setBtn(int);

  void setBG(const std::optional<background> &) override;

private:
  rect base;
  Fl_Group *group = nullptr;
};

class InputBuilder : public IBuilder {
public:
  InputBuilder(const rect &);
  Fl_Group *getGroup() override;
  Fl_Input *setInput(const layout &);
  Fl_Input *SetMultilineInput(const layout &);

  void setBG(const std::optional<background> &) override;

private:
  rect base;
  Fl_Group *group = nullptr;
};