#include "director.h"
#include "Entries_mediator.h"
#include "FL/Enumerations.H"
#include "FL/Fl_Box.H"
#include "FL/Fl_Group.H"
#include "FL/Fl_Pack.H"
#include "builders.h"
#include "styles.h"
#include "ui_types.h"
#include "url.h"

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

  Fl_PNG_Image *icon = new Fl_PNG_Image("assets/plus.png");
  btn->image(icon);

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

void Director::constructSidePanel() {
  background bg{};

  Fl_Pack *pack = new Fl_Pack(0, 0, panelWidth, appHeight);
  Fl_Group *group = new Fl_Group(0, 0, panelWidth, appHeight);

  pack->spacing(8);
  group->box(FL_FLAT_BOX);
  group->color(bg.bg_color);

  constructInfoBtn();

  group->end();
  pack->end();
}

void Director::constructInfoBtn() {
  BtnBuilder builder(rect{.x = 5, .y = appHeight - 65, .w = panelWidth - 10});

  Fl_Button *btn = builder.setBtn(60);
  builder.setBG(background{.box_type = FL_NO_BOX});

  Fl_PNG_Image *icon = new Fl_PNG_Image("assets/info.png");
  btn->image(icon);
  btn->tooltip("Links to my Github");

  btn->callback([](Fl_Widget *w, void *data) {
    openURL("https://github.com/Relzarick/Tracker");
  });
}

void Director::constructDeleteBtn(int widgetID) {
  BtnBuilder builder(deleteBtn.pos);
  builder.getGroup()->begin();

  Fl_Button *btn = builder.setBtn(deleteBtn.pos.h);
  builder.setBG(background{.box_type = FL_NO_BOX});

  Fl_PNG_Image *icon = new Fl_PNG_Image("assets/delete.png");
  deleteData *cbData = new deleteData{med, widgetID};

  btn->image(icon);
  btn->tooltip(deleteBtn.tooltip);

  btn->callback(
      [](Fl_Widget *w, void *data) {
        auto d = static_cast<deleteData *>(data);
        int id = d->entryId;

        Fl_Group *group = d->med->returnGroupPointer(id);
        d->med->removeEntryFromList(id);

        Fl::delete_widget(group);
        w->window()->redraw();
      },
      cbData);

  builder.getGroup()->end();
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