#!gmake
#
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

include $(DEPTH)/config/config.mk

ifdef NSJVM
DIRS		= classes
endif

MODULE		= java
LIBRARY_NAME	= jsj

REQUIRES	= java js applet nspr img util layer xpcom

CSRCS = jsj.c		  \
	jsj_JSObject.c	  \
	jsj_JavaArray.c	  \
	jsj_JavaClass.c	  \
	jsj_JavaMember.c  \
	jsj_JavaObject.c  \
	jsj_JavaPackage.c \
	jsj_array.c	  \
	jsj_class.c	  \
	jsj_convert.c	  \
	jsj_field.c	  \
	jsj_hash.c	  \
	jsj_method.c	  \
	jsj_utils.c		\
    nsCLiveconnect.c          \
	nsCLiveconnectFactory.c


LLIBS=$(LIBNSPR) $(DIST)/lib/js$(MOZ_BITS)$(VERSION_NUMBER).lib \
 $(DIST)/lib/xpcom32.lib	


ifdef NSJVM
JNI_GEN		= netscape.javascript.JSObject netscape.javascript.JSException
endif

EXPORTS		= jsjava.h \
		  $(JNI_GEN_DIR)/netscape_javascript_JSObject.h \
		  $(JNI_GEN_DIR)/netscape_javascript_JSException.h \
		  nsILiveconnect.h \
		  $(NULL)



include $(DEPTH)/config/rules.mk

######################################################################

# Generate jsj_nodl.c (so that you can check it in)
# These make rules only works on IRIX...sigh

ifeq ($(OS_ARCH),IRIX)
jsj_nodl.c: $(OBJDIR)/stubs.o Makefile $(DEPTH)/config/nodl.pl
	rm -f $@
	$(PERL) $(DEPTH)/config/nodl.pl "jsj_nodl_tab" \
	    `nm -Bn $(OBJDIR)/stubs.o | egrep Java_.*_stub | awk '{print $$3;}'` > $@
endif

ifdef JAVA_OR_OJI
$(OBJDIR)/stubs.o:					 \
	$(JNI_GEN_DIR)/netscape_javascript_JSObject.c	 \
	$(JNI_GEN_DIR)/netscape_javascript_JSException.c \
	$(NULL)
else
$(OBJDIR)/stubs.o:
endif

