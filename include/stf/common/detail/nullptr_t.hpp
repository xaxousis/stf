//==================================================================================================
/**
  Copyright 2017 NumScale

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef STF_COMMON_DETAIL_NULLPTR_T_HPP_INCLUDED
#define STF_COMMON_DETAIL_NULLPTR_T_HPP_INCLUDED

#include <stf/common/config.hpp>

namespace stf { namespace detail
{
#if defined(STF_USE_INCOMPLETE_STD)
  using nullptr_t = decltype(nullptr);
#else
  using nullptr_t = std::nullptr_t;
#endif
} }

#endif
