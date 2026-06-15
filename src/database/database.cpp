#include "database.h"
#include "data.h"

#include <cassert>
#include <print>
#include <sqlite3.h>
#include <vector>

using std::println;

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

  // Create a db for each folder
}

DB::~DB() { sqlite3_close(db); }

int DB::insert(const usrInput &input) {
  sqlite3_stmt *stmt;

  sqlite3_prepare_v2(
      db,
      "INSERT INTO entry (name, price, qty, description) VALUES (?, ?, ?, ?)",
      -1, &stmt, nullptr);

  sqlite3_bind_text(stmt, 1, input.name, -1, SQLITE_TRANSIENT);
  sqlite3_bind_double(stmt, 2, input.price);
  sqlite3_bind_int(stmt, 3, input.qty);
  sqlite3_bind_text(stmt, 4, input.description, -1, SQLITE_TRANSIENT);

  if (sqlite3_step(stmt) != SQLITE_DONE)
    println("SQL INSERT ERROR: {}", sqlite3_errmsg(db));

  int rowId = sqlite3_last_insert_rowid(db);

  sqlite3_finalize(stmt);
  return rowId;
}

void DB::update(int id, const usrInput &input) {
  assert(id > 0);

  sqlite3_stmt *stmt;

  sqlite3_prepare_v2(db,
                     "UPDATE entry SET "
                     "name = ?, price = ?, qty = ?, description = ? "
                     "WHERE id = ?",
                     -1, &stmt, nullptr);

  sqlite3_bind_text(stmt, 1, input.name, -1, SQLITE_TRANSIENT);
  sqlite3_bind_double(stmt, 2, input.price);
  sqlite3_bind_int(stmt, 3, input.qty);
  sqlite3_bind_text(stmt, 4, input.description, -1, SQLITE_TRANSIENT);
  sqlite3_bind_int(stmt, 5, id);

  if (sqlite3_step(stmt) != SQLITE_DONE)
    println("SQL UPDATE ERROR: {}", sqlite3_errmsg(db));

  int rowId = sqlite3_last_insert_rowid(db);

  sqlite3_finalize(stmt);
}

void DB::remove(int id) {
  assert(id > 0);
  sqlite3_stmt *stmt;

  sqlite3_prepare_v2(db, "DELETE FROM entry WHERE id = ?", -1, &stmt, nullptr);
  sqlite3_bind_int(stmt, 1, id);

  if (sqlite3_step(stmt) != SQLITE_DONE)
    println("SQL DELETE ERROR: {}", sqlite3_errmsg(db));

  sqlite3_finalize(stmt);
}

dbOutput DB::fetch(int id) {
  assert(id > 0);

  sqlite3_stmt *stmt;
  dbOutput result{};

  sqlite3_prepare_v2(db, "SELECT * FROM entry WHERE id = ?", -1, &stmt,
                     nullptr);

  sqlite3_bind_int(stmt, 1, id);

  if (sqlite3_step(stmt) == SQLITE_ROW) {
    result.id = sqlite3_column_int(stmt, 0);
    result.name = (const char *)sqlite3_column_text(stmt, 1);
    result.price = sqlite3_column_double(stmt, 2);
    result.qty = sqlite3_column_int(stmt, 3);
    result.description = (const char *)sqlite3_column_text(stmt, 4);
  } else
    println("SQL FETCH ERROR: {}", sqlite3_errmsg(db));

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