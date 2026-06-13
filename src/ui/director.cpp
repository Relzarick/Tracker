#include "director.h"
#include "builders.h"
#include "input_mediator.h"
#include "styles.h"
#include "ui_types.h"

#include <format>

#include <FL/Fl_PNG_Image.H>
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

  constructDeleteBtn();

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

  constructDeleteBtn();

  med->setEntryToList(widget);

  textBuilder.getGroup()->end();
  pack->add(textBuilder.getGroup());

  handleInputCB(widget);
}

void Director::constructAddBtn() {
  BtnBuilder builder(rect{.w = divWidth, .h = 95});
  builder.getGroup()->begin();

  Fl_Button *btn = builder.setBtn();

  btn->callback(
      [](Fl_Widget *w, void *data) {
        auto *dir = static_cast<Director *>(data);

        dir->constructEntry();
        dir->pack->insert(*w->parent(), dir->pack->children());

        w->window()->redraw();
      },
      this);

  builder.getGroup()->end();
}

void Director::constructDeleteBtn() {
  rect rect{.x = 600, .y = 15, .w = 30, .h = 40};
  background bg{.box_type = FL_NO_BOX};

  BtnBuilder builder(rect);
  builder.getGroup()->begin();

  Fl_Button *btn = builder.setBtn();
  Fl_PNG_Image *icon = new Fl_PNG_Image("assets/delete.png");

  btn->image(icon);
  btn->box(bg.box_type);
  btn->down_box(bg.box_type);
  btn->down_color(bg.bg_color);

  btn->callback(
      [](Fl_Widget *w, void *data) {
        auto *dir = static_cast<Director *>(data);

        //. make delete entry

        w->window()->redraw();
      },
      this);

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