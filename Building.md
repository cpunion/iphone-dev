Please note that these instructions are subject to change. Before updating your toolchain installation, you should always check the newest version of this page. You should also check [Portability](Portability.md) to see whether there are any special instructions for your particular platform.

**FILE BUG REPORTS TO REPORT BUGS INSTEAD OF LEAVING BUGS AS COMMENTS ON THIS PAGE! THIS MEANS THAT IF THE TOOLCHAIN DOES NOT BUILD FOR YOU, DO NOT LEAVE A COMMENT HERE!**

# HOWTO build the toolchain #

  * Ensure that you have a copy of `bison` and `flex` installed on your system. All major systems should have these tools installed or available in package management systems.
```
$ bison --version
GNU Bison version 1.28
$ flex --version
flex version 2.5.4
```

  * Check out a copy of LLVM _SVN_, and build a _release_ build (as opposed to a debug one). Currently, due to [Issue 70](https://code.google.com/p/iphone-dev/issues/detail?id=70), we are limited to [revision 42498](https://code.google.com/p/iphone-dev/source/detail?r=42498).
```
$ svn co http://llvm.org/svn/llvm-project/llvm/trunk llvm-svn -r 42498
$ pushd llvm-svn
$ ./configure --enable-optimized
$ make ENABLE_OPTIMIZED=1
$ sudo make install
$ LLVMOBJDIR=`pwd`
$ popd
```

  * Check out a copy of the iphone-dev SVN repository.
```
$ svn checkout http://iphone-dev.googlecode.com/svn/trunk/ iphone-dev
$ pushd iphone-dev
```

  * Make a directory to hold the toolchain.
```
$ sudo mkdir /usr/local/arm-apple-darwin
```

  * Build odcctools.
```
$ mkdir -p build/odcctools
$ pushd build/odcctools
$ ../../odcctools/configure --target=arm-apple-darwin --disable-ld64
$ make
$ sudo make install
$ popd
```

  * Get a copy of the iPhone root filesystem. This is usually obtained by decrypting and extracting the iPhone restore software using [these tools](http://iphone.fiveforty.net/wiki/index.php/Break_DMG_Password), but there are many other methods to obtain this, including simply using `scp` to download all the files from the iPhone over Wi-Fi. Unpack the root filesystem somewhere, and set the environment variable `$HEAVENLY` to its path.
```
$ HEAVENLY=/usr/local/share/iphone-filesystem
```

  * Install the iPhone headers to the appropriate place. If you aren't on Mac OS X, replace the `/Developer/SDKs/MacOSX10.4u.sdk` path with the full path to the unpacked Mac OS X 10.4 Universal SDK. If you don't have a copy of this, see below.
```
$ pushd include
$ ./configure --with-macosx-sdk=/Developer/SDKs/MacOSX10.4u.sdk
$ sudo bash install-headers.sh
$ popd
```

  * Install csu, which includes `crt1.o`, `dylib1.o`, and `bundle1.o`. Don't rebuild them from source, as this requires a working cross-GCC, which you don't have yet (and the build-from-source process for csu is broken right now anyway). Binaries are provided for this reason.
```
$ mkdir -p build/csu
$ pushd build/csu
$ ../../csu/configure --host=arm-apple-darwin
$ sudo make install
$ popd
```

  * **Only** if you are compiling on **leopard** 10.5. This is an ugly workaround and compiling with the resulting toolchain will give you a warning.
```
$ mv llvm-gcc-4.0-iphone/configure llvm-gcc-4.0-iphone/configure.old
$ sed 's/^FLAGS_FOR_TARGET=$/FLAGS_FOR_TARGET=${FLAGS_FOR_TARGET-}/g' \ 
llvm-gcc-4.0-iphone/configure.old > llvm-gcc-4.0-iphone/configure
$ export FLAGS_FOR_TARGET="-mmacosx-version-min=10.1"
$ sudo ln -s /usr/local/arm-apple-darwin/lib/crt1.o \
/usr/local/arm-apple-darwin/lib/crt1.10.5.o
```

  * Configure and make LLVM-GCC. Make sure that `$LLVMOBJDIR` and `$HEAVENLY` are set per the instructions above.
```
$ mkdir -p build/llvm-gcc-4.0-iphone
$ pushd build/llvm-gcc-4.0-iphone
$ ../../llvm-gcc-4.0-iphone/configure --enable-llvm=`llvm-config --obj-root` \
--enable-languages=c,c++,objc,obj-c++ --target=arm-apple-darwin --enable-sjlj-exceptions \
--with-heavenly=$HEAVENLY --with-as=/usr/local/bin/arm-apple-darwin-as \
--with-ld=/usr/local/bin/arm-apple-darwin-ld --enable-wchar_t=no
$ make LLVM_VERSION_INFO=2.0-svn-iphone-dev-0.3-svn 
$ sudo make install
$ popd
$ popd
```

  * You're done. Have fun!

# HOWTO obtain the Mac OS X headers on Linux or Windows #

  * Install the `cpio` utility using your distribution's standard package management system. All the major Linux distributions, as well as Cygwin, should have this utility.
  * Download the Xcode DMG from [Apple's Developer Tools download page](http://developer.apple.com/tools/download/). It is free, but you will need to register with them. It is also huge (~924 MB).
  * Extract the `Packages/MacOSX10.4.Universal.pkg` directory from the Xcode DMG. Do not use the Linux kernel's HFS+ loopback mount: it does not support the format used by this DMG, and your files will be corrupted. One program that is known to work is [PowerISO](http://www.poweriso.com/), although it isn't free.
  * Extract the `pax` archive inside the Mac OS X 10.4 SDK package.
```
mkdir MacOSX10.4-Universal-SDK
pushd MacOSX10.4-Universal-SDK
gunzip -c ../MacOSX10.4.Universal.pkg/Contents/Archive.pax.gz | cpio -i
popd
```
  * The SDK files should now live in `MacOSX10.4-Universal-SDK/Developer/SDKs/MacOSX10.4u.sdk` in the current directory. You'll pass the path to this directory to the configure script in the `include` directory. Feel free to get rid of the Xcode DMG and the package directory now.

# Gotchas #

  * Make sure that there are no spaces in any of the directory names that you use. GCC does not build if there are spaces in the directory names, and the shell scripts will not work. This is most often a problem on Windows.
  * Make sure that `/usr/local/bin` is in your `PATH`. This is not the case out of the box on Mac OS X, although chances are if you've installed things from source before you've added it already.
  * If LLVM failed to compile because of missing `bison` and/or `flex` (evidence that this was the case is a failed compile on `utils/TableGen/FileLexer.l`), you must `make clean` _and_ delete `utils/TableGen/FileParser.h` before trying again with `bison` and `flex` installed. LLVM's `make clean` script does not always properly clean up after a failed build.
  * Make sure that `$HEAVENLY` points to a copy of the full iPhone root filesystem, not just the unpacked update DMG. If you get errors about being unable to find `-lc`, then your `$HEAVENLY` is set incorrectly, you mistyped the `--with-heavenly` option to `configure`, or your copy of the root partition is incomplete. Your copy of the iPhone root filesystem _must_ include a `usr/lib/libc.dylib` file.
