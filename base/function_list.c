#include "jzinferno.h"

char *function_list[] = {
	#ifdef _GETENFORCE_
	"getenforce",
	#endif
	#ifdef _SELINUXENABLED_
	"selinuxenabled",
	#endif
	#ifdef _SETENFORCE_
	"setenforce",
	#endif
};

int function_count = sizeof(function_list) / sizeof(char*);

void print_all_function(void) {
	int terminal_width = get_terminal_width(), str_width = 0, wrd_width = 0;
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
	if (function_count) {
		putchar('\n');
	}
}

void print_function_list(void) {
	for (int i = 0; i < function_count; i++) {
		puts(function_list[i]);
	}
}
