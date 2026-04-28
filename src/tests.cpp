#include "data.h"

#include <print>

using std::print;

void testPrint()
{
  product test;
  test.name = "apple";
  test.description = "testing";
  test.price = 22.0;
  test.qty = 22;

  test.adv = advanceInfo{
      year_month_day{year{2020}, month{9}, day{29}},
      year_month_day{year{2022}, month{3}, day{19}}};

  print("Tracker APP\n");
  printP(test);
}

void printP(const product &p)
{
  print("[{}] {} | qty: {} | ${:.2f}", p.name, *p.description, p.qty, p.price);

  if (p.adv)
  {
    if (p.adv->purchase)
      std::print(" | purchased: {}", *p.adv->purchase);
    if (p.adv->expiry)
      std::print(" | expires: {}", *p.adv->expiry);
  }

  print("\n");
}