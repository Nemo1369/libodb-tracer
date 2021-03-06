# file      : odb/tracer/makefile
# author    : Boris Kolpackov <boris@codesynthesis.com>
# copyright : Copyright (c) 2009-2011 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

include $(dir $(lastword $(MAKEFILE_LIST)))../../build/bootstrap.make

cxx :=               \
exceptions.cxx       \
database.cxx         \
connection.cxx       \
transaction.cxx      \
transaction-impl.cxx

cxx_tun := $(cxx)
cxx_obj := $(addprefix $(out_base)/,$(cxx_tun:.cxx=.o))
cxx_od  := $(cxx_obj:.o=.o.d)

odb_tracer.l             := $(out_base)/odb-tracer.l
odb_tracer.l.cpp-options := $(out_base)/odb-tracer.l.cpp-options

default := $(out_base)/
dist    := $(out_base)/.dist
clean   := $(out_base)/.clean

# Import.
#
$(call import,\
  $(scf_root)/import/libodb/stub.make,\
  l: odb.l,cpp-options: odb.l.cpp-options)

# Build.
#
$(odb_tracer.l): $(cxx_obj) $(odb.l)
$(odb_tracer.l.cpp-options): value := -I$(out_root) -I$(src_root)
$(odb_tracer.l.cpp-options): $(odb.l.cpp-options)

$(cxx_obj) $(cxx_od): $(odb_tracer.l.cpp-options) $(out_base)/details/config.h

$(out_base)/details/config.h: | $(out_base)/details/.
	@echo '/* file      : odb/tracer/details/config.h'               >$@
	@echo ' * author    : automatically generated'                  >>$@
	@echo ' */'                                                     >>$@
	@echo ''                                                        >>$@
	@echo '#ifndef ODB_TRACER_DETAILS_CONFIG_H'                     >>$@
	@echo '#define ODB_TRACER_DETAILS_CONFIG_H'                     >>$@
	@echo ''                                                        >>$@
	@echo ''                                                        >>$@
	@echo '#endif /* ODB_TRACER_DETAILS_CONFIG_H */'                >>$@

$(call include-dep,$(cxx_od),$(cxx_obj),$(out_base)/details/config.h)

# Convenience alias for default target.
#
$(out_base)/: $(odb_tracer.l)

# Dist.
#
$(dist): export sources := $(cxx)
$(dist): export headers = $(subst $(src_base)/,,$(shell find $(src_base) \
-name '*.hxx' -o -name '*.ixx' -o -name '*.txx'))
$(dist): export extra_dist := libodb-tracer-vc9.vcproj \
libodb-tracer-vc10.vcxproj libodb-tracer-vc10.vcxproj.filters
$(dist): export interface_version = $(shell sed -e \
's/^\([0-9]*\.[0-9]*\).*/\1/' $(src_root)/version)

$(dist):
	$(call dist-data,$(sources) $(headers) details/config.h.in)
	$(call meta-vc9proj,libodb-tracer-vc9.vcproj)
	$(call meta-vc10proj,libodb-tracer-vc10.vcxproj)
	$(call meta-automake)

# Clean.
#
$(clean): $(odb_tracer.l).o.clean    \
  $(odb_tracer.l.cpp-options).clean  \
  $(addsuffix .cxx.clean,$(cxx_obj)) \
  $(addsuffix .cxx.clean,$(cxx_od))
	$(call message,rm $$1,rm -f $$1,$(out_base)/details/config.h)

# Generated .gitignore.
#
ifeq ($(out_base),$(src_base))
$(odb_tracer.l): | $(out_base)/.gitignore

$(out_base)/.gitignore: files := details/config.h
$(clean): $(out_base)/.gitignore.clean

$(call include,$(bld_root)/git/gitignore.make)
endif

# How to.
#
$(call include,$(bld_root)/dist.make)
$(call include,$(bld_root)/meta/vc9proj.make)
$(call include,$(bld_root)/meta/vc10proj.make)
$(call include,$(bld_root)/meta/automake.make)

$(call include,$(bld_root)/cxx/o-l.make)
$(call include,$(bld_root)/cxx/cxx-o.make)
$(call include,$(bld_root)/cxx/cxx-d.make)
