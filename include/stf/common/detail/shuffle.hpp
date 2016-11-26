//==================================================================================================
/**
  Copyright 2016 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef STF_COMMON_DETAIL_RANDOM_HPP_INCLUDED
#define STF_COMMON_DETAIL_RANDOM_HPP_INCLUDED

#include <algorithm>

 namespace stf { namespace detail
 {
 #if defined(STF_USE_INCOMPLETE_STD)
  template<typename RGenFct> struct URNGConv
  {
    int operator()(int) { return fct(); }
    RGenFct fct;
  };

  template<typename RandomIt, typename RGenFct>
  void shuffle(RandomIt const& begin, RandomIt const& end, RGenFct&& r)
  {
    URNGConv<RGenFct> wrp({r});
    std::random_shuffle(begin, end, wrp);
  }
#else
  using std::shuffle;
#endif
} }

#endif
