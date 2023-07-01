#!/usr/bin/env bash 
rm CMakeCache.txt
echo "Make sure to set the target build system appropriately"
cmake ./.. -G "Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug

