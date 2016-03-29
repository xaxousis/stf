//==================================================================================================
/*!
  @file

  Defines test macros for precision tests

  @copyright 2015 Joel Falcou


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_UNIT_TESTS_PRECISION_HPP_INCLUDED
#define STF_UNIT_TESTS_PRECISION_HPP_INCLUDED

#include <stf/unit/detail/ulp.hpp>
#include <stf/unit/detail/relative.hpp>
#include <stf/unit/detail/decompose.hpp>
#include <stf/unit/tests/basic.hpp>

/*!
  @ingroup group-unit

  @brief Check for equality within ULP distance

  Evaluates @c A and @c B and checks if their respective value are withing @c X ULPs of
  each other.

  @par Example:

  @snippet test/unit/ulp.cpp ulp

  @param A First expression to compare
  @param B Second expression to compare
  @param X ULP distance threshold
**/
#define STF_ULP_EQUAL(A,B,X)                                                                        \
do                                                                                                  \
{                                                                                                   \
  auto stf_local_r = ::stf::ulpdist((A),(B));                                                       \
  if( stf_local_r <= (X) )                                                                          \
    STF_PASS( "Expecting: " << STF_STRING(A) " == " STF_STRING(B) << " within " << X << " ULPs." ); \
  else                                                                                              \
    STF_FAIL( "Expecting: " << STF_STRING(A) " == " STF_STRING(B)                                   \
                             << " within " << X << " ULPs " << "but found:\n" << stf_local_r        \
            );                                                                                      \
} while( ::stf::is_false() )                                                                        \
/**/

/*!
  @ingroup group-unit

  @brief Check for equality within IEEE rules

  Evaluates @c A and @c B and checks if their respective value(s) are equal at 0 ULPs or
  are both NaNs.

  @par Example:

  @snippet test/unit/ulp.cpp ieee

  @param A First expression to compare
  @param B Second expression to compare
**/
#define STF_IEEE_EQUAL(A,B)  STF_ULP_EQUAL(A,B,0.)


/*!
  @ingroup group-unit

  @brief Check for equality within ULP distance in ranges

  Evaluates @c A and @c B and checks if their respective contents are withing @c X ULPs of
  each other. If @c A or @c B are single values, the other must be a container of size 1.

  @par Example:

  @snippet test/unit/all_ulp.cpp all_ulp

  @param A First range expression to compare
  @param B Second range expression to compare
  @param X ULP distance threshold
**/
#define STF_ALL_ULP_EQUAL(A,B,X)                                                                    \
do                                                                                                  \
{                                                                                                   \
  auto stf_local_r = STF_DECOMPOSE((A) == ::stf::ulp(B,X));                                         \
  if( stf_local_r )                                                                                 \
    STF_PASS( "Expecting: " << STF_STRING(A) " == " STF_STRING(B) << " within " << X << " ULPs." ); \
  else                                                                                              \
    STF_FAIL( "Expecting: " << STF_STRING(A) " == " STF_STRING(B)                                   \
                             << " within " << X << " ULPs " << "but found:\n" << stf_local_r.rhs    \
            );                                                                                      \
} while( ::stf::is_false() )                                                                        \
/**/

/*!
  @ingroup group-unit

  @brief Check for equality within IEEE rules in ranges

  Evaluates @c A and @c B and checks if their respective contents are equal at 0 ULPs or
  are both NaNs. If @c A or @c B are single values, the other must be a container of size 1.

  @par Example:

  @snippet test/unit/ulp.cpp ieee

  @param A First range expression to compare
  @param B Second range expression to compare
**/
#define STF_ALL_IEEE_EQUAL(A,B)  STF_ALL_ULP_EQUAL(A,B,0.)

/*!
  @ingroup group-unit

  @brief Check for equality within a relative distance

  Evaluates @c A and @c B and checks if their respective value(s) are within a relative tolerance
  of @c X percent of each other.

  @par Example:

  @snippet test/unit/relative.cpp relative

  @param A First expression to compare
  @param B Second expression to compare
  @param X Relative tolerance
**/
#define STF_RELATIVE_EQUAL(A,B,X)                                                                   \
do                                                                                                  \
{                                                                                                   \
  auto stf_local_r = ::stf::reldist((A),(B));                                                       \
  if( stf_local_r <= (X/100.))                                                                      \
    STF_PASS( "Expecting: " << STF_STRING(A) " == " STF_STRING(B) << " within " << X << " %.");     \
  else                                                                                              \
    STF_FAIL( "Expecting: " << STF_STRING(A) " == " STF_STRING(B)                                   \
                            << " within " << X << " % "                                             \
                            << "but found:\n" << stf_local_r                                        \
            );                                                                                      \
} while( ::stf::is_false() )                                                                        \
/**/

/*!
  @ingroup group-unit

  @brief Check for equality within a relative distance in ranges

  Evaluates @c A and @c B and checks if their respective contents are within a relative tolerance
  of @c X percent of each other. If @c A or @c B are single values, the other must be a container
  of size 1.

  @par Example:

  @snippet test/unit/all_relative.cpp all_relative

  @param A First expression to compare
  @param B Second expression to compare
  @param X Relative tolerance
**/
#define STF_ALL_RELATIVE_EQUAL(A,B,X)                                                               \
do                                                                                                  \
{                                                                                                   \
  auto stf_local_r = STF_DECOMPOSE((A) == ::stf::relative(B,X));                                    \
  if( stf_local_r )                                                                                 \
    STF_PASS( "Expecting: " << STF_STRING(A) " == " STF_STRING(B) << " within " << X << " %.");     \
  else                                                                                              \
    STF_FAIL( "Expecting: " << STF_STRING(A) " == " STF_STRING(B)                                   \
                            << " within " << X << " % "                                             \
                            << "but found:\n" << stf_local_r.rhs                                    \
            );                                                                                      \
} while( ::stf::is_false() )                                                                        \
/**/

#endif
