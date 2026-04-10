#pragma once

#include <string>
#include <optional>
#include <chrono>
// #include <

using std::string;
using namespace std::chrono;

struct advanceInfo
{
  std::optional<year_month_day> purchase;
  std::optional<year_month_day> expiry;
};

struct product
{
  string name;
  std::optional<string> description;
  int qty;
  double price;
  std::optional<advanceInfo> adv;
};