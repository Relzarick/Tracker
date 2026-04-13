#include <iostream>
#include <vector>
#include <string>
#include <print>
#include <chrono>

#include "methods.h"
#include "data.h"
#include <conio.h>

using std::cout, std::cin, std::vector, std::string, std::print;

using namespace std::chrono;

int main()
{
  start();
}

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

  printP(test);
}

void start()
{
  print("Tracker APP\n");
  testPrint();
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