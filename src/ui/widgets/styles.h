#pragma once

#include "ui_types.h"

inline constexpr int divWidth = 660;
inline constexpr int divHeight = 250;

inline constexpr rect entryRect{.w = divWidth, .h = divHeight};

// For entry styles
inline constexpr int textHeight = 40;

inline constexpr layout header{.tooltip = "Entry name",
                               .pos = {20, 10, 170, textHeight}};

inline constexpr layout priceSymbol{.pos = {20, 66, 80, textHeight}};

inline constexpr layout price{.tooltip = "purchased price",
                              .pos = {40, 60, 100, textHeight}};

inline constexpr layout qtySymbol{.pos = {200, 16, 100, textHeight}};

inline constexpr layout qty{.tooltip = "Quantity remaining",
                            .pos = {255, 10, 80, textHeight}};

inline constexpr layout desc{.tooltip = "Description of the entry",
                             .pos = {20, 100, 600, 140}};
