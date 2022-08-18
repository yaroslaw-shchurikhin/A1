#include <iostream>
#include <fstream>

#include "read.hpp"
#include "errors.hpp"

int source()
{
  std::cout << "Enter code: \n0 - if you want read and write with files";
  std::cout << "\n1 - if you want only to read from file\n \nYour code is: ";

  int code;
  std::cin >> code;
  if (!std::cin)
  {
    std::cerr << "\nIncorrect code!\n";
    return 1;
  }
  std::cout << '\n';

  if (code == 1)
  {
    std::cout << "Enter name of input file\n";
    std::string inFileName;
    std::cin >> inFileName;

    std::ifstream in(inFileName);
    if (!in)
    {
      std::cout << "\nIncorrect input file name!\n";
      return 1;
    }
    read(in);
  }

  else if (code == 0)
  {
    std::cout << "Enter name of input file\n";
    std::string inFileName;
    std::cin >> inFileName;

    std::ifstream in(inFileName);
    if (!in)
    {
      std::cerr << "\nIncorrect input file name!\n";
      return 1;
    }

    std::string outFileName;
    std::cout << "\nEnter name of output file\n";
    std::cin >> outFileName;

    std::ofstream out(outFileName);
    if (!out.is_open())
    {
      std::cerr << "\nFailed to create output file\n";
      return 1;
    }

    read(in);
  }
  else
  {
    std::cerr << "\nIncorrect code!\n";
    return 1;
  }

  std::cout << "\nTotal errors: " << errors.count() << "\n\n";
  std::cout << errors;
  return 0;
}
