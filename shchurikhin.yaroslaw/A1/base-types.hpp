#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

#include <iostream>

struct point_t
{
  double x;
  double y;

  friend std::istream& operator>>(std::istream& in, point_t& point);
  friend std::ostream& operator<<(std::ostream& out, const point_t& point);
};

struct rectangle_t
{
  double width;
  double height;
  point_t pos;

  friend std::ostream& operator<<(std::ostream& out, const rectangle_t& rect);
};
#endif
