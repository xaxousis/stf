//==================================================================================================
/*
  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/
//==================================================================================================
#define STF_USE_CUSTOM_DRIVER
#include <stf/unit/unit.hpp>
#include <stf/unit/tests/basic.hpp>

//! [fail]
STF_CASE( "Check that forced failure fails" )
{
  STF_FAIL("Forced fail");
}
//! [fail]

STF_CASE( "Check that forced broken expectation fails" )
{
  STF_EXPECT(false == true);
  STF_EXPECT_NOT(true == true);
}

int main(int argc, const char** argv)
{
  ::stf::unit::env $env(argc,argv,std::cout);
  return ::stf::run( $env, ::stf::unit::suite(), 3, 0 );
}
