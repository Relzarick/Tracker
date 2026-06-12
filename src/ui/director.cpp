#include "director.h"
#include "builders.h"
#include "input_mediator.h"
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

Director::Director(Fl_Pack *pack, InputMediator *med) {
  this->pack = pack;
  this->med = med;
}

void Director::constructEntry(dbOutput data) {
  rect rect{.w = divWidth, .h = divHeight};

  TextBuilder textBuilder(rect);
  textBuilder.getGroup()->begin();
  textBuilder.setBG(background{});

  InputBuilder inputBuilder(rect);

  std::string priceStr = std::format("{:.2f}", data.price);
  std::string qtyStr = std::format("{}", data.qty);

  entryWidgetData widget{};

  widget.id = data.id;
  textBuilder.setText("$ ", priceSymbol);
  textBuilder.setText("QTY: ", qtySymbol);

  widget.name = inputBuilder.setInput(header);
  widget.name->value(data.name.c_str());

  widget.price = inputBuilder.setInput(price);
  widget.price->value(priceStr.c_str());

  widget.qty = inputBuilder.setInput(qty);
  widget.qty->value(qtyStr.c_str());

  widget.desc = inputBuilder.SetMultilineInput(desc);
  widget.desc->value(data.description.c_str());

  widget.group = textBuilder.getGroup();

  med->setEntryToList(widget);

  textBuilder.getGroup()->end();
  pack->add(textBuilder.getGroup());

  handleInputCB(widget);
};

void Director::constructEntry() {
  rect rect{.w = divWidth, .h = divHeight};

  TextBuilder textBuilder(rect);
  textBuilder.getGroup()->begin();
  textBuilder.setBG(background{});

  InputBuilder inputBuilder(rect);

  std::string priceStr = std::format("{:.2f}", 0.0);
  std::string qtyStr = std::format("{}", 0);

  entryWidgetData widget{};

  widget.id = med->insertBlankEntry();
  textBuilder.setText("$ ", priceSymbol);
  textBuilder.setText("QTY: ", qtySymbol);

  widget.name = inputBuilder.setInput(header);
  widget.name->value("Enter a name");

  widget.price = inputBuilder.setInput(price);
  widget.price->value(priceStr.c_str());

  widget.qty = inputBuilder.setInput(qty);
  widget.qty->value(qtyStr.c_str());

  widget.desc = inputBuilder.SetMultilineInput(desc);
  widget.desc->value("Enter your description");

  widget.group = textBuilder.getGroup();

  med->setEntryToList(widget);

  textBuilder.getGroup()->end();
  pack->add(textBuilder.getGroup());

  handleInputCB(widget);
}

void Director::constructAddBtn() {
  BtnBuilder builder(rect{.w = divWidth, .h = 95});
  builder.getGroup()->begin();

  Fl_Button *btn = builder.setBtn();
  addBtnData *btnData = new addBtnData{this, btn};

  btn->callback(
      [](Fl_Widget *w, void *data) {
        auto *bd = static_cast<addBtnData *>(data);

        bd->dir->constructEntry();
        bd->dir->pack->insert(*bd->btn->parent(), bd->dir->pack->children());

        w->window()->redraw();
      },
      btnData);

  builder.getGroup()->end();
}

// td tbd what to do
void Director::constructInput() {
  InputBuilder builder(rect{.w = divWidth, .h = divHeight});
  builder.getGroup()->begin();
  builder.setBG(background{});

  layout settings = {.pos = {200, 100, 200, 40}};
  Fl_Input *input = builder.setInput(settings);

  input->callback(
      [](Fl_Widget *w, void *data) {
        auto input = static_cast<Fl_Input *>(w);
        auto med = static_cast<InputMediator *>(data);

        med->updateDBField(input);
      },
      med);

  builder.getGroup()->end();
  pack->add(builder.getGroup());
}

void Director::handleInputCB(entryWidgetData widget) {
  auto handler = [](Fl_Widget *w, void *data) {
    static_cast<InputMediator *>(data)->updateDBField(
        static_cast<Fl_Input *>(w));
  };

  widget.name->callback(handler, med);
  widget.price->callback(handler, med);
  widget.qty->callback(handler, med);
  widget.desc->callback(handler, med);
}