//==================================================================================================
/*!
  @file

  Defines various helper macros for warning-free compilation

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 Joel Falcou


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_COMMON_WARNING_HPP_INCLUDED
#define STF_COMMON_WARNING_HPP_INCLUDED

#if defined(__GNUC__) || defined(DOXYGEN_ONLY)
/*!
  @ingroup group-details

  Evaluates an expression @c X and prevent warning about unused return.

  @param X Expression to evaluates
**/
#define STF_UNUSED(X) (void) X
#else
#define STF_UNUSED(X) X
#endif

#endif
