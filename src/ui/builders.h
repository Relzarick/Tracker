#pragma once

#include "data.h"
#include "iBuilder.h"

#include <FL/Fl.H>
#include <FL/Fl_Group.H>

#include <FL/Fl_Input.H>
#include <optional>
#include <string>

class TextBuilder : public IBuilder {
public:
  TextBuilder(rect pos);
  Fl_Group *getGroup() override;

  void setBG(const std::optional<background> &bg) override;
  void setText(rect offset, const char *label);

private:
  rect base;
  rect textPos;
  Fl_Group *group = nullptr;
  std::string storedLabel;

  void determinePos(int &tw, int &th, const char *label);
};

class BtnBuilder : public IBuilder {
public:
  BtnBuilder(rect size);
  Fl_Group *getGroup() override;

  void setBG(const std::optional<background> &bg) override;
  void setBtn(rect size);

private:
  rect base;
  Fl_Group *group = nullptr;
};

class InputBuilder : public IBuilder {
public:
  InputBuilder(rect size);
  Fl_Group *getGroup() override;

  void setBG(const std::optional<background> &bg) override;
  Fl_Input *getInput();

private:
  rect base;
  Fl_Group *group = nullptr;
  Fl_Input *input = nullptr;
};