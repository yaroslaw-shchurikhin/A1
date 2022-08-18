#include "base-types.hpp"

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <ostream>

class Shape
{
public:
  virtual ~Shape() = default;

  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual point_t getPos() const = 0;

  virtual void move(const double x, const double y) = 0;
  virtual void move(const point_t& centre) = 0;
  virtual std::ostream& outShape(std::ostream& out) const = 0;
};
#endif
