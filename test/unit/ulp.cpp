//==================================================================================================
/*
  Copyright 2017 NumScale

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/
//==================================================================================================
#include <stf/unit/unit.hpp>
#include <stf/unit/tests/precision.hpp>

STF_CASE( "ULP distance between boolean" )
{
  STF_ULP_EQUAL(true , true  , 0.);
  STF_ULP_EQUAL(true , false , 1.);
  STF_ULP_EQUAL(false, false , 0.);
  STF_ULP_EQUAL(false, true  , 1.);
}

STF_CASE_TPL( "ULP distance between integers"
            , (char)(short)(int)
              (unsigned char)(unsigned short)(unsigned int)
            )
{
  T a = 65, b = a+5;

  STF_ULP_EQUAL(a, a, 0.);
  STF_ULP_EQUAL(a, b, 5.);
  STF_ULP_EQUAL(b, a, 5.);
}

STF_CASE("ULP distance between different types")
{
//! [ulp]
  auto pi = 3.14159265358979323846;

  STF_ULP_EQUAL('A'  , 80ULL                  , 15.         );
  STF_ULP_EQUAL(true , 1LL                    , 0.          );
  STF_ULP_EQUAL( pi  , static_cast<float>(pi) , 9.84293e+07 );
  STF_ULP_EQUAL( 1.  , short{1}               , 0.          );
//! [ulp]
}

STF_CASE_TPL( "ULP distance between floating point", (float)(double))
{
  T a{1};
  T eps  = std::numeric_limits<T>::epsilon();
  T qnan = std::numeric_limits<T>::quiet_NaN();
  T inf  = std::numeric_limits<T>::infinity();
  T minf = -inf;

  STF_ULP_EQUAL(a    , a     , 0.  );
  STF_ULP_EQUAL(a    , qnan  , inf );
  STF_ULP_EQUAL(qnan , a     , inf );
  STF_ULP_EQUAL(qnan , qnan  , 0.  );

  STF_ULP_EQUAL(a    , inf   , inf );
  STF_ULP_EQUAL(inf  , a     , inf );
  STF_ULP_EQUAL(inf  , inf   , inf );

  STF_ULP_EQUAL(a    , minf  , inf );
  STF_ULP_EQUAL(minf , a     , inf );
  STF_ULP_EQUAL(minf , minf  , inf );

  STF_ULP_EQUAL(a, a-eps   , 0.5 );
  STF_ULP_EQUAL(a, a+eps   , 0.5 );
  STF_ULP_EQUAL(a, a+3*eps , 1.5 );

  STF_ULP_EQUAL(a-eps  , a , 0.5 );
  STF_ULP_EQUAL(a+eps  , a , 0.5 );
  STF_ULP_EQUAL(a+3*eps, a , 1.5 );
}

namespace n1
{
  struct my_real { float x; };
}

namespace stf { namespace ext
{
  template<typename EnableIf>
  struct equal<n1::my_real,n1::my_real,EnableIf>
  {
    inline bool operator()(n1::my_real const& l, n1::my_real const& r) const
    {
      return l.x == r.x;
    }
  };

  template<typename EnableIf>
  struct ulpdist<n1::my_real,n1::my_real,EnableIf>
  {
    inline double operator()(n1::my_real const& a, n1::my_real const& b) const
    {
      return a.x/b.x;
    }
  };
} }

STF_CASE("ULP distance of type with custom ulpdist")
{
  STF_ULP_EQUAL(n1::my_real{1.f}, n1::my_real{8.f}, 0.125);
  STF_ULP_EQUAL(n1::my_real{8.f}, n1::my_real{1.f}, 8.);
}

//! [ieee]
STF_CASE("IEEE equality")
{
  float x = std::numeric_limits<float>::quiet_NaN();
  STF_IEEE_EQUAL(x,x);
}
//! [ieee]
