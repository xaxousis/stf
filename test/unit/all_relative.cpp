//==================================================================================================
/*
  Copyright 2016 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/
//==================================================================================================
#include <stf/unit/unit.hpp>
#include <stf/unit/tests/precision.hpp>

// ![all_relative]
STF_CASE("Relative distance between containers")
{
  std::vector<float> a{1.f,1.1f,0.9f,1.3f};
  std::vector<float> b{1.f,1.f,1.f,1.f};
  std::vector<float> s{1.1f};

  STF_ALL_RELATIVE_EQUAL(a  , b   , 25);
  STF_ALL_RELATIVE_EQUAL(s  , 1.f , 25);
  STF_ALL_RELATIVE_EQUAL(1.f, s   , 25);
}
// ![all_relative]
