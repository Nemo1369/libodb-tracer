# file      : makefile
# author    : Boris Kolpackov <boris@codesynthesis.com>
# copyright : Copyright (c) 2009-2010 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

include $(dir $(lastword $(MAKEFILE_LIST)))build/bootstrap.make

default  := $(out_base)/
test     := $(out_base)/.test
install  := $(out_base)/.install
clean    := $(out_base)/.clean

# Build.
#
$(default): $(out_base)/odb/tracer/ #$(out_base)/tests/

# Test.
#
$(test): $(out_base)/tests/.test

# Install.
#
$(install): $(out_base)/odb/tracer/.install
	$(call install-data,$(src_base)/LICENSE,$(install_doc_dir)/libodb-tracer/LICENSE)
	$(call install-data,$(src_base)/README,$(install_doc_dir)/libodb-tracer/README)

# Clean.
#
$(clean): $(out_base)/odb/tracer/.clean $(out_base)/tests/.clean

$(call include,$(bld_root)/install.make)

$(call import,$(src_base)/odb/tracer/makefile)
#$(call import,$(src_base)/tests/makefile)
