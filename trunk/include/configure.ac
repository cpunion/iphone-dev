AC_PREREQ(2.59)

AC_INIT([iphone-dev-include], [0.30], [pcwalton@uchicago.edu])

AC_PREFIX_DEFAULT(/usr/local/arm-apple-darwin)

AC_PROG_INSTALL

AC_ARG_WITH(macosx-sdk,
    AC_HELP_STRING([--with-macosx-sdk=path],
        [specify location to Mac OS X 10.4u SDK]),
    SDK_LOCATION=$withval,
    AC_CHECK_FILE(/Developer/SDKs/MacOSX10.4u.sdk,
        SDK_LOCATION=/Developer/SDKs/MacOSX10.4u.sdk,
        AC_MSG_ERROR("You must have a copy of the Mac OS X 10.4 Universal SDK. Please see the wiki at http://iphone-dev.googlecode.com/ for information on how to obtain this. If you already have the SDK, use a --with-macosx-sdk=path option to specify the path.")))

AC_SUBST(SDK_LOCATION)

AC_CONFIG_FILES([install-headers.sh])
AC_OUTPUT

