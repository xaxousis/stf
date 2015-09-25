//==================================================================================================
/*
  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/
//==================================================================================================
#include <stf/unit/unit.hpp>
#include <stf/unit/tests/basic.hpp>
#include <stf/unit/tests/relation.hpp>
#include <iostream>
#include <cstdlib>

namespace foo_
{
  struct foo {};

  std::ostream& operator<<(std::ostream& os, foo const& f)
  {
    return os << "foo(" << (void*)(&f) << ")";
  }

  bool isequaln(foo const&, foo const&)
  {
    return true;
  }
}

STF_CASE_TPL( "Check STF_CASE_TPL", (float)(short)(char)(bool) )
{
  STF_EXPECT( sizeof(T) != 0ul );
  STF_EXPECT_NOT( sizeof(T) == 0ul );

  foo_::foo f,g;
  STF_EQUAL( f, g );
  STF_EQUAL( sizeof(T), sizeof(T) );
  STF_NOT_EQUAL( sizeof(T), 0ul );
  STF_LESS( sizeof(T), 16ul );
}
