#!/bin/bash

DIR="$(cd "$(dirname "$0")" && pwd)"/..
cd $DIR

echo "  GEN   .config"
cp configs/defconfig .config
