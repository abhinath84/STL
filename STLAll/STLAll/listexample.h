#ifndef LISTEXAMPLE_H
#define LISTEXAMPLE_H

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>


// Template methods
template<typename T>
void printList(const std::string &title, const std::list<T> &lst)
{
  std::cout << title.c_str() << std::endl;
  std::copy(lst.cbegin(), lst.cend(), std::ostream_iterator<T>(std::cout, " "));
  std::cout << std::endl;
}

template<typename T>
void printTwoLists(const std::list<T> &fstList, const std::list<T> &sndList)
{
  printList("First List :", fstList);
  printList("second List :", sndList);
  std::cout << std::endl << std::endl;
}



// Methods
void listSimpleExample();

#endif  //LISTEXAMPLE_H
