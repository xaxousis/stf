//==================================================================================================
//                  Copyright 2015 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//                  Copyright 2015 Joel Falcou
//
//                    Distributed under the Boost Software License, Version 1.0.
//                           See accompanying file LICENSE.txt or copy at
//                               http://www.boost.org/LICENSE_1_0.txt
//==================================================================================================
#ifndef STF_UNIT_DETAIL_RESULT_HPP_INCLUDED
#define STF_UNIT_DETAIL_RESULT_HPP_INCLUDED

#include <string>

namespace stf { namespace detail
{
  // Represent a test result and its displayable representation
  struct result
  {
    bool        status;
    std::string lhs;
    std::string op;
    std::string rhs;

    explicit operator bool() { return status; }
  };
} }

/*!
  @ingroup group-details
  Dump data from a comparison onto the output stream

  @param R Result structure to dump
**/
#define STF_DUMP(R)                                                                                 \
runtime.stream()  << "failing because:\n" << R.lhs << R.op << R.rhs << "\n" << "is incorrect.\n";         \
/**/

#endif
