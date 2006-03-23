/* $FreeBSD$ */
/* Base configuration file for all FreeBSD targets.
   Copyright (C) 1999 Free Software Foundation, Inc.

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* Common FreeBSD configuration. 
   All FreeBSD architectures should include this file, which will specify
   their commonalities.
   Adapted from /usr/src/contrib/gcc/config/i386/freebsd.h & 
   egcs/gcc/config/i386/freebsd-elf.h version by David O'Brien  */


/* Don't assume anything about the header files.  */
#undef NO_IMPLICIT_EXTERN_C
#define NO_IMPLICIT_EXTERN_C

/* This defines which switch letters take arguments.  On FreeBSD, most of
   the normal cases (defined in gcc.c) apply, and we also have -h* and
   -z* options (for the linker) (comming from svr4).
   We also have -R (alias --rpath), no -z, --soname (-h), --assert etc.  */

#define FBSD_SWITCH_TAKES_ARG(CHAR)					\
  (DEFAULT_SWITCH_TAKES_ARG (CHAR)					\
    || (CHAR) == 'h'							\
    || (CHAR) == 'z' /* ignored by ld */				\
    || (CHAR) == 'R')

#undef SWITCH_TAKES_ARG
#define SWITCH_TAKES_ARG(CHAR) (FBSD_SWITCH_TAKES_ARG(CHAR))

#define FBSD_WORD_SWITCH_TAKES_ARG(STR)					\
  (DEFAULT_WORD_SWITCH_TAKES_ARG (STR)					\
   || !strcmp (STR, "rpath") || !strcmp (STR, "rpath-link")		\
   || !strcmp (STR, "soname") || !strcmp (STR, "defsym") 		\
   || !strcmp (STR, "assert") || !strcmp (STR, "dynamic-linker"))

#undef WORD_SWITCH_TAKES_ARG
#define WORD_SWITCH_TAKES_ARG(STR) (FBSD_WORD_SWITCH_TAKES_ARG(STR))

/* Place spaces around this string.  We depend on string splicing to produce
   the final CPP_PREDEFINES value.  */
#define CPP_FBSD_PREDEFINES " -Dunix -D__FreeBSD__ -Asystem(unix) -Asystem(FreeBSD) "

/* Provide a LIB_SPEC appropriate for FreeBSD.  Just select the appropriate
   libc, depending on whether we're doing profiling or need threads support.
   (simular to the default, except no -lg, and no -p).  */

#undef LIB_SPEC
#define LIB_SPEC "%{!shared: \
   %{!pg:%{!pthread:%{!kthread:-lc} \
     %{kthread:-lpthread -lc}} \
     %{pthread:-lc_r}} \
   %{pg:%{!pthread:%{!kthread:-lc_p} \
     %{kthread:-lpthread_p -lc_p}} \
     %{pthread:-lc_r_p}}}"

#ifdef COMMENT_OUT	/* only redefine LIBGCC_SPEC for our native GCC */
/* Tell gcc to locate libgcc.a for us according to the -m rules.  */
#undef LIBGCC_SPEC
#define LIBGCC_SPEC \
 "%{!shared:%{!pthread:%{!kthread:libgcc.a%s}}%{pthread|kthread:libgcc_r.a%s}}"
#endif


/* Code generation parameters.  */

/* Don't default to pcc-struct-return, because gcc is the only compiler, and
   we want to retain compatibility with older gcc versions
   (even though the svr4 ABI for the i386 says that records and unions are
   returned in memory).  */
#undef DEFAULT_PCC_STRUCT_RETURN
#define DEFAULT_PCC_STRUCT_RETURN 0

/* Ensure we the configuration knows our system correctly so we can link with
   libraries compiled with the native cc.  */
#undef NO_DOLLAR_IN_LABEL

/* Use more efficient ``thunks'' to implement C++ vtables.  */
#undef DEFAULT_VTABLE_THUNKS
#define DEFAULT_VTABLE_THUNKS 1


/* Miscellaneous parameters.  */

/* Tell libgcc2.c that FreeBSD targets support atexit(3).  */
#define HAVE_ATEXIT

#ifdef BOOTSTRAP_BOMBS_ON_CURRENT
/* Our malloc can allocte pagesized blocks efficiently.  The default size 
   of 4072 bytes is not optimal on the i386 nor the Alpha.  */
#define OBSTACK_CHUNK_SIZE	(getpagesize())
#endif
