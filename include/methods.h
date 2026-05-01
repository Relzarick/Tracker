#pragma once

#include "data.h"

void start();
void printP(const product &p); // for testing

class IBuilder
{
public:
  virtual void setText(int x, int y, int width, int height, const char *label) = 0;
  virtual void setBG(std::optional<background> bg) = 0;
  virtual ~IBuilder() = default;
};

class TextBuilder : public IBuilder
{
public:
  TextBuilder(int x, int y, int width, int height);
  void setText(int x, int y, int width, int height, const char *label) override;
  void setBG(std::optional<background> bg) override;
  void setBtn();

private:
  int baseX;
  int baseY;
  Fl_Group *group = nullptr;
  std::string storedLabel;
};