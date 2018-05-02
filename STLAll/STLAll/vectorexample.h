#ifndef VECTOREXAMPLE_H
#define VECTOREXAMPLE_H

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>


// Template methods
template<typename T>
void printVector(const std::string &title, const std::vector<T> &vec)
{
  std::cout << title.c_str() << std::endl;
  std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<T>(std::cout, " "));
  std::cout << std::endl;
}

// Methods
void vectorSimpleExample();

#endif  //VECTOREXAMPLE_H
