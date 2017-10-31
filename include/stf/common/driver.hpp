//==================================================================================================
/*!
  @file

  Defines macros for building a custom test driver

  @copyright 2017 NumScale


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_COMMON_DRIVER_HPP_INCLUDED
#define STF_COMMON_DRIVER_HPP_INCLUDED

#include <stf/common/args.hpp>
#include <stf/common/values.hpp>
#include <stf/common/detail/shuffle.hpp>
#include <algorithm>
#include <random>

namespace stf
{
  /*!
    @ingroup group-common

    @brief Starts the execution of a group of function object.

    Starts the execution of every functions registered as a test suite of any kind and report
    success or failure with respect to the expectation of said test semantic.

    Usually, the test suite being run is given by stf::test_suite() but it can
    differs in some use case, hence the need to pass it as a parameter.

    @par Example:
    @snippet example/unit/case.cpp driver

    @param environment  Test environment
    @param tests        Test suite to execute
    @param setup        Additional, test kind specific, parameters

    @return A boolean value indicating if the whole test is considered a success.
  **/
  template<typename Environment, typename Suite, typename... Setup>
  inline bool run(Environment& environment, Suite& tests, Setup const&... setup)
  {
    // retrieve compact status
    auto is_compact = args("compact",false);
    auto is_fail_only = args("fail-only",false);
    environment.compact(is_compact);
    environment.fail_only(is_fail_only);

    // randomize test on non-null random seed option
    if(auto seed = args("random",0u))
    {
      ::stf::detail::shuffle( tests.begin(), tests.end(), std::mt19937{seed} );
    }

    for(auto& t : tests )
    {
      scenario_header(environment,t);
      auto count = environment.tests();

      t(environment);

      process_invalid(environment, count);

      environment.stream() << std::endl;
    }

    return ::stf::report(environment,setup...);
  }
}

#endif
