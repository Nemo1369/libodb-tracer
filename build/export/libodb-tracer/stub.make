# file      : build/export/libodb-tracer/stub.make
# author    : Boris Kolpackov <boris@codesynthesis.com>
# copyright : Copyright (c) 2009-2010 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

$(call include-once,$(src_root)/odb/tracer/makefile,$(out_root))

$(call export,\
  l: $(out_root)/odb/tracer/odb-tracer.l,\
  cpp-options: $(out_root)/odb/tracer/odb-tracer.l.cpp-options)
