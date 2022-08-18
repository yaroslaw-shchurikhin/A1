#include "circle.hpp"

#include <iostream>
#include <boost/io/ios_state.hpp>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <iomanip>
#include <cassert>

#include "errors.hpp"
#include "support_functions.hpp"

Circle::Circle(const point_t& pos = { 0, 0 }, const double radius = 1) :
  pos_(pos),
  radius_(radius)
{ 
}

Circle::Circle(const Circle& circle)
{
  *this = circle;
}

Circle::Circle(Circle&& circle) noexcept
{
  *this = std::move(circle);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return { radius_ * 2, radius_ * 2, pos_ };
}

point_t Circle::getPos() const
{
  return pos_;
}

void Circle::move(const double x, const double y)
{
  pos_.x += x;
  pos_.y += y;
}

void Circle::move(const point_t& centre)
{
  pos_ = centre;
}

std::ostream& Circle::outShape(std::ostream& out) const
{
  if (!out.good())
  {
    return out;
  }
  return ( out << "Circle centre: " << pos_ << " | " << "Circle radius: " << radius_ << '\n' );
}

Circle& Circle::operator=(const Circle& circle)
{
  assert(circle.radius_ > 0);

  pos_ = circle.pos_;
  radius_ = circle.radius_;

  return *this;
}

Circle& Circle::operator=(Circle&& circle) noexcept
{
  assert(circle.radius_ > 0);

  pos_ = circle.pos_;
  radius_ = circle.radius_;

  delete &circle;
  return *this;
}

std::ostream& operator<<(std::ostream& out, const Circle& circle)
{
  return circle.outShape(out);
}

std::istream& operator>>(std::istream& in, Circle& circle)
{
  boost::io::ios_flags_saver startFlags(in);

  bool noErrors = true;
  Circle temp;

  if (!in.good())
  {
    noErrors = false;
  }

  if (noErrors)
  {
    in >> std::noskipws >> temp.pos_;
    if (!in.good())
    {
      noErrors = false;
    }

    if (noErrors)
    {
      if (checkEndl(in))
      {
        noErrors = false;
      }

      if (noErrors)
      {
        in >> std::noskipws >> temp.radius_;
        if (temp.radius_ <= 0 || in.fail())
        {
          errors.add("Incorrect radius in line " + std::to_string(line));
          in.setstate(std::ios::failbit);
          noErrors = false;
        }
      }
    }
  }
  if (noErrors)
  {
    circle = temp;
  }
  return in;
}
