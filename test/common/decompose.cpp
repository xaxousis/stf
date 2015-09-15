//==================================================================================================
/*
  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/
//==================================================================================================
#include <stf/unit/detail/decompose.hpp>

#include <list>
#include <vector>
#include <iostream>

static std::size_t nb_test = 0;
static std::size_t success = 0;


#define IS_CORRECT(A,B,OP,L,R)                                                                      \
{                                                                                                   \
  nb_test++;                                                                                        \
  auto eval = STF_DECOMPOSE( A OP B);                                                            \
  auto r = (L==eval.lhs)&&(R==eval.rhs);                                                            \
  std::cout << (r ? "[OK] " : "[KO] ") << #A << " " << #OP << " " << #B                             \
            << " is displayed as: \"" << eval.lhs << #OP << eval.rhs << "\"\n";                     \
  success += r ? 1 : 0;                                                                             \
}                                                                                                   \
/**/

template<typename F> inline void check(std::string const& title, F tests)
{
  std::cout << std::string(40,'-') << "\n";
  std::cout << title << "\n";
  std::cout << std::string(40,'-') << "\n";
  tests();
  std::cout  << "\n";
}

int main(int, char**)
{
  int   a = 1;
  float b = 3;

  check( "== decomposition" , [&](){ IS_CORRECT(a, b , ==, "1","3") } );
  check( "!= decomposition" , [&](){ IS_CORRECT(a, b , !=, "1","3") } );
  check( ">  decomposition" , [&](){ IS_CORRECT(a, b , > , "1","3") } );
  check( ">= decomposition" , [&](){ IS_CORRECT(a, b , >=, "1","3") } );
  check( "<  decomposition" , [&](){ IS_CORRECT(a, b , < , "1","3") } );
  check( "<= decomposition" , [&](){ IS_CORRECT(a, b , <=, "1","3") } );

  std::cout << success << " / " << nb_test << " successful tests" << "\n";

  return success != nb_test;
}

