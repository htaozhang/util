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

rm -rf build
mkdir -p build
cd build
cmake .. -G "MSYS Makefiles"


#make

