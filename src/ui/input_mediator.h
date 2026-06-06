#pragma once

#include "database.h"
#include "ui_types.h"

#include <vector>

class InputMediator {
public:
  InputMediator(DB *db);

private:
  DB *db = nullptr;
  std::vector<entryWidgetData> entryList;
};