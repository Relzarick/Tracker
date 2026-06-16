#pragma once

#include <Windows.h>

inline void openURL(const char *url) {
#ifdef _WIN32
  ShellExecuteA(nullptr, "open", url, nullptr, nullptr, SW_SHOWNORMAL);
#elif __linux__
  std::string cmd = std::string("xdg-open '") + url + "'";
  system(cmd.c_str());
#endif
}