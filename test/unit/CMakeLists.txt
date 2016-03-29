##===================================================================================================
##                                 Copyright 2015 Joel Falcou
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================
include(make_unit)
include(make_coverage)

set ( SOURCES
      all_relative.cpp
      all_ulp.cpp
      expect.cpp
      exceptions.cpp
      failure.cpp
      invalid.cpp
      pass.cpp
      relation.cpp
      relative.cpp
      types.cpp
      ulp.cpp
    )

make_unit( "stf.unit" ${SOURCES})
make_coverage("stf.unit" ${SOURCES})
