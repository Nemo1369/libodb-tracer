// file      : odb/tracer/version.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2005-2011 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TRACER_VERSION_HXX
#define ODB_TRACER_VERSION_HXX

#include <odb/pre.hxx>

#include <odb/version.hxx>

// Version format is AABBCCDD where
//
// AA - major version number
// BB - minor version number
// CC - bugfix version number
// DD - alpha / beta (DD + 50) version number
//
// When DD is not 00, 1 is subtracted from AABBCC. For example:
//
// Version     AABBCCDD
// 2.0.0       02000000
// 2.1.0       02010000
// 2.1.1       02010100
// 2.2.0.a1    02019901
// 3.0.0.b2    02999952
//

// Check that we have compatible ODB version.
//
#if ODB_VERSION != 10300
#  error incompatible odb interface version detected
#endif

// libodb-tracer version: odb interface version plus the bugfix
// version.
//
#define LIBODB_TRACER_VERSION     1030000
#define LIBODB_TRACER_VERSION_STR "1.3.0"

#include <odb/post.hxx>

#endif // ODB_TRACER_VERSION_HXX
