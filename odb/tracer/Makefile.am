# file      : odb/tracer/Makefile.am
# author    : Boris Kolpackov <boris@codesynthesis.com>
# copyright : Copyright (c) 2009-2011 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

lib_LTLIBRARIES = libodb-tracer.la
libodb_tracer_la_SOURCES = __path__(sources)

odbtracerincludedir = $(includedir)/odb/tracer/
nobase_odbtracerinclude_HEADERS = __path__(headers)
nobase_nodist_odbtracerinclude_HEADERS = details/config.h

EXTRA_DIST = __file__(extra_dist)

AM_CPPFLAGS= -I'$(top_builddir)' -I'$(top_srcdir)' -DLIBODB_TRACER_DYNAMIC_LIB
AM_LDFLAGS = -release __value__(interface_version) -no-undefined
