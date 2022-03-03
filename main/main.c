#include "multibox.h"

static void usage(void)
{
  printf("usage: "PROGRAM_NAME" [function [arguments]...]\n");
}

int main(int argc, char **argv)
{
  if (strncmp(basename(argv[0]), PROGRAM_NAME, strlen(PROGRAM_NAME)) == 0) {
    if (!argv[1]) {
      usage();
    }
    else if (argv[1][0]=='-' && argv[1][1]=='h' && argv[1][2]=='\0') {
      usage();
    }
    else if (argv[1][0]=='-' && argv[1][1]=='v' && argv[1][2]=='\0') {
      printf(PROGRAM_NAME" "PROGRAM_VERSION"\n");
    }
    else if (argv[1][0]=='-' && argv[1][1]=='l' && argv[1][2]=='\0') {
      if (function_count <= 0) {
        printf("No functions available\n");
      }
      else {
        printf("Available functions [%d]:\n        ", function_count);
        int count = function_count - 1;
        for (int i = 0; i < count; i++) {
          printf("%s, ", function_list[i]);
        }
        printf("%s\n", function_list[count]);
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
