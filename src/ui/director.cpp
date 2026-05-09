#include "director.h"
#include "builders.h"
#include "data.h"

void Director::constructText(TextBuilder &builder) {
  background bg;
  builder.setBG(bg);

  builder.setText(rect{.x = -200, .y = -100}, "Product name");
  builder.setText(rect{.x = -200, .y = -90}, "290");
  builder.setText(rect{.x = -180, .y = -100}, "$424.20");

  builder.setText(
      rect{.x = 0, .y = 0},
      "Description Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
      "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");

  // size should be standard
  // create a way to track all text locations
};