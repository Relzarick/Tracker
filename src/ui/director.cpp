#include "director.h"
#include "builders.h"
#include "data.h"

#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Window.H>

Director::Director(Fl_Pack *pack) { this->pack = pack; }

void Director::constructEntry(TextBuilder &builder) {
  builder.getGroup()->begin();
  builder.setBG(background{});

  layout header{.tooltip = "Entry name", .pos = {.x = 10, .y = 10}};
  layout price{.tooltip = "purchased price", .pos = {.x = 10, .y = 40}};
  layout qty{.tooltip = "Quantity remaining", .pos = {.x = 180, .y = 10}};
  layout desc{.tooltip = "Description of the entry",
              .wrap = true,
              .pos = {.x = 10, .y = 100}};

  builder.setText("Product name", header);
  builder.setText("$424.20", price);
  builder.setText("QTY: 290", qty);
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

  builder.getGroup()->end();
  pack->add(builder.getGroup());
};

void Director::constructAddBtn(BtnBuilder &builder) {
  builder.getGroup()->begin();
  builder.setBtn(layout{});

  Fl_Button *btn = builder.getBtn();
  addBtnData *data = new addBtnData{this, btn};

  btn->callback(
      [](Fl_Widget *w, void *data) {
        auto *d = static_cast<addBtnData *>(data);

        TextBuilder builder(rect{.w = 660, .h = 250});
        d->dir->constructEntry(builder);
        d->dir->pack->insert(*d->btn->parent(), d->dir->pack->children());

        w->window()->redraw();
      },
      data);

  builder.getGroup()->end();
}