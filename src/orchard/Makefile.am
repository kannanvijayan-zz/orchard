
AM_CXXFLAGS = -Wall -std=c++14
if DEBUG
  AM_CXXFLAGS += -g -O0 -gdwarf-4
endif
if WARNERR
  AM_CXXFLAGS += -Werror
endif

bin_PROGRAMS = orchard
orchard_SOURCES = \
    debug.cpp \
    spew.cpp \
    memalloc.cpp \
    orchard.cpp
