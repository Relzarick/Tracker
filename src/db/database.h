#pragma once

#include <sqlite3.h>
#include <vector>

class DB {
public:
  DB(const char *name);

private:
  sqlite3 *db;
  std::vector<sqlite3_stmt> *procedures;

  void insertData();
  void editTable();
  void createProcedure(const char *query);
  void callProcedure();
};