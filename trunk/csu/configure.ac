#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(iphone-dev-csu, 0.30, pcwalton@uchicago.edu)

AC_PREFIX_DEFAULT(/usr/local/arm-apple-darwin)

AC_ARG_ENABLE(bootstrap,
    AS_HELP_STRING([--enable-bootstrap],
        [build from source instead of using binaries (default: disabled)]),
    bootstrap=$enable_bootstrap,
    bootstrap=no)

AC_PROG_INSTALL

AC_CONFIG_SRCDIR([crt.c])
AC_CONFIG_FILES([Makefile])

if test "$bootstrap" = "yes"
then
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
fi

AC_OUTPUT

