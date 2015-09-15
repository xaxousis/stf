//==================================================================================================
/*!
  @file

  Defines informations display macros.

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 Joel Falcou


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_UNIT_TESTS_INFOS_HPP_INCLUDED
#define STF_UNIT_TESTS_INFOS_HPP_INCLUDED

#include <stf/common/values.hpp>
#include <stf/common/location.hpp>
#include <stf/unit/detail/decompose.hpp>

/*!
  @ingroup group-detail
  Display an informations message with a given colorization

  @param INDICATOR Type of message
  @param COLOR   Color of the indicator
  @param MESSAGE Values to display
**/
#define STF_DISPLAY( INDICATOR, COLOR, MESSAGE )                                                 \
do                                                                                                  \
{                                                                                                   \
  if(!$.is_compact()) $.stream() << COLOR(INDICATOR) << MESSAGE << std::endl;                       \
} while( ::stf::is_false() )                                                                     \
/**/

/*!
  @ingroup group-unit
  Display an informations message

  @par Usage:

  @snippet test/unit/pass.cpp info

  @param MESSAGE Values to display
**/
#define STF_INFO( MESSAGE ) STF_DISPLAY("[INFO] ",stf::green_, MESSAGE)

/*!
  @ingroup group-unit
  Display a warning message.

  @par Usage:

  @snippet test/unit/pass.cpp warn

  @param MESSAGE Values to display
**/
#define STF_WARNING( MESSAGE ) STF_DISPLAY("[WARNING] ",stf::yellow_, MESSAGE)

/*!
  @ingroup group-unit
  Display an error message.

  @par Usage:

  @snippet test/unit/pass.cpp error

  @param MESSAGE Values to display
**/
#define STF_ERROR( MESSAGE ) STF_DISPLAY("[ERROR] ",stf::red_, MESSAGE)

/*!
  @ingroup group-unit
  Automatically successful test

  Register a test which always passes and streams a custom @c MESSAGE.

  @par Usage:

  @snippet test/unit/pass.cpp pass

  @param MESSAGE Values to stream as additional informations
**/
#define STF_PASS( MESSAGE )                                                                      \
do                                                                                                  \
{                                                                                                   \
  $.as_success();                                                                                   \
  if(!$.is_compact())                                                                               \
  {                                                                                                 \
    $.pass() << MESSAGE << " in: " << ::stf::at(__FILE__,__LINE__) << std::endl;                 \
  }                                                                                                 \
  else                                                                                              \
  {                                                                                                 \
    $.stream() << ::stf::green_("+");                                                            \
  }                                                                                                 \
} while( ::stf::is_false() )                                                                     \
/**/

/*!
  @ingroup group-unit
  Automatically failing test

  Register a test which always fails and streams a custom @c MESSAGE.

  @par Usage:

  @snippet test/unit/failure.cpp fail

  @param MESSAGE Values to stream as additional informations
**/
#define STF_FAIL( MESSAGE )                                                                      \
do                                                                                                  \
{                                                                                                   \
  $.as_failure();                                                                                   \
  if(!$.is_compact())                                                                               \
  {                                                                                                 \
    $.fail() << MESSAGE << " in: " << ::stf::at(__FILE__,__LINE__) << std::endl;                 \
  }                                                                                                 \
  else                                                                                              \
  {                                                                                                 \
    $.stream() << ::stf::red_("-");                                                              \
  }                                                                                                 \
} while( ::stf::is_false() )                                                                     \
/**/

#endif
