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
  }
}

#endif    // STLUTILITY_H