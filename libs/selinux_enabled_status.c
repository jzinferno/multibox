#include "multibox.h"

bool selinux_enabled_status(void)
{
  struct stat buffer;
  return (stat(ENFORCE_FILE, &buffer) == 0);
}
