#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <ostream>
#include <list>

class Errors
{
public:
  Errors() = default;

  int count() const;
  void add(const std::string& text);
  std::ostream& print(std::ostream& out) const;

  friend std::ostream& operator<<(std::ostream& out, const Errors& err);

private:
  std::list<std::string> errors_;
};

extern Errors errors;
extern int line;
#endif
