//==================================================================================================
/*
  Copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/
//==================================================================================================
#include <stf/common/to_string.hpp>

#include <list>
#include <vector>
#include <iostream>

static std::size_t nb_test = 0;
static std::size_t success = 0;

template<typename T> inline void is_correct_string(T const& v, std::string const& ref )
{
  nb_test++;
  auto eval = stf::to_string(v);
  auto r = (ref==eval);

  std::cout << (r ? "[OK] " : "[KO] ") << ref << " is displayed as: " << eval << "\n";
  success += r ? 1 : 0;
}

template<typename F> inline void check(std::string const& title, F tests)
{
  std::cout << std::string(40,'-') << "\n";
  std::cout << title << "\n";
  std::cout << std::string(40,'-') << "\n";
  tests();
  std::cout  << "\n";
}

struct this_doesnt_stream {};
struct this_streams {};

std::ostream& operator<<(std::ostream& os, this_streams const&)
{
  return os << "**streams**";
}

int main(int, char**)
{
  check ( "Boolean to_string"
        , []()
          {
            is_correct_string(true , "true");
            is_correct_string(false, "false");
          }
        );

  check ( "nullptr to_string"
        , []() { is_correct_string(nullptr , "nullptr"); }
        );

  check ( "nullptr to_string"
        , []()
          {
            is_correct_string('x', "x");
            is_correct_string("some string", "some string");
            is_correct_string(std::string{"hello"}, "hello");
          }
        );

  check ( "fundamental types to_string"
        , []()
          {
            is_correct_string(3   , "3"   );
            is_correct_string(2.f , "2"  );
            is_correct_string(0.25, "0.25");
          }
        );

  check ( "container to_string"
        , []()
          {
            auto x = {3,5,7};
            std::list<int> y{};
            std::vector<float> z{1.75f,2.125f,3.5f,4.625f};

            is_correct_string(x, "{ 3, 5, 7 }");
            is_correct_string(y, "{  }");
            is_correct_string(z, "{ 1.75, 2.125, 3.5, 4.625 }");
          }
        );

  check ( "streamable to_string"
        , []() { is_correct_string(this_streams{}, "**streams**"); }
        );

  std::cout << success << " / " << nb_test << " successful tests" << "\n";

  return success != nb_test;
}
