#include "errors.hpp"

#include <list>
#include <ostream>
#include <iterator>

Errors errors;
int line = 1;

int Errors::count() const
{
  return errors_.size();
}

void Errors::add(const std::string& text)
{
  errors_.push_back(text);
}

std::ostream& Errors::print(std::ostream& out) const
{
  if (!out.good())
  {
    return out;
  }

  std::copy(errors_.begin(), errors_.end(), std::ostream_iterator<std::string>(out, "\n"));
  return out;
}

std::ostream& operator<<(std::ostream& out, const Errors& err)
{
  return err.print(out);
}
