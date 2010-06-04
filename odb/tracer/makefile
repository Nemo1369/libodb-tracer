# file      : odb/tracer/makefile
# author    : Boris Kolpackov <boris@codesynthesis.com>
# copyright : Copyright (c) 2009-2010 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

include $(dir $(lastword $(MAKEFILE_LIST)))../../build/bootstrap.make

cxx_tun   := database.cxx transaction.cxx transaction-impl.cxx
cxx_obj   := $(addprefix $(out_base)/,$(cxx_tun:.cxx=.o))
cxx_od    := $(cxx_obj:.o=.o.d)

odb_tracer.l             := $(out_base)/odb-tracer.l
odb_tracer.l.cpp-options := $(out_base)/odb-tracer.l.cpp-options

default   := $(out_base)/
install   := $(out_base)/.install
clean     := $(out_base)/.clean

# Import.
#
$(call import,\
  $(scf_root)/import/libodb/stub.make,\
  l: odb.l,cpp-options: odb.l.cpp-options)

# Build.
#
$(odb_tracer.l): $(cxx_obj) $(odb.l)
$(odb_tracer.l.cpp-options): value := -I$(src_root)
$(odb_tracer.l.cpp-options): $(odb.l.cpp-options)

$(cxx_obj) $(cxx_od): $(odb_tracer.l.cpp-options)

$(call include-dep,$(cxx_od))

# Convenience alias for default target.
#
$(out_base)/: $(odb_tracer.l)

# Install.
#
$(install): $(odb_tracer.l)
	$(call install-lib,$<,$(install_lib_dir)/$(ld_lib_prefix)odb-tracer$(ld_lib_suffix))
	$(call install-dir,$(src_base),$(install_inc_dir)/odb/tracer,\
'(' -name '*.hxx' -o -name '*.ixx' -o -name '*.txx' ')')

# Clean.
#
$(clean): $(odb_tracer.l).o.clean    \
  $(odb_tracer.l.cpp-options).clean  \
  $(addsuffix .cxx.clean,$(cxx_obj)) \
  $(addsuffix .cxx.clean,$(cxx_od))

# How to.
#
$(call include,$(bld_root)/cxx/o-l.make)
$(call include,$(bld_root)/cxx/cxx-o.make)
$(call include,$(bld_root)/cxx/cxx-d.make)
