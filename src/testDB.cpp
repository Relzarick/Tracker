#include <sqlite3.h>

#include <print>

using std::print;

void createDB() {
  sqlite3 *db;
  sqlite3_stmt *stmt;

  sqlite3_open("test.db", &db);

  sqlite3_exec(db,
               "CREATE TABLE IF NOT EXISTS items (id INTEGER PRIMARY KEY "
               "AUTOINCREMENT, name TEXT)",
               nullptr, nullptr, nullptr);

  sqlite3_exec(db, "INSERT INTO items (name) VALUES ('Duck')", nullptr, nullptr,
               nullptr);

  sqlite3_prepare_v2(db, "SELECT id, name FROM items", -1, &stmt, nullptr);

  while (sqlite3_step(stmt) == SQLITE_ROW) {
    print("{} {}\n", sqlite3_column_int(stmt, 0),
          reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);
}

void initDB(const char *dbName) {
  sqlite3 *db;

  sqlite3_open(dbName, &db);

  sqlite3_close(db);
}

void insertDB() {}

void editTable() {}

// change to class