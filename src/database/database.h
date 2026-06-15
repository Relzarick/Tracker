#pragma once

#include "data.h"

#include <sqlite3.h>
#include <vector>

class DB {
public:
  DB(const char *);
  ~DB();

  int insert(const usrInput &);
  void update(int, const usrInput &);
  void remove(int);

  dbOutput fetch(int);
  std::vector<dbOutput> fetchAll();

private:
  sqlite3 *db = nullptr;
};