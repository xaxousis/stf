//==================================================================================================
/*
  Copyright 2017 NumScale

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/
//==================================================================================================
#include <stf/unit/unit.hpp>
#include <stf/unit/tests/basic.hpp>

STF_CASE( "Check that forced pass passes" )
{
//! [pass]
  STF_PASS("Forced pass");
//! [pass]

//! [info]
  STF_INFO("This is an info");
//! [info]

//! [warn]
  STF_WARNING("This is a warning");
//! [warn]

//! [error]
  STF_ERROR("This is an error");
//! [error]
}

