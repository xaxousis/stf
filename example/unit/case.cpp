//==================================================================================================
/*!
  @copyright 2015 Joel Falcou


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
//! [custom_driver_macro]
#define STF_USE_CUSTOM_DRIVER
#include <stf/unit.hpp>
//! [custom_driver_macro]

#include <list>
#include <vector>
#include <iostream>

//! [case]
STF_CASE( "A passing test" )
{
  STF_PASS("Forced pass 1.");
}
//! [case]

//! [fail_case]
STF_CASE( "An empty test will fail" )
{

}
//! [fail_case]

//! [case_tpl]
STF_CASE_TPL( "A template test", (float)(int) )
{
  STF_PASS("Forced pass of " << sizeof(T) << " bytes.");
}
//! [case_tpl]

//! [driver]
int main(int argc, char** argv)
{
  ::stf::env runtime(std::cout);

  // Test specific setup goes here

  auto result = ::stf::run( runtime, ::stf::suite(), {0,0} );

  // Test specific clean-up goes here

  return result;
}
//! [driver]
