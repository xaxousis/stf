//==================================================================================================
/*!
  @file

  Defines types and macros for macro expression display

  @copyright 2017 NumScale


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_UNIT_DETAIL_DECOMPOSE_HPP_INCLUDED
#define STF_UNIT_DETAIL_DECOMPOSE_HPP_INCLUDED

#include <stf/common/to_string.hpp>
#include <stf/unit/detail/result.hpp>
#include <stf/unit/detail/comparator.hpp>

namespace stf { namespace detail
{
  // Carry value around up to display point inside test macro
  template<typename Expression> struct lhs_expr
  {
    Expression lhs;

    lhs_expr( Expression x ) : lhs( x ) {}

    lhs_expr(lhs_expr const&)             = delete;
    lhs_expr& operator=(lhs_expr const&)  = delete;

    operator result()
    {
      return result { bool(lhs)
                    , stf::to_string( bool(lhs) )
                    , stf::to_string("")
                    , stf::to_string("")
                    };
    }

    #define STF_BINARY_DECOMPOSE(OP,SB,FN)                                                          \
    template<typename R> result operator OP( R const & rhs )                                        \
    {                                                                                               \
      return  { stf::detail::FN(lhs, rhs)                                                           \
              , stf::to_string( lhs ), stf::split_line(lhs,rhs,SB), stf::to_string(rhs)             \
              };                                                                                    \
    }                                                                                               \
    /**/

    STF_BINARY_DECOMPOSE( ==, "==", eq  )
    STF_BINARY_DECOMPOSE( !=, "!=", neq )
    STF_BINARY_DECOMPOSE( < , "<" , lt  )
    STF_BINARY_DECOMPOSE( > , ">" , gt  )
    STF_BINARY_DECOMPOSE( >=, ">=", ge  )
    STF_BINARY_DECOMPOSE( <=, "<=", le  )

    #undef STF_BINARY_DECOMPOSE
  };

  /*!
    @brief Trampoline type for custom display of value injected from a macro.
    @ingroup group-details

    When a macro like STF_EXPECT( a == b ) is called, it's often useful to be able to
    display the value of a and b without having to butcher the macro API. The decomposer
    type is used to provide a member pointer access overload able to catch arbitrary binary
    expression and forward them to the display system.

    @note This code is a direct adaptation of the similar technique used by Martin Moene in LEST
  **/
  struct decomposer
  {
    template <typename Expression>
    lhs_expr<Expression const &> operator->* ( Expression const& expr )
    {
      return { expr };
    }
  };
} }

/*!
  @brief Macro decomposing a test expression for display
  @ingroup group-details

  @param XPR Expression to display
**/
#define STF_DECOMPOSE( XPR ) ( stf::detail::decomposer()->* XPR )

#endif
