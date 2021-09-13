#include <cstdio>
#include <iostream>

#ifndef point_hpp
#define point_hpp

class Point
 {
 private:
     int x,
         y,
         z;
 public:
     Point(){x=y=z=0;};
     Point (int x1, int y1, int z1);
     Point & operator = (const Point & b);
     Point operator + (const Point & b);
     friend std::ostream& operator << (std::ostream& os, const Point & b);
 };


#endif /* point_hpp */
