#include "rectangle.hpp"

#include <boost/io/ios_state.hpp>
#include <iostream>
#include <string>
#include <cassert>

#include "errors.hpp"
#include "support_functions.hpp"

Rectangle::Rectangle(const point_t& pos = { 0, 0 }, const double width = 1, const double height = 1) :
  pos_(pos),
  width_(width),
  height_(height)
{ 
}

Rectangle::Rectangle(const Rectangle& rect)
{
  *this = rect;
}

Rectangle::Rectangle(Rectangle&& rect) noexcept
{
  *this = std::move(rect);
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { width_, height_, pos_ };
}

point_t Rectangle::getPos() const
{
  return pos_;
}

void Rectangle::move(const double x, const double y)
{
  pos_.x += x;
  pos_.y += y;
}

void Rectangle::move(const point_t& centre)
{
  pos_ = centre;
}

std::ostream& Rectangle::outShape(std::ostream& out) const
{
  if (!out.good())
  {
    return out;
  }
  return ( out << "Rectangle centre: " << pos_ 
      << " | " << "Rectangle width: " << width_ 
      << " | " << "Rectangle height: " << height_ << '\n' );
}

Rectangle& Rectangle::operator=(const Rectangle& rect)
{
  assert(rect.width_ > 0);
  assert(rect.height_ > 0);

  pos_ = rect.pos_;
  width_ = rect.width_;
  height_ = rect.height_;

  return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& rect) noexcept
{
  assert(rect.width_ > 0);
  assert(rect.height_ > 0);

  pos_ = rect.pos_;
  width_ = rect.width_;
  height_ = rect.height_;

  delete& rect;
  return *this;
}

std::ostream& operator<<(std::ostream& out, const Rectangle& rect)
{
  return rect.outShape(out);
}

std::istream& operator>>(std::istream& in, Rectangle& rect)
{
  boost::io::ios_flags_saver startFlags(in);

  bool noErrors = true;
  Rectangle temp;

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
        in >> std::noskipws >> temp.width_;
        if (temp.width_ <= 0 || in.fail())
        {
          errors.add("Incorrect width in line " + std::to_string(line));
          in.setstate(std::ios::failbit);
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
            in >> std::noskipws >> temp.height_;
            if (temp.height_ <= 0 || in.fail())
            {
              errors.add("Incorrect height in line " + std::to_string(line));
              in.setstate(std::ios::failbit);
              noErrors = false;
            }
          }
        }
      }
    }
  }

  if (noErrors)
  {
    rect = temp;
  }
  return in;
}
