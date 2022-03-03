#include "autoconf.h"

#if CONFIG_HELLO != 1
#undef CONFIG_HELLO
#endif

#if CONFIG_SELINUXENABLED != 1
#undef CONFIG_SELINUXENABLED
#endif

#if CONFIG_GETENFORCE != 1
#undef CONFIG_GETENFORCE
#endif

#if CONFIG_SETENFORCE != 1
#undef CONFIG_SETENFORCE
#endif

#ifdef CONFIG_HELLO
int hello_main(int argc, char **argv);
#endif

#ifdef CONFIG_SELINUXENABLED
int selinuxenabled_main(int argc, char **argv);
#endif

#ifdef CONFIG_GETENFORCE
int getenforce_main(int argc, char **argv);
#endif

#ifdef CONFIG_SETENFORCE
int setenforce_main(int argc, char **argv);
#endif

#ifndef CONFIG_EXTRAVERSION
#define CONFIG_EXTRAVERSION ""
#endif

#define PROGRAM_NAME "multibox"
#define PROGRAM_VERSION "0.0.0"CONFIG_EXTRAVERSION
