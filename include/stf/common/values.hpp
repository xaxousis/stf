//==================================================================================================
/*!
  @file

  Defines the is_false and is_true functions

  @copyright 2015 Joel Falcou


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_COMMON_VALUES_HPP_INCLUDED
#define STF_COMMON_VALUES_HPP_INCLUDED

namespace stf
{
  /*!
    @ingroup group-common
    Return the constant @c false
  **/
  inline bool is_false()  { return false; }

  /*!
    @ingroup group-common
    Return the constant @c true
  **/
  inline bool is_true()   { return true; }
}

#endif
