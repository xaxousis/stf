Getting Started with STF::Unit  {#getting_started_unit}
=================================

@tableofcontents

@section unit-howto Objectives

Validation of complex library or software applications is critical and require specific testing
facilities. This module provides macros, classes and functions to setup, write and run unit tests
in a easy to configure, lightweight environment. This section will give a short overview of the
STF Unit Test module, its rationale and go over the structure of a simple test case.

@subsection unit-howto-suite Test Structure

Unit Test are usually gathered into *scenario* in which a specific behavior of a software
component is tested. Such scenario are usually isolated into different executables.
Then, each scenario is decomposed into *test suite*, i.e a group of related test verifying that
the current scenario is correctly serviced by the software component. Test suite are themselves
composed of at least one test case.

With STF, this decomposition (scenario/suite/test) is supported by various macro. The smallest
viable STF scenario is then defined by a single C++ source file composed of:

  * the inclusion of the file stf/unit.hpp
  * at least one test case defined by the appropriate macro (for example @ref STF_CASE
  or @ref STF_CASE_TPL

That's it ! This is a fully functional STF test suite.

@subsection unit-howto-case Defining a Test Case

Test cases are function performing repeatable, minimal operations able to unambiguously
capture a function or class behavior and assess its correctness.
In STF, a test case can be defined either as:

  * a single function defined by the @ref STF_CASE macro. In this case, the test
  function will be run and proceed to every tests it contains.

  * a family of functions generated from a template function and a list of types passed
  as a Boost.Preprocessor sequence via the @ref STF_CASE_TPL macro. Inside the test case
  itself, the template type is accessible through the template parameter @c T.

In both case, the test case is defined with an unique string description. Additionally, good
testing practices recommend to have fine grain test case to simplify test management.

@snippet example/unit/simple.cpp simple_suite

After compiling and launching the test, you should end up with the following output:

@code
--------------------------------------------------------------------------------
Scenario: Make a simple test suite
--------------------------------------------------------------------------------
[FAIL] - Empty test case

Results:
--------------------------------------------------------------------------------
1 test - 0 success - 0 failure - 1 invalid
@endcode

The unit test output contains the descriptive string of the test, its output and a
report of the total number of tests performed, the number of passing tests, the number
of failing tests and the number of invalid tests.

In this case, unsurprisingly, our empty test is reported as invalid as we consider an empty test
case as erroneous in itself. STF enforces a no test is a failure rule that applies at the test
case level. Any test case with no actual testing will be considered as a failure. Every test
functions then require at least one call to any Testing Macros.

@section unit-howto-macros Testing Macros

STF provides a set of macros to perform usual tests operations and reporting their success or failure to the test suite manager directly from within a test case.

@subsection unit-howto-macro-basic Basic Tests

Those macros provide a way to test how an arbitrary expression evaluate or to force a test
failure or success.

Macro                     | Description
:------------------------ | :-----------------------------------
`STF_PASS(MSG)`        | Forces a success and displays  `MSG`
`STF_FAIL(MSG)`        | Forces a failure and displays  `MSG`
`STF_EXPECT(XPR)`      | Checks if `XPR == true`
`STF_EXPECT_NOT(XPR)`  | Checks if `XPR == false`

These macros are accessible in the stf/unit/tests/basic.hpp file.

@subsection unit-howto-macro-rel Relational Tests

Relational tests compares the equality or ordering of values. Test is considered
successful if values are properly ordered with respect to each other:

Macro                       | Description
:-------------------------- | :-----------------
`STF_EQUAL(A,B)`         | Checks if `A == B`
`STF_NOT_EQUAL(A,B)`     | Checks if `A != B`
`STF_LESS(A,B)`          | Checks if `A < B`
`STF_GREATER(A,B)`       | Checks if `A > B`
`STF_LESS_EQUAL(A,B)`    | Checks if `A <= B`
`STF_GREATER_EQUAL(A,B)` | Checks if `A >= B`

These macros are accessible in the stf/unit/tests/relation.hpp file.

Note that all those relational tests are performed using either the default comparison operators
or, in the a custom types is being tested, a user-defined function named `is_equal`,`is_not_equal`,
`is_less` and so on that are found automatically via argument look-up.

@subsection unit-howto-macro-ulp Precision Tests

These tests are intended to compare floating points results, allowing a third parameter to
state the admitted possible difference between the two quantities. This difference can be expressed
in:

  * ULPs, that is units in the last place, which is an indication of the number of floating
  points values that are representable between the compared quantities.

  * A relative tolerance, that is a fixed quantity which defines a validity interval around the
  expected value.

Macro                           | Description
:------------------------------ | :----------------------------------
`STF_ULP_EQUAL(A,B,N)`       | Checks if `A == B` within `N` ULPs.
`STF_RELATIVE_EQUAL(A,B,N)`  | Checks if `A == B +/- N`

These macros are accessible in the stf/unit/tests/precision.hpp file.

@subsection unit-howto-macro-runtime Runtime Error Tests

Those tests check if a given expression exhibit a given runtime behavior with respect
to exceptions and assertions. Expression can be tested for being able to throw or not
and to trigger an assertion failure or not.

Macro                   | Description
:---------------------- | :----------------------------------------------------------------
`STF_THROW(XPR,T)`   | Checks if the evaluation of `XPR` throws an exception of type `T`
`STF_NO_THROW(XPR)`  | Checks if the evaluation of `XPR` doesn't throw
`STF_ASSERT(XPR)`    | Checks if the evaluation of `XPR` triggers an assertion
`STF_NO_ASSERT(XPR)` | Checks if the evaluation of `XPR` doesn't trigger an assertion

These macros are accessible in the stf/unit/tests/exceptions.hpp file.

Note that testing for assertion failure require the use of `BOOST_ASSERT` or `BOOST_ASSERT_MSG` macros
and the definiton of the `BOOST_ENABLE_ASSERT_HANDLER` preprocessor symbol when compiling.

@subsection unit-howto-macro-type Type Related Tests

Those tests check if a given type or type of expression is verify some relation with another types
or some general types requirements.

Macro                     | Description
:------------------------ | :---------------------------------------
`STF_TYPE_IS(T,U)`     | Checks if types `T` and `U` are the same
`STF_EXPR_IS(X,U)`     | Checks if the type of `X` and `U` are the same
`STF_EXPR_TYPE(E,L,T)` | Checks if a meta-lambda return is correct

These macros are accessible in the stf/unit/tests/types.hpp file.

@section unit-howto-args Command Line and Environment Usage

STF provides options that can be provided either by the command line or by setting up
environment variables to control some aspects of the test behavior.

Command Line option       | Environment Variable | Value  | Description
:------------------------ | :------------------- | :------| :-----------------------------------
`--color`                 | `STF_COLOR`       | `0/1`  | Activate or deactivate output colors
`--random`                | | non-zero unsigned integer | Randomize tests order using a given seed

You can pass other arbitrary options on the command line by using the format `--name value`.
Those options are then accessible through the `args` function.

@section unit-howto-custom Extension Points

TODO

@subsection unit-howto-custom-driver Custom Driver

TODO

@subsection unit-howto-custom-case Custom Test Case

TODO

