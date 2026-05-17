#pragma once

#include "data.h"

#include <FL/Fl.H>
#include <FL/Fl_Group.H>

#include <optional>

class IBuilder {
public:
  virtual void setBG(const std::optional<background> &bg) = 0;
  virtual Fl_Group *getGroup() = 0;

  virtual ~IBuilder() = default;
};