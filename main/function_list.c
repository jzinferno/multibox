#include "multibox.h"

char *function_list[] = {
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


void print_function(void)
{
  int terminal_width = get_terminal_width();
  int str_width = 0;

  for (int i = 0; i < function_count; i++) {
    int wrd_width = strlen(function_list[i]) + 2;

    if (str_width >= terminal_width - wrd_width) {
      printf(",\n");
      str_width = 0;
    }
    if (str_width == 0) {
      putchar('\t');
      str_width += 6;
    } else {
      printf(", ");
    }
    printf("%s", function_list[i]);
    str_width += wrd_width;
  }
  putchar('\n');
}

void print_function_list(void)
{
  for (int i = 0; i < function_count; i++) {
    printf("%s\n", function_list[i]);
  }
}
