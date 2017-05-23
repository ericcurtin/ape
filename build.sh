#!/bin/bash

set -e

UNAME=$(uname)

if [ "$UNAME" == "Linux" ]; then
  j=$(grep -c ^processor /proc/cpuinfo)
else
  j=$(sysctl -n hw.ncpu)
fi

cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr .
make -j"$j" VERBOSE=1

if [ "$UNAME" == "Linux" ]; then
  cpack
fi

