#include "shape.hpp"

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>

class Rectangle :
  public Shape
{
public:
  Rectangle(const point_t& pos, const double width, const double height);
  Rectangle(const Rectangle& rect);
  Rectangle(Rectangle&& rect) noexcept;

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  point_t getPos() const override;

  void move(const double x, const double y) override;
  void move(const point_t& centre) override;
  std::ostream& outShape(std::ostream& out) const override;

  Rectangle& operator=(const Rectangle& rect);
  Rectangle& operator=(Rectangle&& rect) noexcept;

  friend std::ostream& operator<<(std::ostream& out, const Rectangle& rect);
  friend std::istream& operator>>(std::istream& in, Rectangle& rect);

private:
  point_t pos_;
  double width_;
  double height_;
};
#endif
