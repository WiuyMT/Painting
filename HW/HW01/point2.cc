// Copyright 2018 <Minh Tran>

#include <math.h>
#include "HW01/point2.h"

Point2::Point2() {
  x = 0.0;
  y = 0.0;
}

Point2::Point2(float a, float b) {
  x = a;
  y = b;
}

float Point2::DistanceBetween(Point2 n) {
  return sqrt(pow((n.x - x), 2.0) + pow((n.y - y), 2.0));
}
