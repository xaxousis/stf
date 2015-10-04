//==================================================================================================
/*
  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/
//==================================================================================================
#define STF_USE_CUSTOM_DRIVER
#include <stf/unit/unit.hpp>
#include <stf/unit/tests/basic.hpp>
#include <stf/unit/tests/exceptions.hpp>
#include <stf/unit/tests/precision.hpp>
#include <stf/unit/tests/relation.hpp>
#include <stf/unit/tests/types.hpp>

//! [fail]
STF_CASE( "Check that forced failure fails" )
{
  STF_FAIL("Forced fail");
}
//! [fail]

STF_CASE( "Check that forced broken expectation fails" )
{
  STF_EXPECT(false == true);
  STF_EXPECT_NOT(true == true);
}

void foo(bool x)  { if(x) throw 0; }
void bar(int x )  { BOOST_ASSERT_MSG( x != 0, "x must be non-null" ); }

STF_CASE( "Check that forced broken exceptions tests fails" )
{
  STF_THROW(foo(false),int);
  STF_NO_THROW(foo(true));
  STF_ASSERT(bar(1));
  STF_NO_ASSERT(bar(0));
}

STF_CASE( "Check that forced broken precision tests fails" )
{
  STF_RELATIVE_EQUAL(1,2,0.5);
  STF_ULP_EQUAL(1., 2., 0.5 );
}

STF_CASE( "Check that forced broken relation tests fails" )
{
  STF_EQUAL( 1, 0 );
  STF_NOT_EQUAL( 1, 1 );
  STF_LESS(1,0);
  STF_GREATER(0,1);
  STF_LESS_EQUAL(1,0);
  STF_GREATER_EQUAL(0,1);
}

struct meta { template<typename T> struct apply { using type = T&; }; };

STF_CASE( "Check that forced broken types tests fails" )
{
  STF_TYPE_IS( int, float );
  STF_EXPR_IS( 1.f , void**   );
  STF_EXPR_TYPE( 1 , meta, double );
}

int main(int argc, const char** argv)
{
  ::stf::unit::env $env(argc,argv,std::cout);
  return ::stf::run( $env, ::stf::unit::suite(), 18, 0 );
}
