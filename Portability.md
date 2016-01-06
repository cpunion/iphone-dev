Feel free to add platforms to this list. Make sure you have successfully compiled and tested a UIKit-based application before stating that the toolchain works properly.

# Supported and tested #

  * Mac OS X 10.4, Intel. An installed Tiger SDK is automatically detected, so the Xcode DMG is not necessary.
  * Mac OS X 10.4, PPC. The Xcode DMG is not necessary here either.
  * Ubuntu Feisty Fawn, Intel.
  * Ubuntu Gusty Gibbon, Intel.
  * Fedora Core, Intel.
  * Gentoo Linux 2007.0, x86\_64. On 64-bit architectures there are currently compilation and linking problems with structs; as a workaround, try the following:
```
export CFLAGS="-m32"
export LDFLAGS="-m32"
```
  * Debian 2.6.18 (thanks tim.schuerewegen)
  * CentOS 4 (thanks gaoxiaojun)

# Supported but untested #

  * Mac OS X 10.5, PPC.

# Supported but currently does not build #

  * Mac OS X 10.5 Intel: http://code.google.com/p/iphone-dev/issues/detail?id=31
  * Windows XP/Cygwin: http://code.google.com/p/iphone-dev/issues/detail?id=40
  * Windows XP/MinGW: http://code.google.com/p/iphone-dev/issues/detail?id=62

# Unsupported #

  * Windows XP/Visual Studio.
