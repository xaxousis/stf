//==================================================================================================
/*
  Copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/
//==================================================================================================
#define STF_USE_CUSTOM_DRIVER
#include <stf/unit/unit.hpp>

STF_CASE( "Check detection of invalid test" )        {}
STF_CASE( "Check detection of more invalid tests" )  {}

int main(int argc, const char** argv)
{
  ::stf::unit::env runtime(argc,argv,std::cout);
  return ::stf::run( runtime, ::stf::unit::suite(), 0, 2 );
}
