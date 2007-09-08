#!/bin/bash
if test -e llvm-gcc-4.2
then
    echo "I found the directory llvm-gcc-4.2/, so I'm going to update it to"
    echo "the newest revision of LLVM-GCC from LLVM's SVN repository."
    svn update llvm-gcc-4.2
else
    echo "I didn't find the llvm-gcc-4.2/ directory. I'm going to check out a"
    echo "copy from LLVM's SVN server. If this doesn't work, check it out"
    echo "manually to that directory and rerun this script."
    svn co http://llvm.org/svn/llvm-project/llvm-gcc-4.2/trunk llvm-gcc-4.2
fi

find llvm-gcc-4.2 -not -path "*.svn/*" -print > llvm-gcc-4.2-files.tmp

