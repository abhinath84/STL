#include "listexample.h"

void listSimpleExample()
{
  // Init list
  std::list<int> lst1, lst2;

  // Fill list
  for(int i = 0; i <= 5; ++i)
  {
    lst1.push_back(i);
    lst2.push_front(i);
  }
  // Print list
  printTwoLists(lst1, lst2);

  // Splice before value 3
  lst2.splice(std::find(lst2.begin(), lst2.end(), 3), lst1);
  // Print list
  printTwoLists(lst1, lst2);

  // Move first element of list2 to the end
  lst2.splice(lst2.end(), lst2, lst2.begin());
  // Print list
  printTwoLists(lst1, lst2);

  // Sort second list, assign to list1 and remove duplicates
  lst2.sort();
  lst1 = lst2;
  lst2.unique();
  // Print list
  printTwoLists(lst1, lst2);

  // Merge both sorted lists into the first list
  lst1.merge(lst2);
  // Print list
  printTwoLists(lst1, lst2);
}
