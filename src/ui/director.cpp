#include "director.h"
#include "builders.h"
#include "data.h"
#include "database.h"

#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Window.H>

Director::Director(Fl_Pack *pack, DB *db) {
  this->pack = pack;
  this->db = db;
}

void Director::constructEntry(TextBuilder &builder, dbOutput data) {
  builder.getGroup()->begin();
  builder.setBG(background{});

  entryWidgetData widget{};

  layout header{.tooltip = "Entry name", .pos = {.x = 10, .y = 10}};
  layout price{.tooltip = "purchased price", .pos = {.x = 10, .y = 40}};
  layout qty{.tooltip = "Quantity remaining", .pos = {.x = 180, .y = 10}};
  layout desc{.tooltip = "Description of the entry",
              .wrap = true,
              .pos = {.x = 10, .y = 100}};

  std::string priceStr = std::format("${:.2f}", data.price);
  std::string qtyStr = std::format("QTY: {}", data.qty);

  widget.name = builder.setText(data.name.c_str(), header);
  widget.price = builder.setText(priceStr.c_str(), price);
  widget.qty = builder.setText(qtyStr.c_str(), qty);
  widget.desc = builder.setText(data.description.c_str(), desc);
  widget.group = builder.getGroup();

  setEntryList(widget);

  builder.getGroup()->end();
  pack->add(builder.getGroup());
};

void Director::constructEntry(TextBuilder &builder) {
  builder.getGroup()->begin();
  builder.setBG(background{});

  entryWidgetData widget{};

  layout header{.tooltip = "Entry name", .pos = {.x = 10, .y = 10}};
  layout price{.tooltip = "purchased price", .pos = {.x = 10, .y = 40}};
  layout qty{.tooltip = "Quantity remaining", .pos = {.x = 180, .y = 10}};
  layout desc{.tooltip = "Description of the entry",
              .wrap = true,
              .pos = {.x = 10, .y = 100}};

  widget.name = builder.setText("", header);
  widget.price = builder.setText("", price);
  widget.qty = builder.setText("", qty);
  widget.desc = builder.setText("", desc);
  widget.group = builder.getGroup();

  setEntryList(widget);

  builder.getGroup()->end();
  pack->add(builder.getGroup());
}

void Director::constructAddBtn(BtnBuilder &builder) {
  builder.getGroup()->begin();

  Fl_Button *btn = builder.setBtn();
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

void Director::constructInput(InputBuilder &builder) {
  builder.getGroup()->begin();
  builder.setBG(background{});

  layout settings = {.pos = {.x = 200, .y = 100, .w = 200, .h = 40}};
  //. tbd the sizing
  //* After clicking off this to also unfocus

  Fl_Input *input = builder.setInput(settings);

  Fl_Input *input1 =
      builder.setInput({.pos = {.x = 200, .y = 200, .w = 200, .h = 40}});

  input->callback([](Fl_Widget *w, void *data) {
    auto *input = static_cast<Fl_Input *>(w);
  });

  builder.getGroup()->end();
  pack->add(builder.getGroup());
}

int Director::getEntryId() {
  // this should return xx + 1

  return 1;
};

void Director::setEntryList(entryWidgetData data) {
  entryList.push_back(data);
};