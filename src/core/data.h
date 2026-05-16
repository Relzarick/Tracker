#pragma once

#include <FL/Fl_Box.H>

#include <chrono>
#include <optional>
#include <string>

using namespace std::chrono;

struct advanceInfo {
  std::optional<year_month_day> purchase;
  std::optional<year_month_day> expiry;
};

struct product {
  std::string name;
  std::optional<std::string> description;
  int qty;
  double price;
  double total_costs;
  std::optional<advanceInfo> adv;
};

struct background {
  Fl_Color bg_color = FL_WHITE;
  Fl_Boxtype box_type = FL_ROUNDED_BOX;
};

struct rect {
  int x = 0;
  int y = 0;
  int w = 0;
  int h = 0;
};

struct layout {
  const char *tooltip;
  bool wrap = false;
  int fontSize = 22;
  Fl_Font font = FL_COURIER;
  rect pos;
};