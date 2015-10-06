//==================================================================================================
/*
  Copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/
//==================================================================================================
#include <stf/unit/unit.hpp>
#include <stf/unit/tests/exceptions.hpp>

//! [assert_foo]
void foo(int x)
{
  BOOST_ASSERT_MSG( x != 0, "x must be non-null" );
}
//! [assert_foo]

void bar(int x)
{
  BOOST_ASSERT( x != 0 );
}

//! [assert]
STF_CASE( "Check that we can capture assertion failure" )
{
  STF_ASSERT( foo(0) );
  STF_ASSERT( bar(0) );
}
//! [assert]

//! [no_assert]
STF_CASE( "Check that we can check if function don't trigger any assert" )
{
  STF_NO_ASSERT( foo(42) );
  STF_NO_ASSERT( bar(42) );
}
//! [no_assert]
