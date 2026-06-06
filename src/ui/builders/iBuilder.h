#pragma once

#include "widgets/ui_types.h"

#include <optional>

#include <FL/Fl.H>
#include <FL/Fl_Group.H>

class IBuilder {
public:
  virtual void setBG(const std::optional<background> &bg) = 0;
  virtual Fl_Group *getGroup() = 0;

  virtual ~IBuilder() = default;
};