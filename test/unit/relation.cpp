//==================================================================================================
/*
  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/
//==================================================================================================
#include <stf/unit/unit.hpp>
#include <stf/unit/tests/relation.hpp>
#include <limits>

//! [bar]
namespace foo
{
  struct bar { float v; };

  bool compare_equal        (bar const& a, bar const& b)  { return a.v == b.v; }
  bool compare_not_equal    (bar const& a, bar const& b)  { return a.v != b.v; }
  bool compare_less         (bar const& a, bar const& b)  { return a.v <  b.v; }
  bool compare_less_equal   (bar const& a, bar const& b)  { return a.v <= b.v; }
  bool compare_greater      (bar const& a, bar const& b)  { return a.v >  b.v; }
  bool compare_greater_equal(bar const& a, bar const& b)  { return a.v >= b.v; }
}
//! [bar]

//! [equal]
STF_CASE( "Check correctness of equality tests" )
{
  foo::bar x{0.3f},y{0.3f};
  std::vector<float> a{1,2,3}, b{1,2,3};

  STF_EQUAL(a,b); // natural operator==
  STF_EQUAL(x,y); // ADL-accessible compare_equal
}
//! [equal]

//! [not_equal]
STF_CASE( "Check correctness of inequality tests" )
{
  foo::bar x{0.3f},y{0.7f};
  std::vector<float> a{1,2,3}, b{7,9};

  STF_NOT_EQUAL(a,b); // natural operator!=
  STF_NOT_EQUAL(x,y); // ADL-accessible compare_not_equal
}
//! [not_equal]

//! [less]
STF_CASE( "Check correctness of less-than tests" )
{
  foo::bar x{0.3f},y{0.7f};
  std::vector<float> a{1,2,3}, b{7,9};

  STF_LESS(a,b); // natural operator<
  STF_LESS(x,y); // ADL-accessible compare_less
}
//! [less]

//! [greater]
STF_CASE( "Check correctness of greater-than tests" )
{
  foo::bar x{0.3f},y{0.7f};
  std::vector<float> a{1,2,3}, b{7,9};

  STF_GREATER(b,a); // natural operator>
  STF_GREATER(y,x); // ADL-accessible compare_greater
}
//! [greater]

//! [less_equal]
STF_CASE( "Check correctness of less-or-equal-than tests" )
{
  foo::bar x{0.3f},y{0.7f};
  std::vector<float> a{1,2,3}, b{7,9};

  STF_LESS_EQUAL(a,b); // natural operator<=
  STF_LESS_EQUAL(b,b);
  STF_LESS_EQUAL(x,y); // ADL-accessible compare_greater
  STF_LESS_EQUAL(x,x);
}
//! [less_equal]

//! [greater_equal]
STF_CASE( "Check correctness of greater-or-equal-than tests" )
{
  foo::bar x{0.3f},y{0.7f};
  std::vector<float> a{1,2,3}, b{7,9};

  STF_GREATER_EQUAL(b,a); // natural operator>=
  STF_GREATER_EQUAL(a,a);
  STF_GREATER_EQUAL(y,x); // ADL-accessible compare_greater
  STF_GREATER_EQUAL(y,y);
}
//! [greater_equal]

STF_CASE( "Check correctness of tests for NaNs" )
{
  float x = std::numeric_limits<float>::quiet_NaN(),y{0.3f};
  std::vector<float> a{x,x,x}, b{1,2,3};

  // NaN == NaN is desirable behavior
  STF_EQUAL(x,x);
  STF_EQUAL(a,a);
}
