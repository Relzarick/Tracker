#pragma once

#include "data.h"
#include <functional>

void start();
void printP(const product &p); // for testing

class IBuilder
{
public:
  virtual void setText(int x, int y, int width, int height, std::string text) = 0;
  virtual void setBG(std::optional<background> bg) = 0;
  virtual ~IBuilder() = default; // what this do
};

class GroupBuilder : public IBuilder
{
public:
  GroupBuilder(int x, int y, int width, int height);
  void setText(int x, int y, int width, int height, std::string text) override;
  void setBG(std::optional<background> bg) override;

private:
  int baseX;
  int baseY;
  Fl_Group *group = nullptr;
  std::string storedLabel;
};