#! gmake
# The contents of this file are subject to the Netscape Public License
# Version 1.0 (the "NPL"); you may not use this file except in
# compliance with the NPL.  You may obtain a copy of the NPL at
# http://www.mozilla.org/NPL/
#
# Software distributed under the NPL is distributed on an "AS IS" basis,
# WITHOUT WARRANTY OF ANY KIND, either express or implied. See the NPL
# for the specific language governing rights and limitations under the
# NPL.
#
# The Initial Developer of this code under the NPL is Netscape
# Communications Corporation.  Portions created by Netscape are
# Copyright (C) 1998 Netscape Communications Corporation.  All Rights
# Reserved.

DEPTH		= ../../..

LIBRARY_NAME	= jsxpcom

ifeq ($(subst /,_,$(shell uname -s)),OS2)
ifndef XCFLAGS
OS2_IMPLIB=1
LIBRARY	= jsxpcom$(MOZ_BITS)$(VERSION_NUMBER).$(LIB_SUFFIX)
DEF_FILE	= jsxpcomos2$(VERSION_NUMBER).def
EXTRA_LIBS	= $(LIBNSPR) $(LIBNSJAVA)
else
EXTRA_LIBS	= $(LIBNSPR) $(LIBNSJAVA) $(OBJDIR)/libjs.lib
endif
endif

MODULE		= jsxpcom

REQUIRES	= xpcom js nspr

CSRCS		= $(NULL)

CPPSRCS		= jxext.cpp \
                  jsContext.cpp \
		  jsRuntime.cpp \
		  jsScriptable.cpp \
		  $(NULL)

PROGCSRCS	= common.c \
		  $(NULL)

PROGCPPSRCS	= jsxpcom.cpp \
		  $(NULL)

PROGOBJS	= $(addprefix $(OBJDIR)/, $(PROGCPPSRCS:.cpp=.o)) \
		  $(addprefix $(OBJDIR)/, $(PROGCSRCS:.c=.o)) \
		  $(NULL)

EXPORTS		= jsIExtension.h \
                  jsIContext.h \
		  jsIRuntime.h \
		  jsIScript.h \
		  jsIScriptable.h \
		  $(NULL)

INCLUDES	+= -I$(PUBLIC)/xpcom -I$(PUBLIC)/js

PROGRAM		= jsxpcom

# use the C++ compiler to do the final link
CPP_PROG_LINK 	= 1

# `libs' just does libs, `install' does programs
LIBS_NEQ_INSTALL = 1

# XXX this is not XP
LDFLAGS += -rdynamic

include $(DEPTH)/config/rules.mk

export::

libs:: $(SHARED_LIBRARY) $(LIBRARY)

install:: $(PROGRAM)

ifndef BUILD_OPT
MOCHAFILE	= 1
endif

ifdef JSFILE
DEFINES		+= -DJSFILE
endif

ifdef JS_THREADSAFE
DEFINES += -DJS_THREADSAFE
endif

ifdef JS_NO_THIN_LOCKS
DEFINES += -DJS_USE_ONLY_NSPR_LOCKS
endif

ifdef JS_VERSION
DEFINES += -DJS_VERSION=$(JS_VERSION)
endif

ifeq ($(CPU_ARCH),sparc)

ifndef JS_NO_ULTRA
ULTRA_OPTIONS := -xarch=v8plus,-DULTRA_SPARC
ULTRA_OPTIONSCC := -DULTRA_SPARC
else
ULTRA_OPTIONS := -xarch=v8
ULTRA_OPTIONSCC :=
endif

ifeq ($(shell uname -m),sun4u)
ASFLAGS	+= -Wa,$(ULTRA_OPTIONS),-P,-L,-D_ASM,-D__STDC__=0 $(ULTRA_OPTIONSCC)
else
ASFLAGS	+= -Wa,-xarch=v8,-P,-L,-D_ASM,-D__STDC__=0
endif

endif # sparc

INCLUDES	+= -I. 

ifndef NSBUILDROOT
JSJAVA_STUBHEADERS = -I$(DEPTH)/sun-java/include/_gen \
		     -I$(DEPTH)/sun-java/netscape/javascript/_jri \
		     -I$(DEPTH)/sun-java/netscape/security/_jri
else
JSJAVA_STUBHEADERS = -I$(JRI_GEN_DIR) -I$(JDK_GEN_DIR)
endif

JSJAVA_CFLAGS	= -I$(DEPTH)/sun-java/md-include \
		  -I$(DEPTH)/sun-java/include \
		  $(JSJAVA_STUBHEADERS)

# LIBNSPR includes unneeded libmsgc21.a, but abstracts nspr version,
# etc. nicely.
LDFLAGS 	+= -L$(DIST)/bin -lxpcom -lreg -ljsxpcom -ljs $(LIBNSPR) -lplc21 -lm

ifeq ($(OS_ARCH), OSF1)
LDFLAGS += -lc_r
endif
ifeq ($(OS_ARCH), SunOS)
LDFLAGS += -lposix4 -ldl -lnsl -lsocket
endif
ifeq ($(OS_ARCH), Linux)
LDFLAGS += -ldl
endif

jsxpcom: $(PROGRAM)

.PHONY: jsxpcom$(BIN_SUFFIX)
