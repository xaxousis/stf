Design Rationale     {#design_rationale}
================

@tableofcontents

@section rationale-preface Objectives

This section explains some of the Design choices made by STF on how to implement some of its
components and how the usage of its macros was envisioned.

@section rationale-ulp Precision testing

> "Are these two floating computations results similar enough ?""

This is maybe the most difficult question to answer when implementing and
validating numerical algorithms. Various methods are often found in existing
testing frameworks or are used by developers. But, in the same way floating-point
arithmetic can be tricky, floating-point comparisons are even trickier.

In the rest of this section, we take for granted that the basic
notions of floating-point computations and their related problems is known by
the reader. If not, we strongly recommend having a deep look at [Goldberg's paper
on the subject][Goldberg] or to [its simplified version][guide].

@subsection rationale-ulp-metric Metric for precision measurement

The first thing people learn (and often they learn it the hard way) is that strict
equality for floating points number is often meaningless or very hard to achieve.
Once this state of fact is integrated, people often goes to use a simple absolute
difference with an arbitrary threshold. If this method looks sound, it's easy to
fold and may lead to false positive. The proper way to compare non-zero or non-invalid
floating point numbers is to use the *Unit in the Last Place* metric.

Let us define @f$ \epsilon @f$ -- the machine epsilon@refanchor{1} -- as being the smallest
positive floating point number such that @f$ 1+\epsilon @f$ is different of @f$ 1 @f$
In fact, @f$ 1+\epsilon @f$ and @f$ 1 @f$ only differs by a bit 1 in the least significant digit:
the unit in the last place (ULP). Generally, the ULP between a floating point number
@f$f@f$ and its immediate successor is @f$ \epsilon \times 2^{E} @f$ where @f$E@f$ is the
exponent of @f$f@f$.

@subsection rationale-ulp-distance Computing ULP Distance

The ULP distance (or `ulpdist`) is a way to compare floating-point numbers by
estimating the number of significant bits between their respective representations.
The IEEE 754 specification -- followed by all modern floating-point hardware -- requires that the
result of an elementary arithmetic operation (addition, subtraction, multiplication, division,
and square root) must be within 0.5 ULP of the mathematically exact result. Achieving 0.5-1 ULP
for computationally complex functions like transcendental functions is what a proper numerical
library should aim for.

The full algorithm can be expressed in standard C++ in the following way:

@snippet doc/src/ulpdist.cpp ulpdist

Put in an other way, one can estimate the `ulpdist` between two floating point
numbers as the number of representable floating points values between them. This
estimation leads to the following properties:

  * The `ulpdist` between @f$N@f$ and @f$N+N\times\epsilon@f$ is equal to @f$0.5@f$
  * The `ulpdist` between @f$N@f$ and @f$N+N\times\frac{\epsilon}{2}@f$ is equal to @f$0@f$
  * If a `double` is compared to the double representation of its single precision
  conversion (they are exceptions as for fully representable reals), their
 `ulpdist` will be around @f$2^{26.5}@f$ (or @f$10^8@f$).

  For example: `ulpdist( double(float(M_PI)), double(M_PI) ) == 9.84293e+07`

@subsection rationale-ulp-tests Taking ULP in consideration in your tests

What to do then when writing an unit test that handles floating points number ?
You basically have three cases :

  * The value you compare must be equal by design. In this case, use
  @ref STF_EQUAL to clearly state your intent. One such case can be
  for example functions that construct a floating point value bitwise.
  * The value you compare are the results of an undetermined number of other
  floating point operations. In this case, use @ref STF_ULP_EQUAL and
  try to estimate the maximum amount of ULP your implementation should give. This
  can be either done by a strict analysis of the function behavior or by some guess
  work.
  * The value you compare are the results of an undetermined number of other
  floating point operations but stands in a predictable absolute range of error
  independent of the architecture and magnitude of the input. In this case, use
  @ref STF_RELATIVE_EQUAL.

Take extreme care to not overestimate the value of ULP measures. Some classical algorithms
may ends up with hundreds of ULPs but still be meaningful.

----------------------------------------------------------------------------------------------------

<!-- Footnotes -->
@anchor{1} @f$\epsilon@f$ is @f$2^{-52}@f$ for double precision numbers and @f$2^{-23}@f$ for
single precision numbers.

<!-- Links -->
[Goldberg]: http://docs.oracle.com/cd/E19957-01/806-3568/ncg_goldberg.html
[guide]: http://floating-point-gui.de/
