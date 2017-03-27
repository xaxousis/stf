//==================================================================================================
/*!
  @file

  Defines the stf::test data structure and related functions

  @copyright 2017 NumScale


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_UNIT_TEST_HPP_INCLUDED
#define STF_UNIT_TEST_HPP_INCLUDED

#include <vector>
#include <functional>
#include <stf/unit/env.hpp>

namespace stf { namespace unit
{
  /*!
    @brief Test case wrapper class
    @ingroup group-unit

    The stf::test data-structure is used to store :
      - a `std::function` instance wrapping the actual test code
      - a `std::string` containing the test case description

    Those data are later used for display and execution of said test case.
  **/
  struct test
  {
    using behavior_t = std::function<void( env& )>;

    std::string name;
    behavior_t  behaviour;

    test( std::string const& n, behavior_t const& b ) : name( n ), behaviour( b ) {}

    /// Trigger current test execution
    void operator()(env& e) { behaviour(e); }
  };

   /*!
    @brief Type defining the test suite container
    @ingroup group-unit
  **/
  using test_suite = std::vector<test>;

  /*!
    @brief Global test suite accessor
    @ingroup group-unit

    Return a reference to the global tests suite container where instances of stf::test are
    stored before being executed by a test driver.

    @return A non-const reference to the tests suite instance
  **/
  static inline test_suite& suite()
  {
    static test_suite tests;
    return tests;
  }
} }

#endif
