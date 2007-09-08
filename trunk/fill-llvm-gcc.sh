#!/bin/bash
if getopts "l" the_option
then
    local_only=yes
else
    local_only=no
fi

if test -e llvm-gcc-4.2
then
    if test $local_only = yes
    then
        echo "I found the directory llvm-gcc-4.2."
    else
        echo "I found the directory llvm-gcc-4.2, so I'm going to update it"
        echo "to the newest revision of LLVM-GCC from LLVM's SVN repository."
        svn update llvm-gcc-4.2 || exit 1
    fi
else
    if test $local_only = yes
    then
        echo "I didn't find the directory llvm-gcc-4.2/, and you've requested"
        echo "not to check the Internet for updates."
        exit 1;
    fi

    echo "I didn't find the llvm-gcc-4.2/ directory. I'm going to check out a"
    echo "copy from LLVM's SVN server. If this doesn't work, check it out"
    echo "manually to that directory and rerun this script."
    svn co http://llvm.org/svn/llvm-project/llvm-gcc-4.2/trunk llvm-gcc-4.2
fi

echo "Finding files in LLVM-GCC..."
find llvm-gcc-4.2 -not -path "*.svn*" -and -not -name llvm-gcc-4.2 -and -not \
    -path "*/libstdc++-v3/*" -and -not -name libstdc++-v3 -print > \
    llvm-gcc-4.2-files.tmp

echo "Mangling names..."
sed -E -i '' -e s!^[^/]+/!! llvm-gcc-4.2-files.tmp

echo "Copying files..."
for f in `cat llvm-gcc-4.2-files.tmp`
do
    if test -e "llvm-gcc-iphone/$f"
    then
        echo "Skipping $f"
    else
        if test -d "llvm-gcc-4.2/$f"
        then
            echo "Making directory llvm-gcc-iphone/$f"
            mkdir -p "llvm-gcc-iphone/$f" || exit 1
        else
            echo "Copying llvm-gcc-4.2/$f to llvm-gcc-iphone/$f"
            cp "llvm-gcc-4.2/$f" "llvm-gcc-iphone/$f" || exit 1
        fi
    fi
done

echo "Removing temporary files..."
rm -f llvm-gcc-4.2-files.tmp

echo "All done!"

