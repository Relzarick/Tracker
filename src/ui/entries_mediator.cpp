#include "Entries_mediator.h"
#include "FL/Fl_Group.H"
#include "data.h"
#include "database.h"
#include "ui_types.h"

#include <print>

using std::erase_if, std::println;

EntriesMediator::EntriesMediator(DB *db) { this->db = db; }

void EntriesMediator::updateDBField(Fl_Input *field) {
  widgetsData *entry = retrieveEntry(field);

  if (entry == nullptr) {
    println("UpdateDB: Entry Not Found");
    return;
  }

  usrInput input{entry->name->value(), std::stod(entry->price->value()),
                 std::stoi(entry->qty->value()), entry->desc->value()};

  // td clean the value()

  db->update(entry->id, input);
}

void EntriesMediator::setEntryToList(widgetsData &entry) {
  entryList.push_back(entry);
}

void EntriesMediator::removeEntryFromList(int id) {
  removeDBField(id);

  erase_if(entryList, [&](const widgetsData &e) { return e.id == id; });
}

int EntriesMediator::returnLastEntry() { return entryList.back().id; };

Fl_Group *EntriesMediator::returnGroupPointer(int id) {
  for (int i = 0; i < entryList.size(); i++) {
    if (entryList[i].id == id)
      return entryList[i].group;
  }

  return nullptr;
}

int EntriesMediator::insertBlankEntry() {
  int rowId = db->insert(usrInput{});
  return rowId;
}

widgetsData *EntriesMediator::retrieveEntry(Fl_Input *p) {
  for (int i = 0; i < entryList.size(); i++) {
    if (p == entryList[i].name || p == entryList[i].price ||
        p == entryList[i].qty || p == entryList[i].desc)

      return &entryList[i];
  }

  // td if there is time, find a faster way to search
  return nullptr;
}

void EntriesMediator::removeDBField(int index) { db->remove(index); }