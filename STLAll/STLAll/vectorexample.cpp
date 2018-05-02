#include "vectorexample.h"
#include "stlutility.h"


void vectorSimpleExample()
{
  // Init vector
  std::vector<int> ivec;

  // Fill the vector
  ivec.push_back(11);
  ivec.push_back(22);
  ivec.push_back(33);
  ivec.push_back(44);
  ivec.push_back(55);
  ivec.push_back(66);
  ivec.push_back(77);
  ivec.push_back(88);
  ivec.push_back(99);

  // Print the vector
  printVector("Vector : ", ivec);

  // Erase odd element
  // Following method is not a good way to remove element from vector
  // while iterating elements in the vector (range base iterator) as 
  // it took O(n^2) - Quadratic time to complete the removal of vector elements.
  /*for(std::vector<int>::iterator it = ivec.begin(); it != ivec.end(); )
  {
    if((*it % 2) == 1)
      it = ivec.erase(it);
    else
      ++it;
  }*/

  // better way if to use 'remove_if' and 'erase' method.
  // It'll took O(n) - Linear time.
  //ivec.erase(std::remove_if(ivec.begin(), ivec.end(),
  //                          [] (int elem) { return ((elem % 2) == 1); }),
  //            ivec.end());

  // my own range based erase implementation (using template metaprogramming).
  avenger::erase_if(ivec, [] (int elem) { return ((elem % 2) == 1); });


  // Print the vector
  printVector("After Erase odd elements : ", ivec);
}
