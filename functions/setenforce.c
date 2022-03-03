#include "multibox.h"

static void usage(void)
{
  printf("usage: setenforce [1|0]\n");
}

int setenforce_main(int argc, char **argv)
{
  int status;
  if (!argv[1] || argv[2]) {
    usage();
    return 1;
  } else if (argv[1][0] == '1' && argv[1][1]=='\0') {
    status = 1;
  } else if (argv[1][0] == '0' && argv[1][1]=='\0') {
    status = 0;
  } else {
    usage();
    return 1;
  }
  if (selinux_enabled_status() == 1) {
    FILE *enforce_file = fopen(ENFORCE_FILE, "w");
    if(enforce_file == NULL) {
      puts("Permission denied!");
      return 1;
    }
    fprintf(enforce_file, "%d", status);
    fclose(enforce_file);
  } else {
    puts("SELinux is disabled!");
    return 1;
  }
  return 0;
}