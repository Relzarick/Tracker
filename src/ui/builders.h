#pragma once

#include "data.h"
#include "iBuilder.h"

#include <FL/Fl.H>
#include <FL/Fl_Group.H>

#include <optional>
#include <string>

class TextBuilder : public IBuilder {
public:
  TextBuilder(int x, int y, int w, int h);
  Fl_Group *getGroup() override;

  void setText(int x, int y, int w, int h, const char *label);
  void setBG(const std::optional<background> &bg) override;

private:
  int baseX;
  int baseY;

  Fl_Group *group = nullptr;
  std::string storedLabel;
};

class BtnBuilder : public IBuilder {
public:
private:
};

class InputBuilder : public IBuilder {
public:
private:
};