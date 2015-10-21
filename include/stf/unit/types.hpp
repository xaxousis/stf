//==================================================================================================
/*!
  @file

  Common types and filters ready to use

  @copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_UNIT_TYPES_HPP_INCLUDED
#define STF_UNIT_TYPES_HPP_INCLUDED

#include <cstddef>
#include <cstdint>

#define STF_SIGNED_BASIC_INTEGRAL_TYPES     (std::ptrdiff_t)(std::intptr_t)(std::intmax_t)
#define STF_UNSIGNED_BASIC_INTEGRAL_TYPES   (std::size_t)(std::uintptr_t)(std::uintmax_t)
#define STF_BASIC_TYPES                     STF_SIGNED_BASIC_INTEGRAL_TYPES STF_UNSIGNED_BASIC_INTEGRAL_TYPES

#define STF_SIGNED_FIXED_INTEGRAL_TYPES    (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
#define STF_UNSIGNED_FIXED_INTEGRAL_TYPES  (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
#define STF_FIXED_INTEGRAL_TYPES           STF_SIGNED_FIXED_INTEGRAL_TYPES STF_UNSIGNED_FIXED_INTEGRAL_TYPES

#define STF_SIGNED_STD_INTEGRAL_TYPES    STF_SIGNED_BASIC_INTEGRAL_TYPES STF_SIGNED_FIXED_INTEGRAL_TYPES
#define STF_UNSIGNED_STD_INTEGRAL_TYPES  STF_UNSIGNED_BASIC_INTEGRAL_TYPES STF_UNSIGNED_FIXED_INTEGRAL_TYPES
#define STF_STD_INTEGRAL_TYPES           STF_SIGNED_STD_INTEGRAL_TYPES STF_UNSIGNED_STD_INTEGRAL_TYPES

#define STF_SIGNED_INTEGRAL_TYPES   (signed char)(signed short)(signed int)(signed long)
#define STF_UNSIGNED_INTEGRAL_TYPES (unsigned char)(unsigned short)(unsigned int)(unsigned long)
#define STF_INTEGRAL_TYPES          (char) STF_SIGNED_INTEGRAL_TYPES STF_UNSIGNED_INTEGRAL_TYPES

#define STF_SIGNED_ALL_INTEGRAL_TYPES   STF_SIGNED_STD_INTEGRAL_TYPES STF_SIGNED_INTEGRAL_TYPES
#define STF_UNSIGNED_ALL_INTEGRAL_TYPES STF_UNSIGNED_STD_INTEGRAL_TYPES STF_UNSIGNED_INTEGRAL_TYPES
#define STF_ALL_INTEGRAL_TYPES          STF_SIGNED_ALL_INTEGRAL_TYPES STF_UNSIGNED_ALL_INTEGRAL_TYPES

#define STF_IEEE_TYPES (float)(double)

#define STF_SIGNED_NUMERIC_TYPES    STF_SIGNED_ALL_INTEGRAL_TYPES STF_IEEE_TYPES
#define STF_UNSIGNED_NUMERIC_TYPES  STF_UNSIGNED_ALL_INTEGRAL_TYPES
#define STF_NUMERIC_TYPES           STF_SIGNED_NUMERIC_TYPES STF_UNSIGNED_NUMERIC_TYPES

#define STF_ALL_TYPES     (bool) STF_NUMERIC_TYPES

#endif
