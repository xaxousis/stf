//==================================================================================================
/*!
  @file

  Defines macros generating line-based unique identifiers

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 Joel Falcou


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_COMMON_UNIQUE_ID_HPP_INCLUDED
#define STF_COMMON_UNIQUE_ID_HPP_INCLUDED

#define STF_UNIQUE3( ID, LINE )  ID ## LINE
#define STF_UNIQUE2( ID, LINE )  STF_UNIQUE3( ID, LINE )

#if defined(DOXYGEN_ONLY)
/*!
  @brief Generate an unique ID for based on line

  Generates an unique symbol from a root identifier and `__LINE__`

  @param Identifier Base identifier used by the generator

**/
#define STF_UNIQUE( Identifier )

/// @brief Generate an unique function ID
#define STF_FUNCTION

/// @brief Generate an unique test registration ID
#define STF_REGISTRATION
#else

#define STF_UNIQUE( Identifier ) STF_UNIQUE2( Identifier, __LINE__ )
#define STF_FUNCTION      STF_UNIQUE(stf_function)
#define STF_REGISTRATION  STF_UNIQUE(stf_registration)

#endif

#endif
