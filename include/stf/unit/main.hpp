//==================================================================================================
/*!
  @file

  Defines the automatic entry-point for all test cases

  @copyright 2015 Joel Falcou


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_UNIT_MAIN_HPP_INCLUDED
#define STF_UNIT_MAIN_HPP_INCLUDED

#if !defined(STF_CUSTOM_DRIVER_FUNCTION)
#define STF_CUSTOM_DRIVER_FUNCTION main
#endif

#if defined(DOXYGEN_ONLY)
/*!
  @ingroup group-common
  @brief Test application entry-point customization

  In some scenario, one may need to run tests from a function not called main.
  Redefining STF_CUSTOM_DRIVER_FUNCTION to any valid symbol name will generate a
  custom function callable from an already existing @c main function
**/
#define STF_CUSTOM_DRIVER_FUNCTION
#endif

#if !defined(STF_USE_CUSTOM_DRIVER)
int STF_CUSTOM_DRIVER_FUNCTION(int argc, const char** argv)
{
  ::stf::unit::env runtime(argc,argv,std::cout);
  return ::stf::run( runtime, ::stf::unit::suite(), 0, 0 );
}
#endif

#endif
