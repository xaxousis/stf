//==================================================================================================
/*
  Copyright 2017 NumScale

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/
//==================================================================================================
#include <stf/unit/unit.hpp>
#include <stf/unit/tests/types.hpp>
#include <boost/mpl/placeholders.hpp>
#include <array>

//! [type_is]
STF_CASE( "Check that types can be tested for equality" )
{
  STF_TYPE_IS( std::add_pointer<float const>::type, float const* );
}
//! [type_is]

//! [expr_is]
STF_CASE( "Check that expression types can be tested for equality" )
{
  double d;
  boost::ignore_unused(d);

  STF_EXPR_IS( ('c', &d + 5) , double*   );
  STF_EXPR_IS( std::move(d)  , double&&  );
  STF_EXPR_IS( std::swap(d,d), void      );
}
//! [expr_is]

//! [type_expr]
template<typename T> struct add_const_ref
{
  using type = T const&;
};

STF_CASE( "Check that meta-lambda application can be tested" )
{
  std::array<float,3> x;
  STF_EXPR_TYPE( x , add_const_ref<boost::mpl::_>, (std::array<float,3> const&) );
}
//! [type_expr]
