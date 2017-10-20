//==================================================================================================
/*
  Copyright 2017 NumScale

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/
//==================================================================================================
#include <stf/unit/unit.hpp>
#include <stf/unit/tests/precision.hpp>

// ![all_absolute]
STF_CASE("Absolute distance between containers")
{
  std::vector<float> a{1.f,1.1f,0.9f,1.3f};
  std::vector<float> b{1.f,1.f,1.f,1.f};
  std::vector<float> s{1.1f};

  STF_ALL_ABSOLUTE_EQUAL(a  , b   , .4);
  STF_ALL_ABSOLUTE_EQUAL(s  , 1.f , .15);
  STF_ALL_ABSOLUTE_EQUAL(1.f, s   , .15);
}
// ![all_absolute]
