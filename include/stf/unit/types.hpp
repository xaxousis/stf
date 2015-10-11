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

#define STF_IEEE_TYPES (float)(double)

#define STF_SIZED_SIGNED_TYPES    (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
#define STF_SIZED_UNSIGNED_TYPES  (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
#define STF_SIZED_TYPES           STF_SIZED_SIGNED_TYPES STF_SIZED_UNSIGNED_TYPES

#define STF_NATIVE_SIGNED_TYPES   (char)(short)(int)(long)(long long)
#define STF_NATIVE_UNSIGNED_TYPES (unsigned char)(unsigned short)(unsigned int)(unsigned long)(unsigned long long)
#define STF_NATIVE_TYPES          STF_NATIVE_SIGNED_TYPES STF_NATIVE_UNSIGNED_TYPES

#define STF_STANDARD_TYPES (std::size_t)(std::ptrdiff_t)(std::intptr_t)(std::uintptr_t)

#define STF_NUMERIC_TYPES STF_SIZED_TYPES STF_NATIVE_TYPES STF_STANDARD_TYPES STF_IEEE_TYPES
#define STF_ALL_TYPES (bool)STF_NUMERIC_TYPES

#endif
