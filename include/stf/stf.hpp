//==================================================================================================
/*!
  @file

  Main header for the unit test system

  @copyright 2017 NumScale


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_HPP_INCLUDED
#define STF_HPP_INCLUDED

#include <stf/unit/unit.hpp>
#include <stf/unit/functions.hpp>

namespace stf
{
  namespace unit
  {
    /*!
      @defgroup group-unit Unit Test related components.
      Unit Test related components
    **/

    /*!
      @defgroup group-common Utility components
      Utility components
    **/

    /*!
      @defgroup group-exhaustive Exhaustive testing related components.
      Exhaustive testing related components
    **/

    /*!
      @defgroup group-sampling Sampling testing related components.
      Sampling testing related components
    **/

#if defined(DOXYGEN_ONLY)
/*!
  @ingroup group-unit
  @brief Test application entry-point registration

  If STF_USE_CUSTOM_DRIVER is defined, STF won't define an predefined @c main function
  and will let the client application provides it.

  @snippet example/unit/case.cpp custom_driver_macro
**/
#define STF_USE_CUSTOM_DRIVER
#endif
  }

   namespace detail
  {
    /*!
      @defgroup group-details Details
      Implementation details.
    **/
  }
}

#endif
