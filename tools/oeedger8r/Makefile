#
# Copyright (C) 2011-2018 Intel Corporation. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#   * Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#   * Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in
#     the documentation and/or other materials provided with the
#     distribution.
#   * Neither the name of Intel Corporation nor the names of its
#     contributors may be used to endorse or promote products derived
#     from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#

# include ../../../buildenv.mk

OCAML_VERSION_MAJOR=$(shell ocamlopt -version | head -n  1 | cut -d . -f 1)
OCAML_VERSION_MINOR=$(shell ocamlopt -version | head -n  1 | cut -d . -f 2)
OCAML_VERSION=$(OCAML_VERSION_MAJOR)$(OCAML_VERSION_MINOR)

CUR_DIR=$(shell pwd)
BUILD_DIR=$(CUR_DIR)/dist
CP=cp
MKDIR=mkdir

.PHONY: all
all: build | $(BUILD_DIR)
	@$(CP) $(CUR_DIR)/_build/main.native $(BUILD_DIR)/oeedger8r

.PHONY: build
build:
# ocaml 4.02 - added support for PIC
ifeq ($(shell test $(OCAML_VERSION) -lt 402 && echo 1), 1)
	ocamlbuild -I intel -lflag -ccopt -lflag "-Wl,-z,now" -no-links -libs str,unix  main.native
else
	ocamlbuild -I intel -cflags -ccopt,-fpie -lflags -runtime-variant,_pic,-ccopt,-pie,-ccopt -lflag "-Wl,-z,now"  -no-links -libs str,unix main.native
endif

$(BUILD_DIR):
	@$(MKDIR) $@

.PHONY:
clean:
	@ocamlbuild Edger8rOE.native -clean
	@$(RM) $(BUILD_DIR)/oeedger8r