#!/bin/bash

DIR="$(cd "$(dirname "$0")" && pwd)"/..
cd $DIR

funcc() {
  for p in multibox .config include/autoconf.h */*.o; do
    if [ -f $p ]; then
      echo -n $p' '
    fi
  done
}

echo "rm -rf $(funcc)"
rm -rf $(funcc)
