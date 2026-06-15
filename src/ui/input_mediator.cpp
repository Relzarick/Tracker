#include "input_mediator.h"
#include "data.h"
#include "database.h"
#include "ui_types.h"

#include <string>

#include <FL/Fl_Input.H>

InputMediator::InputMediator(DB *db) { this->db = db; }

void InputMediator::updateDBField(Fl_Input *field) {

  widgetsData entry = entryList[retrieveEntryId(field)];

  usrInput input{entry.name->value(), std::stod(entry.price->value()),
                 std::stoi(entry.qty->value()), entry.desc->value()};

  // td need to clean the input

  getDB()->update(entry.id, input);
}

void InputMediator::setEntryToList(widgetsData entry) {
  entryList.push_back(entry);
}

int InputMediator::retrieveEntryId(Fl_Input *p) {
  for (int i = 0; i < entryList.size(); i++) {
    if (p == entryList[i].name || p == entryList[i].price ||
        p == entryList[i].qty || p == entryList[i].desc)
      return i;
  }

  return -1;
  // td make this not crash if not found
}

int InputMediator::insertBlankEntry() {
  usrInput blank{"", 0, 0, ""};

  int rowId = db->insert(blank);

  return rowId;
}

DB *InputMediator::getDB() { return db; }