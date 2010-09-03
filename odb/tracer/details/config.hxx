// file      : odb/tracer/details/config.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2005-2010 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TRACER_DETAILS_CONFIG_HXX
#define ODB_TRACER_DETAILS_CONFIG_HXX

// no pre

#ifdef HAVE_CONFIG_H
#  include <odb/tracer/details/config.h>
#endif

#ifndef LIBODB_TRACER_INCLUDE_SHORT
  #ifdef _WIN32
    #define LIBODB_TRACER_INCLUDE_SHORT 1
  #endif
#endif

// no post

#endif // ODB_TRACER_DETAILS_CONFIG_HXX
