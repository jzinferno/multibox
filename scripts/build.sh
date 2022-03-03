#!/bin/bash

DIR="$(cd "$(dirname "$0")" && pwd)"/..
cd $DIR

if [ ! -f $DIR/.config ]; then
  echo ".config not found!"
  exit 0
fi

source $DIR/.config

CC=gcc
CFLAGS=$CONFIG_CFLAGS
LDFLAGS=$CONFIG_LDFLAGS
LDFILES=""

if [ $CONFIG_STATIC == "y" ]; then
  LDFLAGS=$LDFLAGS" -static"
fi

cc_file() {
  echo "  CC    $2"
  $CC -w -Iinclude $CFLAGS -c $1 -o $2
  LDFILES=$LDFILES" $2"
}

gen_file() {
  if [ $2 == "y" ]; then
    status=1
  else
    status=0
  fi
  echo "#define "$1" "$status >> $DIR/include/autoconf.h
}

gen_string() {
  echo "#define $1 \"$2\"" >> $DIR/include/autoconf.h
}

rm -rf $DIR/include/autoconf.h
echo "  GEN   include/autoconf.h"
gen_string CONFIG_EXTRAVERSION $CONFIG_EXTRAVERSION

gen_file CONFIG_HELLO $CONFIG_HELLO
gen_file CONFIG_GETENFORCE $CONFIG_GETENFORCE
gen_file CONFIG_SELINUXENABLED $CONFIG_SELINUXENABLED
gen_file CONFIG_SETENFORCE $CONFIG_SETENFORCE

cc_file main/function_list.c main/function_list.o
cc_file main/main.c main/main.o
cc_file main/multibox.c main/multibox.o
cc_file libs/selinux_enabled_status.c libs/selinux_enabled_status.o

if [ $CONFIG_HELLO == "y" ]; then
  cc_file functions/hello.c functions/hello.o
fi

if [ $CONFIG_GETENFORCE == "y" ]; then
  cc_file functions/getenforce.c functions/getenforce.o
fi

if [ $CONFIG_SELINUXENABLED == "y" ]; then
  cc_file functions/selinuxenabled.c functions/selinuxenabled.o
fi

if [ $CONFIG_SETENFORCE == "y" ]; then
  cc_file functions/setenforce.c functions/setenforce.o
fi

echo "  LD    multibox"
$CC -w $LDFLAGS -s $LDFILES -o multibox
