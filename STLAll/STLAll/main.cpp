#include <iostream>

#include "listexample.h"
#include "vectorexample.h"

const int choose = 2;   // 1 = list, 2 = vector 

int main(int argc, char **argv)
{
  // list section
  if(choose == 1)
  {
    listSimpleExample();
  }

  // Vector section
  if(choose == 2)
  {
    vectorSimpleExample();
  }

  system("pause");
  return(0);
}
