#!/bin/bash

DIR="$(cd "$(dirname "$0")" && pwd)"/..
cd $DIR

if [ ! -f $DIR/.config ]; then
  echo "  GEN   .config"
  cp $DIR/configs/defconfig $DIR/.config
fi

source $DIR/.config

CC=gcc
STRIP=strip
CFLAGS=$CONFIG_CFLAGS
LDFLAGS=$CONFIG_LDFLAGS
LDFILES=""

if [ $CONFIG_STATIC = "y" ]; then
  LDFLAGS=$LDFLAGS" -static"
fi

cc_file() {
  mkdir -p $DIR/obj $(dirname $DIR/obj/$2)
  echo "  CC    $2"
  $CC -Iinclude $CFLAGS -c $1 -o $DIR/obj/$2
  LDFILES=$LDFILES" $DIR/obj/$2"
}

gen_config() {
  echo "  GEN   include/config.h"
  rm -rf $1 && touch $1
  echo -e "#define CONFIG_EXTRAVERSION\t\"$CONFIG_EXTRAVERSION\"" >> $1

  if [ $CONFIG_GETENFORCE == "y" ]; then
    echo -e "#define CONFIG_GETENFORCE\t1" >> $1
  fi

  if [ $CONFIG_SELINUXENABLED == "y" ]; then
    echo -e "#define CONFIG_SELINUXENABLED\t1" >> $1
  fi

  if [ $CONFIG_SETENFORCE == "y" ]; then
    echo -e "#define CONFIG_SETENFORCE\t1" >> $1
  fi
}

gen_config $DIR/include/config.h

cc_file main/function_list.c main/function_list.o
cc_file main/main.c main/main.o
cc_file main/multibox.c main/multibox.o
cc_file libs/file_exists.c libs/file_exists.o
cc_file libs/get_terminal_size.c libs/get_terminal_size.o
cc_file libs/open_file.c libs/open_file.o

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
$CC -w $LDFLAGS $LDFILES -o $DIR/obj/multibox
cp $DIR/obj/multibox $DIR/multibox
$STRIP --strip-unneeded multibox
