//==================================================================================================
/*!
  @file

  Defines basic test macros.

  @copyright 2015 Joel Falcou


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_UNIT_TESTS_BASIC_HPP_INCLUDED
#define STF_UNIT_TESTS_BASIC_HPP_INCLUDED

#include <stf/common/values.hpp>
#include <stf/unit/tests/infos.hpp>
#include <stf/unit/detail/decompose.hpp>

/*!
  @ingroup group-unit
  Test if a boolean expression @c EXPR evaluates to @c true.

  @par Usage:

  @snippet test/unit/expect.cpp expect

  @param EXPR Boolean expression to test
**/
#define STF_EXPECT( EXPR )                                                                          \
do                                                                                                  \
{                                                                                                   \
  if( ::stf::detail::result stf_local_r = STF_DECOMPOSE(EXPR) )                                     \
    STF_PASS( "Expecting: " << STF_STRING(EXPR));                                                   \
  else                                                                                              \
  {                                                                                                 \
    STF_FAIL( "Expecting: " << STF_STRING(EXPR));                                                   \
    if(!runtime.is_compact()) STF_DUMP( stf_local_r );                                                    \
  }                                                                                                 \
} while( ::stf::is_false() )                                                                        \
/**/

/*!
  @ingroup group-unit
  Test if a boolean expression @c EXPR evaluates to @c false.

  @par Usage:

  @snippet test/unit/expect.cpp expect_not

  @param EXPR Boolean expression to test
**/
#define STF_EXPECT_NOT( EXPR )                                                                      \
do                                                                                                  \
{                                                                                                   \
  if( ::stf::detail::result stf_local_r = STF_DECOMPOSE(EXPR) )                                     \
  {                                                                                                 \
    STF_FAIL( "Not expecting: " << STF_STRING(EXPR));                                               \
    if(!runtime.is_compact()) STF_DUMP( stf_local_r );                                                    \
  }                                                                                                 \
  else                                                                                              \
    STF_PASS( "Not expecting: " << STF_STRING(EXPR));                                               \
} while( ::stf::is_false() )                                                                        \
/**/

#endif
