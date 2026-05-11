#include "director.h"
#include "builders.h"
#include "data.h"
#include <FL/Enumerations.H>

void Director::constructEntry(TextBuilder &builder) {
  background bg;
  builder.setBG(bg);

  layout header{.tooltip = "Entry name", .pos = {.x = 10, .y = 10}};
  layout price{.tooltip = "purchased price", .pos = {.x = 10, .y = 40}};
  layout qty{.tooltip = "Quantity remaining", .pos = {.x = 180, .y = 10}};
  layout desc{.tooltip = "Description of the entry",
              .wrap = true,
              .pos = {.x = 10, .y = 100}};

  builder.setText("Product name", header);
  builder.setText("$424.20", price);
  builder.setText("QTY: 290", qty);

  builder.setText(
      "Description Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
      "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
      desc);
};