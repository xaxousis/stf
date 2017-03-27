//==================================================================================================
//                  Copyright 2015 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//                  Copyright 2017 NumScale
//
//                    Distributed under the Boost Software License, Version 1.0.
//                           See accompanying file LICENSE.txt or copy at
//                               http://www.boost.org/LICENSE_1_0.txt
//==================================================================================================
#ifndef STF_UNIT_DETAIL_REGISTRATION_HPP_INCLUDED
#define STF_UNIT_DETAIL_REGISTRATION_HPP_INCLUDED

#include <stf/unit/test.hpp>

namespace stf { namespace detail
{
  struct registrar
  {
    registrar( ::stf::unit::test const& test_case ) { unit::suite().push_back( test_case ); }
  };
} }

#endif
