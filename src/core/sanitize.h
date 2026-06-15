#pragma once

#include <string>

namespace sanitize {
inline int cleanIntInput(const char *num) {
  int result;

  try {
    result = std::stoi(num);

    if (result < 0)
      result *= -1;

  } catch (const std::exception &e) {
    result = 0;
  }

  return result;
}

inline double cleandoubleInput(const char *num) {
  double result;

  try {
    result = std::stod(num);

    if (result < 0)
      result *= -1;

  } catch (const std::exception &e) {
    result = 0;
  }

  return result;
}
} // namespace sanitize