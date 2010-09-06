// file      : odb/tracer/details/config.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2005-2010 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TRACER_DETAILS_CONFIG_HXX
#define ODB_TRACER_DETAILS_CONFIG_HXX

// no pre

#ifdef _MSC_VER
#elif defined(ODB_COMPILER)
#  error libodb-tracer header included in odb-compiled header
#else
#  include <odb/tracer/details/config.h>
#endif

// no post

#endif // ODB_TRACER_DETAILS_CONFIG_HXX
