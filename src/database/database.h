#pragma once

#include "data.h"

#include <sqlite3.h>
#include <vector>

class DB {
public:
  DB(const char *name);
  ~DB();

  int insert(const usrInput &input);
  void update(int id, const usrInput &input);

  dbOutput fetch(int id);
  std::vector<dbOutput> fetchAll();

private:
  sqlite3 *db = nullptr;
};