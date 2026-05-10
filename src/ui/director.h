#pragma once

#include "builders.h"
#include "iBuilder.h"

struct Layout {
  rect header;
  rect price;
  rect qty;
  rect description;
};

class Director {
public:
  void constructEntry(TextBuilder &builder);

private:
  IBuilder *builder = nullptr;
  Layout entryLayout{.header = {.x = 10, .y = 10},
                     .price = {.x = 10, .y = 35},
                     .qty = {.x = 180, .y = 10},
                     .description = {.x = 10, .y = 100}};
};