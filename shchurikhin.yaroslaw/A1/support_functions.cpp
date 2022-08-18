#include "support_functions.hpp"

#include <istream>
#include <string>
#include <cctype>

#include "errors.hpp"

void skipws(std::istream& in)
{
  while (isblank(in.peek()))
  {
    in.ignore(1);
  }
}

bool checkEndl(std::istream& in)
{
  skipws(in);

  if (iscntrl(in.get()) || in.eof())
  {
    in.unget();
    errors.add("Lack of data in line " + std::to_string(line));
    in.setstate(std::ios::failbit);
    return true;
  }

  in.unget();
  return false;
} 
