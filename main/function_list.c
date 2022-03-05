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

void print_all_function(void) {
	int terminal_width = get_terminal_width();
	int str_width = 0;
	int wrd_width = 0;
	printf("Available functions [%d]:\n", function_count);
	for (int i = 0; i < function_count; i++) {
		wrd_width = strlen(function_list[i]) + 2;
		if (str_width >= terminal_width - wrd_width) {
			putchar(',');
			putchar('\n');
			str_width = 0;
		}
		if (str_width == 0) {
			putchar('\t');
			str_width = 6;
		}
		else {
			putchar(',');
			putchar(' ');
		}
		printf("%s", function_list[i]);
		str_width += wrd_width;
	}
	putchar('\n');
}

void print_function_list(void) {
	for (int i = 0; i < function_count; i++) {
		puts(function_list[i]);
	}
}