#include "multibox.h"

static void usage(void)
{
  printf("usage: selinuxenabled\n");
}

int selinuxenabled_main(int argc, char **argv)
{
  if (argv[1]) {
    usage();
  }
  return !selinux_enabled_status();
}
