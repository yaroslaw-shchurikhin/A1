#include "base-types.hpp"

#include <iostream>
#include <boost/io/ios_state.hpp>

#include "errors.hpp"
#include "support_functions.hpp"

std::istream& operator>>(std::istream& in, point_t& point)
{
  boost::io::ios_flags_saver startFlags(in);

  bool noErrors = true;
  point_t temp{ 0, 0 };

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
      in >> temp.x;
      if (!in.good())
      {
        errors.add("Incorrect coordinate of the abscissa of the center in line " + std::to_string(line));
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
          in >> temp.y;
          if (!in.good())
          {
            errors.add("Incorrect coordinate of the ordinate of the center in line " + std::to_string(line));
            noErrors = false;
          }
        }
      }
    }
  }
  if (!noErrors)
  {
    point.x = temp.x;
    point.y = temp.y;
  }
  return in;
}

std::ostream& operator<<(std::ostream& out, const point_t& point)
{
  if (!out.good())
  {
    return out;
  }
  return ( out << "(" << point.x << ";" << point.y << ")" );
}

std::ostream& operator<<(std::ostream& out, const rectangle_t& rect)
{
  if (!out.good())
  {
    return out;
  }
  return (out << "Centre of rectangle: " << rect.pos << " width = " << rect.width
      << " height = " << rect.height);
}
