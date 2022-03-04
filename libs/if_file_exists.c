#include "multibox.h"

int if_file_exists(char *file)
{
  struct stat buffer;
  if (stat(file, &buffer) == 0) {
    return 1;
  }
  return 0;
}
