//==================================================================================================
/*!
  @file

  Defines test macros for test on exceptions and assertions trigger

  @copyright 2015 Joel Falcou


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_UNIT_TESTS_EXCEPTIONS_HPP_INCLUDED
#define STF_UNIT_TESTS_EXCEPTIONS_HPP_INCLUDED

#include <stf/common/warning.hpp>
#include <stf/unit/tests/basic.hpp>
#include <boost/preprocessor/punctuation/remove_parens.hpp>

/*!
  @ingroup group-unit
  Test if an expression @c X throws an exception of type @c T.

  @par Usage:

  @snippet test/unit/exceptions.cpp throw

  where @c foo is defined as :

  @snippet test/unit/exceptions.cpp throwing_foo

  @param X Expression to test
  @param T Exception type expected to be thrown
**/
#define STF_THROW( X, T )                                                                           \
do                                                                                                  \
{                                                                                                   \
  bool caught = false;                                                                              \
  try                                 { STF_UNUSED(BOOST_PP_REMOVE_PARENS(X)); }                    \
  catch( BOOST_PP_REMOVE_PARENS(T)& ) { caught = true; }                                            \
                                                                                                    \
  if(caught)                                                                                        \
    STF_PASS( STF_STRING(X) <<  " throws " <<  STF_STRING(T) );                                     \
  else                                                                                              \
    STF_FAIL( STF_STRING(X) <<  " does not throw " <<  STF_STRING(T) );                             \
} while( ::stf::is_false() )                                                                        \
/**/

/*!
  @ingroup group-unit
  Test if an expression @c X does not throw any exception.

  @par Usage:

  @snippet test/unit/exceptions.cpp no_throw

  where @c foo is defined as :

  @snippet test/unit/exceptions.cpp throwing_foo

  @param X Expression to test
**/
#define STF_NO_THROW( X )                                                                           \
do                                                                                                  \
{                                                                                                   \
  bool caught = false;                                                                              \
  try          { STF_UNUSED(BOOST_PP_REMOVE_PARENS(X)); }                                           \
  catch( ... ) { caught = true; }                                                                   \
                                                                                                    \
  if(caught)                                                                                        \
    STF_FAIL( STF_STRING(X) << " throws while not expected to" );                                   \
  else                                                                                              \
    STF_PASS( STF_STRING(X) << " doesn't throw" );                                                  \
} while( ::stf::is_false() )                                                                        \
/**/

#endif
