//==================================================================================================
/*!
  @file

  Defines the absolute error testing related helpers

  @copyright 2017 NumScale


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_UNIT_DETAIL_ABSOLUTE_HPP_INCLUDED
#define STF_UNIT_DETAIL_ABSOLUTE_HPP_INCLUDED

#include <stf/unit/detail/approx.hpp>
#include <stf/unit/detail/absdist.hpp>
#include <string>

namespace stf
{
  namespace detail
  {
    struct absolute_measure
    {
      template<typename T, typename U>
      double operator()(T const& data, U const& ref) const
      {
        return ::stf::absdist(data,ref);
      }

      template<typename Stream> static void to_stream(Stream& s, double v)
      {
        s.precision(5);
        s << " (" <<  v << ")\n";
      }
    };
  }

  // Perform absolute distance computation and report
  template<typename R> using absolute_ = approx_<detail::absolute_measure, R>;

  // Simple absolute_ constructor like call
  template<typename R> inline absolute_<R> absolute(R const& t, double n) { return {t,n}; }
}

#endif
