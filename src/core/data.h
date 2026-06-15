#pragma once

#include <string>

struct usrInput {
  const char *name = "";
  double price = 0;
  int qty = 0;
  const char *description = "";
};

struct dbOutput {
  int id;
  int qty;
  double price;
  std::string name;
  std::string description;
};