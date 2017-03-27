//==================================================================================================
/*!
  @file

  Defines the STF_STRING macro

  @copyright 2017 NumScale


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_COMMON_STRING_HPP_INCLUDED
#define STF_COMMON_STRING_HPP_INCLUDED

#define STF_STRING__(...) #__VA_ARGS__
#define STF_STRING_(text) STF_STRING__ text

/*!
  @ingroup group-common

  Turn a variadic macro calls into a string containing properly placed commas.
**/
#define STF_STRING(...) STF_STRING_((__VA_ARGS__))

#endif
