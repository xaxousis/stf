//==================================================================================================
/*
  Copyright 2017 NumScale

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/
//==================================================================================================
#include <stf/unit/unit.hpp>
#include <stf/unit/tests/exceptions.hpp>

struct some_exception_type {};

//! [throwing_foo]
void foo(bool x)
{
  if(x)
    throw some_exception_type();
}
//! [throwing_foo]

//! [throw]
STF_CASE( "Check that we can capture thrown exceptions" )
{
  STF_THROW( foo(true), some_exception_type );
}
//! [throw]

//! [no_throw]
STF_CASE( "Check that nothrow function are detected as such" )
{
  STF_NO_THROW( foo(false) );
}
//! [no_throw]
