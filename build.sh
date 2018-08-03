#!/system/bin/sh

#================================================================
#   Copyright (C) 2018 macrozhang Ltd. All rights reserved.
#   
#   文件名称：build.sh
#   创 建 者：macrozhang
#   创建日期：2018-07-31
#   描    述：
#
#================================================================

if [ $# -lt 1 ]; then
    FLAG=
elif [ "$1"x = "MinGW"x ]; then
    FLAG="-G 'MinGW Makefiles'"
elif [ "$1"x = "MSYS"x ]; then
    FLAG="-G 'MSYS Makefiles'"
elif [ "$1"x = "Xcode"x ]; then
    FLAG="-G Xcode"
fi

rm -rf build
mkdir -p build
cd build
cmake .. ${FLAG}

[ "${FLAG}"x = ""x ] && make

