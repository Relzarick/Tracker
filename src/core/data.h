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
  rect pos;
};

struct usrInput {
  const char *name;
  double price;
  int qty;
  const char *description;
};

struct dbOutput {
  int id;
  int qty;
  double price;
  std::string name;
  std::string description;
};

struct entryWidgetData {
  int id;
  Fl_Box *name;
  Fl_Box *price;
  Fl_Box *qty;
  Fl_Box *desc;
  Fl_Group *group;
};