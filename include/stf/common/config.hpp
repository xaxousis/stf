//==================================================================================================
/*!
  @file

  Defines the various wrapper around name demangling function

  @copyright 2017 NumScale


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_CONFIG_HPP_INCLUDED
#define STF_CONFIG_HPP_INCLUDED

#include <boost/config.hpp>

// Detect stupid ICC/G++ combos
#if defined(BOOST_INTEL_GCC_VERSION) && (BOOST_INTEL_GCC_VERSION < 40600)
#  if !defined(STF_USE_INCOMPLETE_STD)
#    define STF_USE_INCOMPLETE_STD
#  endif
#endif

#endif
