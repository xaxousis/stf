//==================================================================================================
/**
  Copyright 2017 NumScale

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

  See https://stackoverflow.com/a/11826666
**/
//==================================================================================================
#ifndef STF_NULL_STREAM_HPP_INCLUDED
#define STF_NULL_STREAM_HPP_INCLUDED

#include <streambuf>
#include <ostream>

namespace stf {
namespace detail {

class null_buffer_t : public std::streambuf
{
public:
  int overflow(int c) { return c; }
};

} // closing namespace [stf]::detail

namespace {

stf::detail::null_buffer_t null_buffer = {};
std::ostream null_stream(&null_buffer);

} // closing anonymous namespace

} // closing namespace stf

#endif /* STF_NULL_STREAM_HPP_INCLUDED */
