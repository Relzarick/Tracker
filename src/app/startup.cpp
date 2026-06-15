#include "data.h"
#include "database.h"
#include "director.h"

#include <vector>

void fetchFromDB(DB *db, Director *dir) {
  std::vector<dbOutput> dbList = db->fetchAll();

  if (dbList.size() == 0)
    return;

  for (const auto &entry : dbList)
    dir->constructEntry(entry);
}