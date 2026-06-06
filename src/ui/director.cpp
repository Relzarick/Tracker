#include "director.h"
#include "builders.h"
#include "database.h"
#include "styles.h"
#include "ui_types.h"

#include <format>

#include <FL/Enumerations.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>

Director::Director(Fl_Pack *pack, DB *db) {
  this->pack = pack;
  this->db = db;
}

void Director::constructEntry(dbOutput data) {
  rect rect{.w = divWidth, .h = divHeight};

  TextBuilder textBuilder(rect);
  textBuilder.getGroup()->begin();
  textBuilder.setBG(background{});

  InputBuilder inputBuilder(rect);

  std::string priceStr = std::format("{:.2f}", data.price);
  std::string qtyStr = std::format("{}", data.qty);

  layout header{.tooltip = "Entry name", .pos = {20, 10, 170, textHeight}};

  layout desc{.tooltip = "Description of the entry",
              .pos = {20, 100, 600, textHeight}};

  layout priceSymbol{.pos = {20, 66, 80, textHeight}};
  layout price{.tooltip = "purchased price", .pos = {40, 60, 100, textHeight}};

  layout qtySymbol{.pos = {200, 16, 100, textHeight}};
  layout qty{.tooltip = "Quantity remaining", .pos = {255, 10, 80, textHeight}};

  // td make these inline ^

  entryWidgetData widget{};

  widget.id = entryList.size(); // assigns id by size need review
  textBuilder.setText("$ ", priceSymbol);
  textBuilder.setText("QTY: ", qtySymbol);

  widget.name = inputBuilder.setInput(header);
  widget.name->value(data.name.c_str());

  widget.price = inputBuilder.setInput(price);
  widget.price->value(priceStr.c_str());

  widget.qty = inputBuilder.setInput(qty);
  widget.qty->value(qtyStr.c_str());

  widget.desc = inputBuilder.setInput(desc);
  widget.desc->value(data.description.c_str());

  widget.group = textBuilder.getGroup();

  setEntryList(widget);

  textBuilder.getGroup()->end();
  pack->add(textBuilder.getGroup());

  widget.name->callback(
      [](Fl_Widget *w, void *data) {
        auto input = static_cast<Fl_Input *>(w);
        auto dir = static_cast<Director *>(data);

        usrInput test{input->value(), 1.2, 333, "Its a pear"};

        dir->db->update(dir->getEntryId(), test);

        //. New class observer monster
        // It will own the entrylist
        // then it will sub to all input events? (somehow)
        // each entry update will ping the observer monster
        // observer monster would then know about its id (somehow)
        // can just use .value and build the usrInput struct for DB
      },
      this);
};

void Director::constructEntry() {
  TextBuilder builder(rect{.w = divWidth, .h = divHeight});
  builder.getGroup()->begin();
  builder.setBG(background{});

  layout header{.tooltip = "Entry name", .pos = {.x = 10, .y = 10}};
  layout price{.tooltip = "purchased price", .pos = {.x = 10, .y = 40}};
  layout qty{.tooltip = "Quantity remaining", .pos = {.x = 180, .y = 10}};
  layout desc{.tooltip = "Description of the entry",
              .pos = {.x = 10, .y = 100}};

  // widget.name = builder.setText("", header);
  // widget.price = builder.setText("", price);
  // widget.qty = builder.setText("", qty);
  // widget.desc = builder.setText("", desc);
  entryWidgetData widget{};

  widget.group = builder.getGroup();
  setEntryList(widget);

  builder.getGroup()->end();
  pack->add(builder.getGroup());
}

void Director::constructAddBtn() {
  BtnBuilder builder(rect{.w = divWidth, .h = 95});
  builder.getGroup()->begin();

  Fl_Button *btn = builder.setBtn();
  addBtnData *btnData = new addBtnData{this, btn};

  btn->callback(
      [](Fl_Widget *w, void *data) {
        auto *bd = static_cast<addBtnData *>(data);

        // bd->dir->constructEntry();
        // bd->dir->pack->insert(*bd->btn->parent(), bd->dir->pack->children());

        for (const auto &entry : bd->dir->entryList) {
          printf("%d: %s\n", entry.id, entry.name->value());
          printf("Description: %s\n\n", entry.desc->value());
        }

        w->window()->redraw();
      },
      btnData);

  builder.getGroup()->end();
}

void Director::constructInput() {
  InputBuilder builder(rect{.w = divWidth, .h = divHeight});
  builder.getGroup()->begin();
  builder.setBG(background{});

  layout settings = {.pos = {200, 100, 200, 40}};
  Fl_Input *input = builder.setInput(settings);

  input->callback(
      [](Fl_Widget *w, void *data) {
        auto input = static_cast<Fl_Input *>(w);
        auto dir = static_cast<Director *>(data);

        usrInput test{"pear", 1.2, 333, "Its a pear"};
        // * get user input

        dir->db->update(dir->getEntryId(), test);

        // now have to refresh list
        // update the entry list

        //. make a render all
        //. update list entry to take optional index
        //. construct input needs to know index of the input
      },
      this);

  builder.getGroup()->end();
  pack->add(builder.getGroup());
}

int Director::getEntryId() {
  // revisit after refactor

  return 1;
};

void Director::setEntryList(entryWidgetData data) {
  entryList.push_back(data);
};