//==================================================================================================
/**
  Copyright 2017 NumScale

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef STF_COMMON_DETAIL_DECLVAL_HPP_INCLUDED
#define STF_COMMON_DETAIL_DECLVAL_HPP_INCLUDED

#include <stf/common/config.hpp>

#if defined(STF_USE_INCOMPLETE_STD)
#include <boost/utility/declval.hpp>
namespace stf { namespace detail {
using boost::declval;
}}
#else
#include <utility>
namespace stf { namespace detail {
using std::declval;
} }
#endif

#endif
