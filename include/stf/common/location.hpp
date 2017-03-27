//==================================================================================================
/*!
  @file

  Defines file location wrapper class

  @copyright 2017 NumScale


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_COMMON_LOCATION_HPP_INCLUDED
#define STF_COMMON_LOCATION_HPP_INCLUDED

#include <iostream>
#include <string>

namespace stf
{
  /*!
    @ingroup group-common

    Simple POD wrapper for the __FILE__/__LINE__ macro pair.
  **/
  struct location
  {
    std::string file;
    std::size_t line;
  };

  /// Insert a location into a stream
  std::ostream& operator<<(std::ostream& os, location const& l)
  {
    return os << l.file << ":" << l.line;
  }

  /// Constructs a location instance
  inline location at(std::string const& f, std::size_t l) { return {f,l}; }
}

#endif
