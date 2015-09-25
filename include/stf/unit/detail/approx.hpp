//==================================================================================================
/*!
  @file

  Defines the approximate testing related helpers

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 Joel Falcou


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_UNIT_DETAIL_APPROX_HPP_INCLUDED
#define STF_UNIT_DETAIL_APPROX_HPP_INCLUDED

#include <vector>
#include <string>

namespace stf
{
  // Provides the basic services to perform approximate distance computation and report
  template<typename Measure, typename Reference> struct approx_
  {
    approx_(Reference const& r, double u) : ref(r), diff(u), size_mismatch(false), max_diff(u) {}

    template<typename U> inline bool compare(U const& data) const
    {
      Measure m;
      size_mismatch = detail::size(ref) != detail::size(data);
      if(size_mismatch) return false;

      auto dist = m(data,ref);

      auto br = detail::begin(data);
      auto bi = detail::begin(ref);
      auto bd = detail::begin(dist);
      auto sz = detail::size(data);

      for(std::size_t idx=0;idx < sz; ++idx)
        check( *bd++, *br++, *bi++, (sz>1 ? idx : -1) );

      return errors.size() == 0;
    }

    struct error
    {
      double          value;
      std::string     ref,data;
      std::ptrdiff_t  idx;
    };

    bool                      mismatched()  const { return size_mismatch; }
    double                    max()         const { return max_diff;      }
    std::vector<error> const& report()      const { return errors;        }

    private:

    template<typename U, typename X, typename Y>
    inline void check(U const&  u, X const& x, Y const& y, std::ptrdiff_t idx) const
    {
      using stf::to_string;

      if( u  > diff )
      {
        errors.push_back( {u, to_string(x),to_string(y), idx} );
        max_diff = std::max(max_diff,u);
      }
    }

    Reference                   ref;
    double                      diff;
    mutable bool                size_mismatch;
    mutable double              max_diff;
    mutable std::vector<error>  errors;
  };

  // Streaming approx_ builds the report
  template<typename Measure, typename Reference>
  std::string to_string( approx_<Measure,Reference> const& u )
  {
    using stf::to_string;

    if(u.mismatched()) return "arguments with mismatched size.";

    std::ostringstream s,ls;

    // Stream all errors
    ls.precision(20);

    for(auto const& e : u.report())
    {
      (e.idx >= 0) ? ls << "  [" << e.idx << "]: " : ls << "  ";
      ls << to_string(e.ref) << " vs " << to_string(e.data);
      Measure::to_stream(ls,e.value);
    }

    // Stream max error
    s.precision(20);
    Measure::to_stream(s,u.max());

    return "{\n"  + ls.str() + "}\n with a maximal error of " + s.str();
  }

  // ADL compare_equal for approx_
  template<typename Measure, typename Reference, typename U>
  inline bool isequaln(U const& l, approx_<Measure, Reference> const& r)
  {
    return r.compare(l);
  }
}

#endif
