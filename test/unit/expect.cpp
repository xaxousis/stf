//==================================================================================================
/*
  Copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/
//==================================================================================================
#include <stf/unit/unit.hpp>
#include <stf/unit/tests/basic.hpp>

//! [expect]
STF_CASE( "Check that expectation can be met" )
{
  int a = 42, b = 69;

  STF_EXPECT(a != b);
  STF_EXPECT(a <  b);
  STF_EXPECT(a <= b);
  STF_EXPECT(b >  a);
  STF_EXPECT(b >= a);
}
//! [expect]

//! [expect_not]
STF_CASE( "Check that counter-expectation can be met" )
{
  int a = 42, b = 69;

  STF_EXPECT_NOT(a == b);
  STF_EXPECT_NOT(a >  b);
  STF_EXPECT_NOT(a >= b);
  STF_EXPECT_NOT(b <  a);
  STF_EXPECT_NOT(b <= a);
}
//! [expect_not]
