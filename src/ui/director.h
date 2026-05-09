#pragma once

#include "builders.h"
#include "iBuilder.h"

class Director {
public:
  void constructText(TextBuilder &builder);

private:
  IBuilder *builder = nullptr;
};