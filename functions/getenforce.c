#include "multibox.h"

static void usage(void)
{
  printf("usage: getenforce\n");
}

int getenforce_main(int argc, char **argv)
{
  if (argv[1]) {
    usage();
  } else if (selinux_enabled_status() == 1) {
    int selinux_status;
    FILE *selinux_file;
    if ((selinux_file = fopen(ENFORCE_FILE, "r")) == NULL) {
      selinux_status = 1;
    } else {
      fscanf(selinux_file, "%d", &selinux_status);
      fclose(selinux_file);
    }
    if (selinux_status) {
      printf("Enforcing\n");
    } else {
      printf("Permissive\n");
    }
  } else {
    printf("Disabled\n");
  }
  return 0;
}
