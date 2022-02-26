// Copyright 2018 <Minh Tran>

#ifndef HW01_POINT2_H_
#define HW01_POINT2_H_

class Point2 {
 public:
  // constructors
  Point2();
  Point2(float a, float b);

  // regular member function(s)
  float DistanceBetween(Point2 n);

 private:
  // member variables
  float x;
  float y;
};

#endif  // HW01_POINT2_H_
