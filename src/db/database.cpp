#include "database.h"
#include <sqlite3.h>

DB::DB(const char *name) {
  sqlite3 *db;

  sqlite3_open(name, &db);
  //   sqlite3_exec(&db, const char *sql, int (*callback)(void *, int, char **,
  //   char **), void *, char **errmsg);

  // * create all the fields here

  sqlite3_close(db);
}

void DB::insertData() {}
void DB::editTable() {}
void DB::createProcedure(const char *query) {
  // access the vector
  // auto test = procedures[1];

  // ? do I even need this
  // ? just hard code all the query?

  // sqlite3_prepare_v2(*db, query, -1, insert into vector, nullptr);
}

void DB::callProcedure() {} //? pass in pointer?