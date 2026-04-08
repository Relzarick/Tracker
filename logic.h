#pragma once

#include <string>
#include <optional>

using std::string;
void start();
void prompt();
void render();

struct product
{
  string name;
  string description;
  int qty;
  double price;
  std::optional<advanceInfo> adv;
};

struct advanceInfo
{
  string supplier;
  // add dates?
};
