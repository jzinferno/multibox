#include "multibox.h"

int multibox(int argc, char **argv, char *func_name)
{
  if (!func_name) {
    printf(PROGRAM_NAME": error\n");
    return 1;
  }

#ifdef CONFIG_HELLO
  else if (strcmp(func_name, "hello") == 0) {
    return hello_main(argc, argv);
  }
#endif
#ifdef CONFIG_SELINUXENABLED
  else if (strcmp(func_name, "selinuxenabled") == 0) {
    return selinuxenabled_main(argc, argv);
  }
#endif
#ifdef CONFIG_GETENFORCE
  else if (strcmp(func_name, "getenforce") == 0) {
    return getenforce_main(argc, argv);
  }
#endif
#ifdef CONFIG_SETENFORCE
  else if (strcmp(func_name, "setenforce") == 0) {
    return setenforce_main(argc, argv);
  }
#endif

  else {
    printf("%s: not a function\n", func_name);
  }
  return 1;
}
