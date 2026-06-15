#include "director.h"
#include "Entries_mediator.h"
#include "builders.h"
#include "styles.h"
#include "ui_types.h"

#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Window.H>

#include <format>

Director::Director(Fl_Pack *pack, EntriesMediator *med) {
  this->pack = pack;
  this->med = med;
}

void Director::constructEntry(dbOutput data) {
  TextBuilder textBuilder(entryRect);
  textBuilder.getGroup()->begin();
  textBuilder.setBG(background{});

  InputBuilder inputBuilder(entryRect);

  std::string priceStr = std::format("{:.2f}", data.price);
  std::string qtyStr = std::format("{}", data.qty);

  widgetsData widget{};

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
  constructDeleteBtn(med->returnLastEntry());

  textBuilder.getGroup()->end();
  pack->add(textBuilder.getGroup());

  handleInputCB(widget);
};

void Director::constructEntry() {
  TextBuilder textBuilder(entryRect);
  textBuilder.getGroup()->begin();
  textBuilder.setBG(background{});

  InputBuilder inputBuilder(entryRect);

  std::string priceStr = std::format("{:.2f}", 0.0);
  std::string qtyStr = std::format("{}", 0);

  widgetsData widget{};

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
  constructDeleteBtn(med->returnLastEntry());

  textBuilder.getGroup()->end();
  pack->add(textBuilder.getGroup());

  handleInputCB(widget);
}

void Director::constructAddBtn() {
  BtnBuilder builder(rect{.w = divWidth, .h = 95 + 12});
  builder.getGroup()->begin();

  Fl_Button *btn = builder.setBtn(95);
  new Fl_Box(0, 0, divWidth, 12);

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

void Director::constructDeleteBtn(int widgetID) {
  rect rect{.x = 600, .y = 15, .w = 30, .h = 40};
  background bg{.box_type = FL_NO_BOX};

  BtnBuilder builder(rect);
  builder.getGroup()->begin();

  Fl_Button *btn = builder.setBtn(rect.h);
  Fl_PNG_Image *icon = new Fl_PNG_Image("assets/delete.png");
  deleteData *cbData = new deleteData{.med = med, .entryId = widgetID};

  btn->image(icon);
  btn->box(bg.box_type);
  btn->down_box(bg.box_type);
  btn->down_color(bg.bg_color);

  btn->callback(
      [](Fl_Widget *w, void *data) {
        auto dataStruct = static_cast<deleteData *>(data);
        int id = dataStruct->entryId;

        Fl_Group *g = dataStruct->med->returnGroupPointer(id);
        dataStruct->med->removeEntryFromList(id);

        Fl::delete_widget(g);
        w->window()->redraw();
      },
      cbData);

  builder.getGroup()->end();
}

// td tbd on what to do
void Director::constructInput() {
  InputBuilder builder(entryRect);
  builder.getGroup()->begin();
  builder.setBG(background{});

  layout settings = {.pos = {200, 100, 200, 40}};
  Fl_Input *input = builder.setInput(settings);

  input->callback(
      [](Fl_Widget *w, void *data) {
        auto input = static_cast<Fl_Input *>(w);
        auto med = static_cast<EntriesMediator *>(data);

        med->updateDBField(input);
      },
      med);

  builder.getGroup()->end();
  pack->add(builder.getGroup());
}

void Director::handleInputCB(widgetsData &widget) {
  auto handler = [](Fl_Widget *w, void *data) {
    static_cast<EntriesMediator *>(data)->updateDBField(
        static_cast<Fl_Input *>(w));
  };

  widget.name->callback(handler, med);
  widget.price->callback(handler, med);
  widget.qty->callback(handler, med);
  widget.desc->callback(handler, med);
}