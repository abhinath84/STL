#include <iostream>

#include <vector>
#include <list>
#include <iterator>


void checkDuplicateVectorListItem(std::list<int>::iterator left, std::vector<std::list<int> > &ivec)
{
  std::cout << "Inside checkDuplicateVectorListItem" << std::endl;

  for (std::vector<std::list<int> >::iterator viit(ivec.begin()); viit != ivec.end(); ++viit)
  {
    for (std::list<int>::iterator liit(viit->begin()); liit != viit->end(); ++liit)
    {
      int dref = *liit;   // Dereference of iterator.
      if (liit != left)
        std::cout << *liit << std::endl;
    }
  }
}

void appendList(std::vector<std::list<int> > &vec, int init)
{
  std::list<int> lst;

  for(int i = 1; i <=10; ++i)
    lst.push_back(init * i);

  vec.push_back(lst);
}

int mixed_main()
{
  std::vector<std::list<int> > v;
  appendList(v, 1);
  appendList(v, 10);
  appendList(v, 100);
  appendList(v, 1000);

  for (std::vector<std::list<int> >::iterator vit(v.begin()); vit != v.end(); ++vit)
  {
    for(std::list<int>::iterator lit(vit->begin()); lit != vit->end(); ++lit)
      checkDuplicateVectorListItem(lit, v);
  }


  system("pause");
  return(0);
}
