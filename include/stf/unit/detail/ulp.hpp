//==================================================================================================
/*!
  @file

  Defines the ULP related helpers

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 Joel Falcou


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_UNIT_DETAIL_ULP_HPP_INCLUDED
#define STF_UNIT_DETAIL_ULP_HPP_INCLUDED

#include <stf/unit/detail/approx.hpp>
#include <stf/unit/detail/ulpdist.hpp>
#include <string>

namespace stf
{
  namespace detail
  {
    struct ulp_measure
    {
      template<typename T, typename U>
      auto operator()(T const& data, U const& ref) const -> decltype(ulpdist(data,ref))
      {
        using stf::ulpdist;
        return ulpdist(data,ref);
      }

      template<typename Stream> static void to_stream(Stream& s, double v)
      {
        s << " (" << v << " ULPs)\n";
      }
    };
  }
  // Perform ULP distance computation and report
  template<typename R> using ulp_ = approx_<detail::ulp_measure, R>;

  // Simple ulp_ constructor like call
  template<typename R> inline ulp_<R> ulp(R const& t, double n) { return {t,n}; }
}

#endif
