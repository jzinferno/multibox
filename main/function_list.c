#include "multibox.h"

char *function_list[] = {
#ifdef CONFIG_HELLO
  "hello",
#endif
#ifdef CONFIG_GETENFORCE
  "getenforce",
#endif
#ifdef CONFIG_SELINUXENABLED
  "selinuxenabled",
#endif
#ifdef CONFIG_SETENFORCE
  "setenforce",
#endif
};

int function_count = sizeof(function_list) / sizeof(char*);
