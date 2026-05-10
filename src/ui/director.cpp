#include "director.h"
#include "builders.h"
#include "data.h"

void Director::constructEntry(TextBuilder &builder) {
  background bg;
  builder.setBG(bg);

  builder.setText(entryLayout.header, "Product name");
  builder.setText(entryLayout.price, "$424.20");
  builder.setText(entryLayout.qty, "QTY: 290");

  builder.setText(
      entryLayout.description,
      "Description Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
      "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");

  // size should be standard
  // create a way to track all text locations
};