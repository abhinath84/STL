#ifndef STLUTILITY_H
#define STLUTILITY_H

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>


// Implement generic range based element removal from STL containers.
namespace avenger
{
  namespace detail
  {
    // struct to specify typedef of containers.
    struct vectorlike_tag { };
    struct listlike_tag { };
    struct associativelike_tag { };

    // Trait to identify typedef of containers.
    template<typename C> struct container_traits;

    template<typename T, typename A> struct container_traits<std::vector<T, A> >
    { typedef vectorlike_tag category; };

    template<typename T, typename A> struct container_traits<std::deque<T, A> >
    { typedef vectorlike_tag category; };

    template<typename T, typename A> struct container_traits<std::list<T, A> >
    { typedef listlike_tag category; };

    template<typename T, typename A> struct container_traits<std::forward_list<T, A> >
    { typedef listlike_tag category; };

    template<typename T, typename C, typename A> struct container_traits<std::set<T, C, A> >
    { typedef associativelike_tag category; };

    template<typename T, typename C, typename A> struct container_traits<std::multiset<T, C, A> >
    { typedef associativelike_tag category; };

    template<typename T, typename C, typename A> struct container_traits<std::map<T, C, A> >
    { typedef associativelike_tag category; };

    template<typename T, typename C, typename A> struct container_traits<std::multimap<T, C, A> >
    { typedef associativelike_tag category; };

    template<typename T, typename C, typename A> struct container_traits<std::unordered_set<T, C, A> >
    { typedef associativelike_tag category; };

    template<typename T, typename C, typename A> struct container_traits<std::unordered_multiset<T, C, A> >
    { typedef associativelike_tag category; };

    template<typename T, typename C, typename A> struct container_traits<std::unordered_map<T, C, A> >
    { typedef associativelike_tag category; };

    template<typename T, typename C, typename A> struct container_traits<std::unordered_multimap<T, C, A> >
    { typedef associativelike_tag category; };

    // Helper methods for erase & erase_if for different container type
    template<typename Container, typename Arg> void erase_helper(Container &c, const Arg &arg, vectorlike_tag)
    {
      c.erase(std::remove(c.begin(), c.end(), arg), c.end());
    }

    template<typename Container, typename Pred> void erase_if_helper(Container &c, Pred p, vectorlike_tag)
    {
      c.erase(std::remove_if(c.begin(), c.end(), p), c.end());
    }

    template<typename Container, typename Arg> void erase_helper(Container &c, const Arg &arg, listlike_tag)
    {
      c.remove(x);
    }

    template<typename Container, typename Pred> void erase_if_helper(Container &c, Pred p, listlike_tag)
    {
      c.remove_if(p);
    }

    template<typename Container, typename Arg> void erase_helper(Container &c, const Arg &arg, associativelike_tag)
    {
      c.remove(x);
    }

    template<typename Container, typename Pred> void erase_if_helper(Container &c, Pred p, associativelike_tag)
    {
      for(auto itr = c.begin(); itr != c.end(); )
      {
        if(p(*itr))
          c.erase(itr++);
        else
          ++itr;
      }
    }
  }

  // Implement the generic method for erase and erase_if for user
  template<typename Container, typename Arg> void erase(Container &c, const Arg &arg)
  {
    detail::erase_helper(c, arg, typename detail::container_traits<Container>::category());
  }

  template<typename Container, typename Pred> void erase_if(Container &c, Pred p)
  {
    detail::erase_if_helper(c, p, typename detail::container_traits<Container>::category());
  }
}

#endif    // STLUTILITY_H