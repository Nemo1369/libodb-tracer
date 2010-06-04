# file      : build/bootstrap.make
# author    : Boris Kolpackov <boris@codesynthesis.com>
# copyright : Copyright (c) 2009-2010 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

project_name := libodb-tracer

# First try to include the bundled bootstrap.make if it exist. If that
# fails, let make search for the external bootstrap.make.
#
build := build-0.3

-include $(dir $(lastword $(MAKEFILE_LIST)))../../$(build)/bootstrap.make

ifeq ($(patsubst %build/bootstrap.make,,$(lastword $(MAKEFILE_LIST))),)
include $(build)/bootstrap.make
endif


# Aliases
#
.PHONY: $(out_base)/         \
        $(out_base)/.test    \
        $(out_base)/.install \
        $(out_base)/.clean

ifdef %interactive%

.PHONY: test install clean

test:    $(out_base)/.test
install: $(out_base)/.install
clean:   $(out_base)/.clean

ifneq ($(filter $(.DEFAULT_GOAL),test install clean),)
.DEFAULT_GOAL :=
endif

endif

# Don't include dependency info for certain targets.
#
define include-dep
$(call -include,$1)
endef

ifneq ($(filter $(MAKECMDGOALS),clean disfigure),)
include-dep =
endif
