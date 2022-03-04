#include "multibox.h"

static void usage(void)
{
  printf("usage: multibox [function [arguments]...]\n\n");
  printf("Options:\n");
  printf("\t-h, --help\tPrint help message.\n");
  printf("\t-l, --list\tPrint list functions.\n");
  printf("\t-v, --version\tPrint version.\n");
  printf("\nAvailable functions [%d]:\n", function_count);
  print_function();
}

int main(int argc, char **argv)
{
  if (strncmp(basename(argv[0]), "multibox", 8) == 0) {
    if (!argv[1]) {
      usage();
    }
    else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
      usage();
    }
    else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
      printf("multibox "PROGRAM_VERSION"\n");
    }
    else if (strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--list") == 0) {
      if (function_count <= 0) {
        printf("No functions available\n");
      }
      else {
        print_function_list();
      }
    }
    else {
      argv[0] = NULL;
      argv++, argc--;
      return multibox(argc, argv, argv[0]);
    }
  }
  else {
    return multibox(argc, argv, basename(argv[0]));
  }
}
