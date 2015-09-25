 //==================================================================================================
 /*!
   @file

   Defines extensible comparator for relation tests macro

   @copyright 2015 LRI UMR 8623 CNRS/Univ Parcompare_ Sud XI
   @copyright 2015 Joel Falcou


   Distributed under the Boost Software License, Version 1.0.
   (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

 **/
 //==================================================================================================
 #ifndef STF_UNIT_DETAIL_COMPARATOR_HPP_INCLUDED
 #define STF_UNIT_DETAIL_COMPARATOR_HPP_INCLUDED

namespace stf { namespace detail
{
  template<typename LHS, typename RHS>
  inline bool isequaln(LHS const& l, RHS const& r)
  {
    // equality or both are NaNs
    return (l == r) || ((l!=l) && (r!=r));
  }

  template<typename LHS, typename RHS>
  inline bool compare_not_equal(LHS const& l, RHS const& r)
  {
    return !isequaln(l,r);
  }

  template<typename LHS, typename RHS>
  inline bool compare_less(LHS const& l, RHS const& r)          { return l < r; }

  template<typename LHS, typename RHS>
  inline bool compare_less_equal(LHS const& l, RHS const& r)    { return l <= r; }

  template<typename LHS, typename RHS>
  inline bool compare_greater(LHS const& l, RHS const& r)       { return l > r; }

  template<typename LHS, typename RHS>
  inline bool compare_greater_equal(LHS const& l, RHS const& r) { return l >= r; }
} }

#endif
