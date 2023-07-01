#!/usr/bin/env bash 
rm CMakeCache.txt
cmake ./.. -G "Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug
