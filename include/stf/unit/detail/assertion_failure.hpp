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

#include <boost/config.hpp>
#if defined(BOOST_NO_EXCEPTIONS)
#error Exceptions must be enabled to  use STF_ASSERT() macro
#endif

#include <stf/common/location.hpp>
#include <boost/core/ignore_unused.hpp>
#include <boost/throw_exception.hpp>
#include <boost/exception/all.hpp>
#include <boost/assert.hpp>

namespace stf { namespace detail
{
  /*!
    @brief Runtime assertion exception

    assertion_failure is thrown when a runtime assertion triggers while a test case is being run.
  **/
  struct BOOST_SYMBOL_VISIBLE assertion_failure : virtual boost::exception, std::runtime_error
  {
    /// Builds an assert_exception from the actual runtime assertion message
    inline assertion_failure(std::string const& msg) : boost::exception() , std::runtime_error(msg)
    {}
  };

  /// Boost.Exception mark-up for carrying assertion message
  using throw_message = boost::error_info<struct tag_throw_msg,char const*>;

  inline std::ostream& operator<<(std::ostream& os, assertion_failure const& e)
  {
    auto fn   = boost::get_error_info< ::boost::throw_function >(e);
    auto f    = boost::get_error_info< ::boost::throw_file >(e);
    auto l    = boost::get_error_info< ::boost::throw_line >(e);
    auto msg  = boost::get_error_info< ::stf::detail::throw_message >(e);

    os  << "Assertion    '"  << e.what() << "' failed\n"
        << " in function '"  << *fn << "'\n"
        << " from         "  << ::stf::at(*f,*l)    << " \n";

    if(msg)  os << " because     '"  << *msg << "'";

    return os;
  }
} }

namespace boost
{
  // Define a BOOST_ASSERT handler for STF
  inline void assertion_failed( char const* expr, char const* fn, char const* f, long l )
  {
    #ifndef BOOST_EXCEPTION_DISABLE
    ::boost::throw_exception
    (     ::boost::enable_error_info( ::stf::detail::assertion_failure(expr) )
      <<  ::boost::throw_function(fn)
      <<  ::boost::throw_file(f)
      <<  ::boost::throw_line(int(l))
    );
    #else
    ::boost::ignore_unused(fn,f,l);
    ::boost::throw_exception( ::stf::detail::assertion_failure(expr) );
    #endif
  }

  // Define a BOOST_ASSERT_MSG handler for STF
  inline void assertion_failed_msg( char const* expr, char const* msg
                                  , char const* fn, char const* f, long l
                                  )
  {
    #ifndef BOOST_EXCEPTION_DISABLE
    ::boost::throw_exception
    (     ::boost::enable_error_info( ::stf::detail::assertion_failure(expr) )
      <<  ::boost::throw_function(fn)
      <<  ::boost::throw_file(f)
      <<  ::boost::throw_line(int(l))
      <<  ::stf::detail::throw_message(msg)
    );
    #else
    ::boost::ignore_unused(expr,fn,f,l);
    ::boost::throw_exception( ::stf::detail::assertion_failure(msg) );
    #endif
  }
}

#endif
