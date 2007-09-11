#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(iphone-dev-csu, 0.30, pcwalton@uchicago.edu)
AM_INIT_AUTOMAKE(iphone-dev-csu, 0.30)

AC_PREFIX_DEFAULT(/usr/local/arm-apple-darwin)

AC_CONFIG_SRCDIR([crt.c])
AM_CONFIG_HEADER(config.h)
AC_CONFIG_FILES([Makefile])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stddef.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

# Checks for library functions.
AC_CHECK_FUNCS([atexit])
AC_OUTPUT

