//==================================================================================================
/*!
  @file

  Defines the relative error testing related helpers

  @copyright 2017 NumScale


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_UNIT_DETAIL_RELATIVE_HPP_INCLUDED
#define STF_UNIT_DETAIL_RELATIVE_HPP_INCLUDED

#include <stf/unit/detail/approx.hpp>
#include <stf/unit/detail/reldist.hpp>
#include <string>

namespace stf
{
  namespace detail
  {
    struct relative_measure
    {
      template<typename T, typename U>
      double operator()(T const& data, U const& ref) const
      {
        return ::stf::reldist(data,ref);
      }

      template<typename Stream> static void to_stream(Stream& s, double v)
      {
        s.precision(2);
        s << " (" << std::fixed << v*100. << " %)\n";
      }
    };
  }

  // Perform relative distance computation and report
  template<typename R> using relative_ = approx_<detail::relative_measure, R>;

  // Simple relative_ constructor like call
  template<typename R> inline relative_<R> relative(R const& t, double n) { return {t,n/100.}; }
}

#endif
