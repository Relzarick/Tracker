#pragma once

#include "builders.h"
#include "iBuilder.h"

class Director {
public:
  void constructEntry(TextBuilder &builder);

private:
  IBuilder *builder = nullptr;
};