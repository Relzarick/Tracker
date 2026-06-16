#pragma once

#include "ui_types.h"

inline constexpr int appWidth = 700;
inline constexpr int appHeight = 750;

inline constexpr int panelWidth = 70;

inline constexpr int divWidth = appWidth - panelWidth - 34;
inline constexpr int divHeight = 250;

inline constexpr rect entryRect{.w = divWidth, .h = divHeight};

// For entry styles
inline constexpr int textHeight = 40;
inline constexpr int textSize = 22;

// Private rect
namespace {
constexpr rect nameRect{15, 10, 170, textHeight};
constexpr rect priceSymbolRect{15, 66, 80, textHeight};
constexpr rect priceRect{35, 60, 150, textHeight};
constexpr rect qtySymbolRect{195, 16, 100, textHeight};
constexpr rect qtyRect{250, 10, 100, textHeight};
constexpr rect descRect{15, 100, 566, 140};
constexpr rect deleteBtnRect{.x = 551, .y = 15, .w = 30, .h = 40};

} // namespace

inline constexpr layout header{"Entry name", nameRect};
inline constexpr layout priceSymbol{.pos = priceSymbolRect};
inline constexpr layout price{"purchased price", priceRect};
inline constexpr layout qtySymbol{.pos = qtySymbolRect};
inline constexpr layout qty{"Quantity remaining", qtyRect};
inline constexpr layout desc{"Description of the entry", descRect};

inline constexpr layout deleteBtn{"Click to delete entry", deleteBtnRect};
