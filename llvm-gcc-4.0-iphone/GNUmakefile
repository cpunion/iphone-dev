# APPLE LOCAL file build machinery
# Apple GCC Compiler Makefile for use by buildit.  
#
# This makefile is intended only for use with B&I buildit. For "normal"
# builds use the conventional FSF top-level makefile.
#
# You can specify TARGETS=ppc (or i386) on the buildit command line to 
# limit the build to just one target.  The default is for ppc and i386. 
# The compiler targetted at this host gets built anyway, but not installed
# unless it's listed in TARGETS.

# Include the set of standard Apple makefile definitions.
ifndef CoreOSMakefiles
CoreOSMakefiles = $(MAKEFILEPATH)/CoreOS
endif
include $(CoreOSMakefiles)/Standard/Standard.make

# Enable Apple extensions to (gnu)make.
USE_APPLE_PB_SUPPORT = all

RC_ARCHS := ppc i386
HOSTS = $(RC_ARCHS)
targets = echo $(RC_ARCHS)
TARGETS := $(shell $(targets))

SRCROOT = .

SRC = `cd $(SRCROOT) && pwd | sed s,/private,,`
OBJROOT = $(SRC)/obj
SYMROOT = $(OBJROOT)/../sym
DSTROOT = $(OBJROOT)/../dst

PREFIX = /usr

#######################################################################

# APPLE LOCAL begin LLVM
# LLVM defaults to enabled.
ifndef DISABLE_LLVM
ENABLE_LLVM = true
# LLVM gets installed into /usr/local, not /usr.
PREFIX = /usr/local/llvm-gcc-install
else
ENABLE_LLVM = false
endif

# Unless assertions are forced on in the GMAKE command line, disable them.
ifdef ENABLE_ASSERTIONS
LLVM_ASSERTIONS := yes
else
LLVM_ASSERTIONS := no
endif

ifndef RC_ProjectSourceVersion
RC_ProjectSourceVersion = 9999
endif

ifndef RC_ProjectSourceSubversion
RC_ProjectSourceSubversion = 00
endif

install: $(OBJROOT) $(SYMROOT) $(DSTROOT)
	cd $(OBJROOT) && \
	  $(SRC)/build_gcc "$(RC_ARCHS)" "$(TARGETS)" \
	    $(SRC) $(PREFIX) $(DSTROOT) $(SYMROOT) $(ENABLE_LLVM) \
	    $(RC_ProjectSourceVersion) $(RC_ProjectSourceSubversion) \
	    $(LLVM_ASSERTIONS)
# APPLE LOCAL end LLVM

# installhdrs does nothing, because the headers aren't useful until
# the compiler is installed.
installhdrs:

# We build and install in one shell script.
build: 

installsrc:
	@echo
	@echo ++++++++++++++++++++++
	@echo + Installing sources +
	@echo ++++++++++++++++++++++
	@echo
	if [ $(SRCROOT) != . ]; then \
	  $(PAX) -rw . $(SRCROOT); \
	fi
	# APPLE LOCAL begin LLVM: Avoid verification error due to binaries in libjava.
	rm -rf "$(SRCROOT)/libjava/"
	find -d "$(SRCROOT)" \( -type d -a -name CVS -o \
	                        -type f -a -name .DS_Store -o \
				-name \*~ -o -name .\#\* \) \
	  -exec rm -rf {} \;

#######################################################################

clean:
	@echo
	@echo ++++++++++++
	@echo + Cleaning +
	@echo ++++++++++++
	@echo
	@if [ -d $(OBJROOT) -a "$(OBJROOT)" != / ]; then \
	  echo '*** DELETING ' $(OBJROOT); \
	  rm -rf $(OBJROOT); \
	fi
	@if [ -d $(SYMROOT) -a "$(SYMROOT)" != / ]; then \
	  echo '*** DELETING ' $(SYMROOT); \
	  rm -rf $(SYMROOT); \
	fi
	@if [ -d $(DSTROOT) -a "$(DSTROOT)" != / ]; then \
	  echo '*** DELETING ' $(DSTROOT); \
	  rm -rf $(DSTROOT); \
	fi

#######################################################################

$(OBJROOT) $(SYMROOT) $(DSTROOT):
	mkdir -p $@

.PHONY: install installsrc clean
