//==================================================================================================
/*!
  @file

  Defines the basic reldist function

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 Joel Falcou


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_UNIT_DETAIL_RELDIST_HPP_INCLUDED
#define STF_UNIT_DETAIL_RELDIST_HPP_INCLUDED

#include <stf/common/detail/is_container.hpp>
#include <algorithm>
#include <iterator>
#include <cmath>

namespace stf
{
#if defined(DOXYGEN_ONLY)
  /*!
    @ingroup group-details

    @brief Relative distance between values

    Computes the relative distance between two values.

    @par Semantic:

    For any types @c T and @c U, any value @c a0 of type @c T and any value @c a1 of type @c U:

    @code
    auto r = reldist(a0,a1);
    @endcode

    is equivalent to:

    @code
    auto r = reldist( static_cast<std::common_t<T,U>>(a0), static_cast<std::common_t<T,U>>(a1));
    @endcode

    For any type @c T and any value of type @c T @c a0 and @c a1, then:

    @code
    auto r = reldist(a0,a1);
    @endcode

    is equivalent to:

    - if @c T is @c bool :
      @code
      auto r = a0==a1 ? 0. : 1.;
      @endcode

    - if @c T is a Container, @c r is a container containing the ULP distance between each pair of
    elements in @c a0 and @c a1

    @param a0 First value to compare
    @param a1 Second value to compare
    @return The relative distance between a0 and a1
  **/
  template<typename T, typename U> inline auto reldist(T a0, U a1);
#else

#endif

  inline double reldist(bool a0, bool a1) { return a0 == a1 ? 0. : 1.; }

  template<typename T,typename U> using dependent = U;

  template<typename T>
  inline detail::if_integral<T,double> reldist(T const& a0, T const& a1)
  {
    dependent<T,double> d0 = static_cast<double>(a0), d1 = static_cast<double>(a1);
    return reldist(d0,d1);
  }

  template<typename T>
  inline detail::if_real<T,double> reldist(T const& a0, T const& a1)
  {
    if( (a0 == a1) || ((a0!=a0) && (a1!=a1)) )  return 0.;
    if( (a0!=a0) || (a1!=a1) )                  return std::numeric_limits<T>::infinity();

    return std::abs(a0-a1) / std::max(T(1), std::max(std::abs(a0),std::abs(a1)));
  }

  template<typename T>
  inline detail::if_container<T,std::vector<double>> reldist(T const& a0, T const& a1)
  {
    using type = decltype(*a0.begin());
    std::vector<double> rels;

    std::transform( a0.begin(), a0.end(), a1.begin()
                  , std::back_inserter(rels)
                  , [](type const& a,type const& b) { using ::stf::reldist; return reldist(a,b); }
                  );

    return rels;
  }

  template<typename T, typename U>
  inline detail::if_container<T,std::vector<double>>
  reldist(U const& a1,T const& a0)
  {
    using type = decltype(*a0.begin());
    std::vector<double> rels;

    std::transform( a0.begin(), a0.end()
                  , std::back_inserter(rels)
                  , [&a1](type const& a) { using ::stf::reldist; return reldist(a1,a); }
                  );

    return rels;
  }

  template<typename T, typename U>
  inline detail::if_container<T,std::vector<double>>
  reldist(T const& a0,U const& a1)
  {
    using type = decltype(*a0.begin());
    std::vector<double> rels;

    std::transform( a0.begin(), a0.end()
                  , std::back_inserter(rels)
                  , [&a1](type const& a) { using ::stf::reldist; return reldist(a,a1); }
                  );

    return rels;
  }

  template<typename T, typename U>
  inline detail::are_not_containers<T,U,double> reldist(T const& a0, U const& a1)
  {
    return reldist(static_cast<detail::common_t<T,U>>(a0), static_cast<detail::common_t<T,U>>(a1));
  }
}

#endif
