/**
 * @file main.cc
 *
 * @copyright 2018 3081 Staff, All rights reserved.
 */

#include "Date.h"

#include <iostream>
#include <string>

void doInterestingThing(int yr) {
  // variables used in this method
  int array_len;
  Date d1;
  Date d2;
  Date d3;
  Date* birthday_list;

  std::cout << " ... A set of Dates ... " << std::endl;

  d2 = Date(yr, 4, 19);
  d3 = d2.copy();
  array_len = 4;

  std::cout << "default date is: " << d1.show() << std::endl;

  std::cout << "date d2 is: " << d2.show() << endl;

  std::cout << "date d3 is: " << d3.show() << endl;

  std::cout << " ... Now print out 4 dates in reverse time order ... "
            << std::endl;

  birthday_list = new Date[array_len];
  // accumulate the all dates January 1, from 1990 to 1990+array_len
  for (int i = 0; i < array_len; i++) {
    birthday_list[i] = Date(1990+i, 1, 1);
  }

  // now show the dates accumulated in reverse order
  for (int i = array_len-1; i >= 0; i--) {
    std::cout << "date is: " << birthday_list[i].show() << std::endl;
  }

  // now set the dates to January 2
  for (int i = 0; i < array_len; i++) {
    birthday_list[i] = Date(1990+i, 1, 2);
  }

  std::cout << "the first date is: " << birthday_list[0].show() << std::endl;
}

int main() {
  doInterestingThing(1998);
  doInterestingThing(1999);
  std::cout << std::endl << "... Goodbye ..." << std::endl;
}
