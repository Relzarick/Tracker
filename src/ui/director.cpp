#include "director.h"
#include "builders.h"
#include "data.h"
#include <FL/Enumerations.H>

void Director::constructEntry(TextBuilder &builder) {
  background bg;
  builder.setBG(bg);

  xx header{.tooltip = "Entry name"};
  xx price{.tooltip = "purchased price"};
  xx qty{.tooltip = "Quantity remaining"};
  xx desc{.tooltip = "Description of the entry", .wrap = true};

  builder.setText(entryLayout.header, "Product name", header);
  builder.setText(entryLayout.price, "$424.20", price);
  builder.setText(entryLayout.qty, "QTY: 290", qty);

  builder.setText(
      entryLayout.description,
      "Description Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
      "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
      desc);
};