#ifndef READ_HPP
#define READ_HPP

#include <iostream>
#include <memory>
#include <vector>
#include <limits>
#include <string>

#include "circle.hpp"
#include "rectangle.hpp"
#include "errors.hpp"

void cleanFlagsAndSkipIncorrectSymbs(std::istream& in);

void read(std::istream& in)
{
  std::vector<std::shared_ptr<Shape>> shapes;

  while (!in.eof())
  {
    std::string typeOfShape;
    in >> typeOfShape;

    if (typeOfShape == "Circle")
    {
      Circle circle({ 0, 0 }, 0);
      in >> circle;

      if (in.fail())
      {
        cleanFlagsAndSkipIncorrectSymbs(in);
      }
      else
      {
        shapes.push_back(std::make_shared<Circle>(circle));
      }
      ++line;
    }

    else if (typeOfShape == "Rectangle")
    {
      Rectangle rect({ 0, 0 }, 0, 0);
      in >> rect;

      if (in.fail())
      {
        cleanFlagsAndSkipIncorrectSymbs(in);
      }
      else
      {
        shapes.push_back(std::make_shared<Rectangle>(rect));
      }
      ++line;
    }

    else
    {
      ++line;
      errors.add("Incorrect type of shape in line " + std::to_string(line));
      cleanFlagsAndSkipIncorrectSymbs(in);
    }
  }
}

void cleanFlagsAndSkipIncorrectSymbs(std::istream& in)
{
  in.clear();
  in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
#endif
