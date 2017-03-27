//==================================================================================================
/*!
  @file

  Defines the basic reldist function

  @copyright 2017 NumScale


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_UNIT_DETAIL_RELDIST_HPP_INCLUDED
#define STF_UNIT_DETAIL_RELDIST_HPP_INCLUDED

#include <stf/unit/detail/traits.hpp>
#include <type_traits>
#include <algorithm>
#include <iterator>
#include <cmath>

namespace stf
{
  namespace ext
  {
    /*!
      @ingroup group-details

      @brief User extension point for relative precision computation
    **/
    template< typename T1, typename T2 = T1
            , typename EnableIF = void
            >
    struct reldist
    {
      inline double operator()(T1 const& a, T2 const& b) const
      {
        using common_t = detail::common_t<T1,T2>;
        return ext::reldist<common_t>() ( static_cast<common_t>(a)
                                        , static_cast<common_t>(b)
                                        );
      }
    };

    // Overload for booleans
    template< typename T>
    struct reldist<T,T,typename std::enable_if<std::is_same<T,bool>::value>::type>
    {
      inline double operator()(T a, T b) const
      {
        return a == b ? 0. : 1.;
      }
    };

    // Overload for reals
    template<typename T>
    struct reldist< T, T
                  , typename std::enable_if<std::is_floating_point<T>::value>::type
                  >
    {
      inline double operator()(T a, T b) const
      {
        auto inf_ = std::numeric_limits<T>::infinity();
        auto aa   = std::abs(a);
        auto ab   = std::abs(b);

        if( (a == b  ) || ((a != a) && (b!=b)) )  return 0.;
        if( (a != a  ) || (b  != b) )             return inf_;
        if( (aa==inf_) || (ab == inf_) )          return inf_;

        return std::abs(a-b) / std::max(T(1), std::max(aa,ab));
      }
    };

    // Overload for integers
    template<typename T>
    struct reldist< T, T
                  , typename std::enable_if <   std::is_integral<T>::value
                                            &&  !std::is_same<T,bool>::value
                                            >::type
                  >
    {
      inline double operator()(T a, T b) const
      {
        auto d0 = static_cast<double>(a), d1 = static_cast<double>(b);
        return reldist<double>()(d0,d1);
      }
    };
  }

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

    @param a0 First value to compare
    @param a1 Second value to compare
    @return The relative distance between a0 and a1
  **/
  template<typename T, typename U> inline double reldist(T const& a0, U const& a1)
  {
    return ext::reldist<T,U>()(a0,a1);
  }
}

#endif
