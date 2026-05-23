#include "database.h"
#include "data.h"

#include <cassert>
#include <print>
#include <sqlite3.h>
#include <vector>

DB::DB(const char *name) {
  char *err = nullptr;

  sqlite3_open(name, &db);

  sqlite3_exec(db,
               "CREATE TABLE IF NOT EXISTS entry("
               "id INTEGER PRIMARY KEY,"
               "name TEXT NOT NULL,"
               "price REAL,"
               "qty INTEGER,"
               "description TEXT)",
               nullptr, nullptr, &err);

  //. add more fields after making this work
  // Create a db for each folder
}

DB::~DB() { sqlite3_close(db); }

void DB::insert(const usrInput &data) {
  sqlite3_stmt *stmt;

  sqlite3_prepare_v2(
      db,
      "INSERT INTO entry (name, price, qty, description) VALUES (?, ?, ?, ?)",
      -1, &stmt, nullptr);

  sqlite3_bind_text(stmt, 1, data.name, -1, SQLITE_TRANSIENT);
  sqlite3_bind_double(stmt, 2, data.price);
  sqlite3_bind_int(stmt, 3, data.qty);
  sqlite3_bind_text(stmt, 4, data.description, -1, SQLITE_TRANSIENT);

  if (sqlite3_step(stmt) != SQLITE_DONE)
    std::println("SQL INSERT ERROR: {}", sqlite3_errmsg(db));

  sqlite3_finalize(stmt);
}

dbOutput DB::edit(int id) {
  dbOutput db{};

  return db;
}

dbOutput DB::fetch(int id) {
  sqlite3_stmt *stmt;
  dbOutput result{};

  sqlite3_prepare_v2(db, "SELECT * FROM entry WHERE id = ?", -1, &stmt,
                     nullptr);

  assert(id > 0);
  sqlite3_bind_int(stmt, 1, id);

  if (sqlite3_step(stmt) == SQLITE_ROW) {
    int rowId = sqlite3_column_int(stmt, 0); // might be useful
    result.name = (const char *)sqlite3_column_text(stmt, 1);
    result.price = sqlite3_column_double(stmt, 2);
    result.qty = sqlite3_column_int(stmt, 3);
    result.description = (const char *)sqlite3_column_text(stmt, 4);
  } else
    std::println("SQL FETCH ERROR: {}", sqlite3_errmsg(db));

  sqlite3_finalize(stmt);
  return result;
}

std::vector<dbOutput> DB::fetchAll() {
  sqlite3_stmt *stmt;
  std::vector<dbOutput> results{};

  sqlite3_prepare_v2(db, "SELECT * FROM entry", -1, &stmt, nullptr);

  while (sqlite3_step(stmt) == SQLITE_ROW) {
    dbOutput row{};
    row.id = sqlite3_column_int(stmt, 0);
    row.name = (const char *)sqlite3_column_text(stmt, 1);
    row.price = sqlite3_column_double(stmt, 2);
    row.qty = sqlite3_column_int(stmt, 3);
    row.description = (const char *)sqlite3_column_text(stmt, 4);
    results.push_back(row);
  }

  sqlite3_finalize(stmt);
  return results;
};