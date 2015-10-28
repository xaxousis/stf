//==================================================================================================
/*!
  @file

  Redefine BOOST_ASSERT related macros to be able to catch them in tests.

  @copyright 2015 Joel Falcou


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_UNIT_DETAIL_ASSERTION_FAILURE_HPP_INCLUDED
#define STF_UNIT_DETAIL_ASSERTION_FAILURE_HPP_INCLUDED

#if !defined(BOOST_ENABLE_ASSERT_HANDLER)
#error BOOST_ENABLE_ASSERT_HANDLER must be defined to use STF_ASSERT() macro
#endif

#include <stf/common/location.hpp>
#include <boost/assert.hpp>
#include <sstream>
#include <memory>
#include <string>

namespace stf { namespace detail
{
  inline std::unique_ptr<std::string>& current_assertion()
  {
    static std::unique_ptr<std::string> ptr;
    return ptr;
  }
} }

namespace boost
{
  // Define a BOOST_ASSERT handler for STF
  inline void assertion_failed( char const* expr, char const* fn, char const* f, long l )
  {
    std::ostringstream os;
    os  << "Assertion    '"  << expr << "' failed\n"
        << " in function '"  << fn << "'\n"
        << " from         "  << ::stf::at(f,l)    << " \n";

    stf::detail::current_assertion().reset( new std::string(os.str()) ) ;
  }

  // Define a BOOST_ASSERT_MSG handler for STF
  inline void assertion_failed_msg( char const* expr, char const* msg
                                  , char const* fn, char const* f, long l
                                  )
  {
    std::ostringstream os;
    os  << "Assertion    '"  << expr << "' failed\n"
        << " in function '"  << fn << "'\n"
        << " from         "  << ::stf::at(f,l)    << " \n"
        << " because:     "  << msg  << " \n";

    stf::detail::current_assertion().reset( new std::string(os.str()) ) ;
  }
}

#endif
