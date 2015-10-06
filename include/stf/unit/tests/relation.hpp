//==================================================================================================
/*!
  @file

  Defines test macros for logical relations

  @copyright 2015 Joel Falcou


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_UNIT_TESTS_RELATION_HPP_INCLUDED
#define STF_UNIT_TESTS_RELATION_HPP_INCLUDED

#include <stf/unit/tests/basic.hpp>

/*!
  @ingroup group-unit
  Test for value equality.

  This macro performs an equality test between its arguments using either the natural @c == operator
  or an ADL-accessible function named @c isequaln , whichever occurs first.

  @par Usage:

  @snippet test/unit/relation.cpp equal

  where @c foo::bar is defined as follow:

  @snippet test/unit/relation.cpp bar

  @param A First argument of the test
  @param B Second argument of the test
**/
#define STF_EQUAL( A, B )      STF_EXPECT( (A) == (B) )

/*!
  @ingroup group-unit
  Test for value inequality.

  This macro performs an inequality test between its arguments using either the natural
  @c != operator or an ADL-accessible function named @c compare_not_equal, whichever occurs first.

  @par Usage:

  @snippet test/unit/relation.cpp not_equal

  where @c foo::bar is defined as follow:

  @snippet test/unit/relation.cpp bar

  @param A First argument of the test
  @param B Second argument of the test
**/
#define STF_NOT_EQUAL( A, B )  STF_EXPECT( (A) != (B) )

/*!
  @ingroup group-unit
  Test for value less-than relationship.

  This macro performs a less-than test between its arguments using either the natural @c < operator
  or an ADL-accessible function named @c compare_less , whichever occurs first.

  @par Usage:

  @snippet test/unit/relation.cpp less

  where @c foo::bar is defined as follow:

  @snippet test/unit/relation.cpp bar

  @param A First argument of the test
  @param B Second argument of the test
**/
#define STF_LESS(A,B)        STF_EXPECT( (A) < (B) )

/*!
  @ingroup group-unit
  Test for value greater-than relationship.

  This macro performs a greater-than test between its arguments using either the natural
  @c > operator or an ADL-accessible function named @c compare_greater, whichever occurs first.

  @par Usage:

  @snippet test/unit/relation.cpp greater

  where @c foo::bar is defined as follow:

  @snippet test/unit/relation.cpp bar

  @param A First argument of the test
  @param B Second argument of the test
**/
#define STF_GREATER(A,B)       STF_EXPECT( (A) > (B) )

/*!
  @ingroup group-unit
  Test for value lesser-or-equal-than relationship.

  This macro performs a lesser-or-equal-than test between its arguments using either the natural
  @c <= operator or an ADL-accessible function named @c compare_less_equal, whichever occurs first.

  @par Usage:

  @snippet test/unit/relation.cpp less_equal

  where @c foo::bar is defined as follow:

  @snippet test/unit/relation.cpp bar

  @param A First argument of the test
  @param B Second argument of the test
**/
#define STF_LESS_EQUAL(A,B)  STF_EXPECT( (A) <= (B) )

/*!
  @ingroup group-unit
  Test for value greater-or-equal-than relationship.

  This macro performs a greater-or-equal-than test between its arguments using either the natural
  @c >= operator or an ADL-accessible function named @c compare_greater_equal, whichever occurs first.

  @par Usage:

  @snippet test/unit/relation.cpp greater_equal

  where @c foo::bar is defined as follow:

  @snippet test/unit/relation.cpp bar

  @param A First argument of the test
  @param B Second argument of the test
**/
#define STF_GREATER_EQUAL(A,B) STF_EXPECT( (A) >= (B) )

#endif
