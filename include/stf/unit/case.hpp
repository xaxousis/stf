//==================================================================================================
/*!
  @file

  Defines the various macro for defining test cases

  @copyright 2015 Joel Falcou


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_UNIT_CASE_HPP_INCLUDED
#define STF_UNIT_CASE_HPP_INCLUDED

#include <stf/common/string.hpp>
#include <stf/common/unique_id.hpp>
#include <stf/unit/detail/registration.hpp>
#include <stf/unit/env.hpp>

#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

/*!
  @ingroup group-unit

  @brief Starts a block defining a test case.

  The following block will contains user defined preparation, actual tests,
  expectations and clean-up for said test case.

  A simple test case is then defined as :

  @snippet example/unit/case.cpp case

  Note that test cases performing no actual tests such as:

  @snippet example/unit/case.cpp fail_case

  will be reported as an automatic failure.

  Most of the time, however, compiling with all warning options will lead to compile-time
  notification of such cases.

  @param DESCRIPTION String literal describing the purpose of the test case
**/
#define STF_CASE(DESCRIPTION)                                                                       \
void STF_FUNCTION( ::stf::unit::env& );                                                             \
namespace                                                                                           \
{                                                                                                   \
  ::stf::detail::registrar                                                                          \
  STF_REGISTRATION{::stf::unit::test(DESCRIPTION, STF_FUNCTION)};                                   \
}                                                                                                   \
void STF_FUNCTION( ::stf::unit::env& runtime)                                                               \
/**/

#define STF_RTYPE(z, n, t)                                                                          \
{                                                                                                   \
  using T = BOOST_PP_SEQ_ELEM(n,t);                                                                 \
  runtime.stream() << std::endl;                                                                    \
  runtime.stream() <<  "With T = [" << STF_STRING(BOOST_PP_SEQ_ELEM(n,t))                           \
                        << "] ";                                                                    \
  if(!runtime.is_compact()) { runtime.stream() << std::endl; }                                      \
  STF_FUNCTION<T>(runtime);                                                                         \
}                                                                                                   \
/**/

/*!
  @ingroup group-unit

  @brief Starts a block defining a template test case.

  The following block will contains user defined preparation, actual tests,
  expectations and clean-up for said test case parametrized by a template type named @c T
  and instantiated for each type in the @c TYPES sequence.

  Such a test case is then defined as :

  @snippet example/unit/case.cpp case_tpl

  Note that, as for @ref STF_CASE , empty tests are reported as automatic failures.

  @param DESCRIPTION  String literal describing the scope of the test case
  @param TYPES        Boost.Preprocessor sequence of types
**/
#define STF_CASE_TPL(DESCRIPTION, TYPES)                                                            \
template<typename T> void STF_FUNCTION( stf::unit::env& );                                          \
namespace                                                                                           \
{                                                                                                   \
  stf::detail::registrar                                                                            \
  STF_REGISTRATION{ stf::unit::test                                                                 \
                      ( DESCRIPTION                                                                 \
                      , [](::stf::unit::env& runtime) -> void                                       \
                        {                                                                           \
                          BOOST_PP_REPEAT(BOOST_PP_SEQ_SIZE(TYPES),STF_RTYPE,TYPES)                 \
                        }                                                                           \
                      )                                                                             \
                    };                                                                              \
}                                                                                                   \
template<typename T> void STF_FUNCTION( stf::unit::env& runtime )                                   \
/**/

#endif
