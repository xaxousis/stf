Main Page {#mainpage}
=========

@tableofcontents

@section main-preface Preface

----------------------------------------------------------------------------------------------------
Testing for correctness is a daunting task if performed on a large number of OS and architectures.
As our tools require to be optimal on a large selection of system, we developed our own testing
system that allow us to :

  - perform Behavior Driven testing with a focus on numerical precision
  - perform exhaustive precision test for single precision functions

@section main-howto How to use this documentation

----------------------------------------------------------------------------------------------------
The structure of the reference (available in the menu to the left) goes as
follow:

  - @ref group-unit\n
    Those functions, classes and macros are provided to simplify the design and
    execution of unit tests loosely based on the BDD methodology. This work has
    been largely inspired by [the LEST framework][lest] by Martin Moene.

  - @ref group-exhaustive\n
    Those functions, classes and macros are provided to simplify the design and
    execution of unit tests performing exhaustive exploration of precision related
    issue of one single precision function by testing each and every possible value
    of this function's range. This methodology is inspired from [this Bruce Dawson's
    blog post][exhaustive] and can be used to completely map the behavior of a single
    argument, single precision function.

  - @ref group-sampling\n
    Those functions, classes and macros are provided to simplify the design and
    execution of unit tests performing exploration of precision related issue of
    arbitrary function by testing random samples of value from within this function's range.

  - @ref group-common\n
    Those functions, classes and macros are useful generic components used by the various unit test
    subsystems.

  - @ref group-details\n
    Documentation for implementation details of the library. This documentation is useful
    for people wanting to work on the library internals and provide patches.


----------------------------------------------------------------------------------------------------

<!-- Links -->
[lest]: https://github.com/martinmoene/lest
[exhaustive]: https://randomascii.wordpress.com/2014/01/27/theres-only-four-billion-floatsso-test-them-all/
