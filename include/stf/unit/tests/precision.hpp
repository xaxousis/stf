//==================================================================================================
/*!
  @file

  Defines test macros for precision tests

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
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

  Evaluates @c A and @c B and checks if their respective value(s) are withing @c X ULPs of
  each other. This test is performed by calling the default @c stf::ulpdist function or any
  ADL-accessible overload on each values from @c A and @c B.

  @par Example:

  @snippet test/unit/ulp.cpp ulp

  @param A First expression to compare
  @param B Second expression to compare
  @param X ULP distance threshold
**/
#define STF_ULP_EQUAL(A,B,X)                                                                        \
do                                                                                                  \
{                                                                                                   \
  auto stf_local_r = STF_DECOMPOSE((A) == ::stf::ulp(B,X));                                                   \
  if( stf_local_r )                                                                                           \
    STF_PASS ( "Expecting: " << ::stf::white_(STF_STRING(A) " == " STF_STRING(B))                   \
                                << " within " << ::stf::white_(X) << " ULPs."                       \
                );                                                                                  \
  else                                                                                              \
    STF_FAIL ( "Expecting: " << ::stf::white_(STF_STRING(A) " == " STF_STRING(B))                   \
                                << " within " << ::stf::white_(X) << " ULPs "                       \
                                << "but found:\n" << ::stf::white_(stf_local_r.rhs)                           \
                );                                                                                  \
} while( ::stf::is_false() )                                                                        \
/**/


/*!
  @ingroup group-unit

  @brief Check for equality within IEEE rules

  Evaluates @c A and @c B and checks if their respective value(s) are equal at 0 ULPs or
  are both NaNs. This test is performed by calling the default @c stf::ulpdist function or any
  ADL-accessible overload on each values from @c A and @c B.

  @par Example:

  @snippet test/unit/ulp.cpp ieee

  @param A First expression to compare
  @param B Second expression to compare
**/
#define STF_IEEE_EQUAL(A,B)  STF_ULP_EQUAL(A,B,0.)

/*!
  @ingroup group-unit

  @brief Check for equality within a relative distance

  Evaluates @c A and @c B and checks if their respective value(s) are within a relative tolerance
  of @c X percent of each other. This test is performed by calling the default @c stf::reldist
  function or any ADL-accessible overload on each values from @c A and @c B.

  @par Example:

  @snippet test/unit/relative.cpp relative

  @param A First expression to compare
  @param B Second expression to compare
  @param X Relative tolerance
**/
#define STF_RELATIVE_EQUAL(A,B,X)                                                                   \
do                                                                                                  \
{                                                                                                   \
  auto stf_local_r = STF_DECOMPOSE((A) == ::stf::relative(B,X));                                    \
  if( stf_local_r )                                                                                 \
    STF_PASS ( "Expecting: " << ::stf::white_(STF_STRING(A) " == " STF_STRING(B))                   \
                                << " within " << ::stf::white_(X) << " %."                          \
                );                                                                                  \
  else                                                                                              \
    STF_FAIL ( "Expecting: " << ::stf::white_(STF_STRING(A) " == " STF_STRING(B))                   \
                                << " within " << ::stf::white_(X) << " % "                          \
                                << "but found:\n" << ::stf::white_(stf_local_r.rhs)                 \
                );                                                                                  \
} while( ::stf::is_false() )                                                                        \
/**/

#endif
