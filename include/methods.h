#pragma once

#include "data.h"
#include <functional>

void start();
void printP(const product &p); // for testing

void renderTitle(int, int);
void renderInputs();

void createGroups(int x, int y, int width, int height, const std::function<void()> &content, std::optional<background> bg = std::nullopt);