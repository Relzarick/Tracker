#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Box.H>

#include <string>
#include <optional>
#include <chrono>

using namespace std::chrono;

struct advanceInfo
{
  std::optional<year_month_day> purchase;
  std::optional<year_month_day> expiry;
};

struct product
{
  std::string name;
  std::optional<std::string> description;
  int qty;
  double price;
  std::optional<advanceInfo> adv;
};

struct background
{
  Fl_Color bg_color = FL_DARK3;
  Fl_Boxtype box_type = FL_FLAT_BOX;
};

struct contianerDimensions
{
  int h = 200;
  int w;
};

struct inputDimensions
{
  int h;
  int w;
};

struct imageDimensions
{
  int h;
  int w;
};