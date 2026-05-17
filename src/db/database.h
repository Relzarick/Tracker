#pragma once

#include <sqlite3.h>
#include <vector>

class DB {
public:
  DB(const char *name);
  void insertData();
  void editTable();

private:
  sqlite3 *db;
  std::vector<sqlite3_stmt> *procedures;

  void createProcedure(const char *query);
  void callProcedure();
};