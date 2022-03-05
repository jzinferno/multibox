#!/bin/bash

DIR="$(cd "$(dirname "$0")" && pwd)"/..
cd $DIR

clean_files="multibox .config include/config.h obj"

echo "rm -rf $clean_files"
rm -rf $clean_files
