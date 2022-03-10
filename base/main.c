#include "jzinferno.h"

int main(int argc, char **argv) {
	if (!strncmp(basename(argv[0]), _PROG_NAME_, strlen(_PROG_NAME_))) {
		if (!argv[1] || !strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
			puts(
				"Usage: "_PROG_NAME_" [function [arguments]...]\n\n"
				"Options:\n"
				"\t-h, --help\tShow this message.\n"
				"\t-i, --install\tInstall functions.\n"
				"\t-l, --list\tShow all functions.\n"
				"\t-v, --version\tShow program version.\n"
			);
			int terminal_width = get_terminal_size("w");
			int str_width = 0,
			wrd_width = 0;
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
					str_width += 6;
				}
				else {
					putchar(',');
					putchar(' ');
				}
				fputs(function_list[i], stdout);
				str_width += wrd_width;
			}
			if (function_count) {
				putchar('\n');
			}
		}
		else if (!strcmp(argv[1], "-i") || !strcmp(argv[1], "--install")) {
			if (argv[2]) {
				char buff[PATH_MAX],
				*path;
				size_t len = readlink("/proc/self/exe", buff, PATH_MAX);
				if (len != -1) {
					buff[len] = '\0';
				}
				for (int i = 0; i < function_count; i++) {
					path = strdup(argv[2]);
					if (strcmp(&path[strlen(path)-1], "/") != 0) {
						strcat(path, "/");
					}
					symlink(buff, strcat(path, function_list[i]));
				}
			}
		}
		else if (!strcmp(argv[1], "-l") || !strcmp(argv[1], "--list")) {
			for (int i = 0; i < function_count; i++) {
				puts(function_list[i]);
			}
		}
		else if (!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version")) {
			puts(_VERSION_);
		}
		else {
			argv[0] = NULL;
			argv++;
			argc--;
			return run_util_function(argc, argv, argv[0]);
		}
	}
	else {
		return run_util_function(argc, argv, basename(argv[0]));
	}
}
