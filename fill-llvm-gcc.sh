#!/bin/bash
local_only=no
version=4.0

while getopts "lr:" the_option
do
    case the_option in
        l)  local_only=yes  ;;
        r)  version=$OPTARG ;;
    esac
done

if test -e llvm-gcc-$version
then
    if test $local_only = yes
    then
        echo "I found the directory llvm-gcc-$version."
    else
        echo "I found the directory llvm-gcc-$version, so I'm going to update "
        echo "it to the newest revision of LLVM-GCC from LLVM's SVN "
        echo "repository."
        svn update llvm-gcc-$version || exit 1
    fi
else
    if test $local_only = yes
    then
        echo "I didn't find the directory llvm-gcc-$version/, and you've "
        echo "requested that I not check the Internet for updates."
        exit 1;
    fi

    echo "I didn't find the llvm-gcc-$version/ directory. I'm going to check"
    echo "out a copy from LLVM's SVN server. If this doesn't work, check it"
    echo "out manually to that directory and rerun this script."
    svn co http://llvm.org/svn/llvm-project/llvm-gcc-$version/trunk \
        llvm-gcc-$version
fi

echo "Finding files in LLVM-GCC..."
pushd llvm-gcc-$version
find * -not -path "*.svn*" -not -name llvm-gcc-$version -print > \
    ../llvm-gcc-$version-files.tmp
popd

echo "Copying files..."
while read f
do
    if test -e "llvm-gcc-iphone/$f"
    then
        echo "Skipping $f"
    else
        if test -d "llvm-gcc-$version/$f"
        then
            echo "Making directory llvm-gcc-iphone/$f"
            mkdir -p "llvm-gcc-iphone/$f" || exit 1
        else
            echo "Copying llvm-gcc-$version/$f to llvm-gcc-iphone/$f"
            cp "llvm-gcc-$version/$f" "llvm-gcc-iphone/$f" || exit 1
        fi
    fi
done < llvm-gcc-$version-files.tmp

echo "Removing temporary files..."
rm -f llvm-gcc-$version-files.tmp

echo "All done!"

