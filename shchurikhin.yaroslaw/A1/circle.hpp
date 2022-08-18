#include "shape.hpp"

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <iostream>

class Circle :
  public Shape
{
public:
  Circle(const point_t& pos, const double radius);
  Circle(const Circle& circle);
  Circle(Circle&& circle) noexcept;

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  point_t getPos() const override;

  void move(const double x, const double y) override;
  void move(const point_t& centre) override;
  std::ostream& outShape(std::ostream& out) const override;

  Circle& operator=(const Circle& circle);
  Circle& operator=(Circle&& circle) noexcept;

  friend std::ostream& operator<<(std::ostream& out, const Circle& circle);
  friend std::istream& operator>>(std::istream& in, Circle& circle);

private:
  point_t pos_;
  double radius_;
};
#endif
