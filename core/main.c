#include "jzinferno.h"

int main(int argc, char *argv[]) {
	char *applet_name = basename(argv[0]);

	if (!strncmp(applet_name, "busybox", 7)) {



		if (!argv[1] || !strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
			puts(
				"Usage: busybox [function [arguments]...]\n\n"
				"Options:\n"
				"\t-h, --help\tShow this message.\n"
				"\t-i, --install\tInstall functions.\n"
				"\t-l, --list\tShow all functions.\n"
				"\t-v, --version\tShow program version.\n"
			);
			int terminal_width = get_terminal_size("w");
			int str_width = 0;
			int wrd_width = 0;
			puts("Currently defined functions:");
			for (int i = 0; i < applets_count; i++) {
				wrd_width = strlen(applets_table[i]) + 2;
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
				fputs(applets_table[i], stdout);
				str_width += wrd_width;
			}
			if (applets_count) {
				putchar('\n');
			}
			return 0;
		}



		if (!strcmp(argv[1], "-i") || !strcmp(argv[1], "--install")) {
			if (argv[2]) {
				char buff[4096],
				*path;
				int len = readlink("/proc/self/exe", buff, sizeof(buff));
				if (len != -1) {
					buff[len] = '\0';
				}
				for (int i = 0; i < applets_count; i++) {
					path = strdup(argv[2]);
					if (strcmp(&path[strlen(path)-1], "/") != 0) {
						strcat(path, "/");
					}
					symlink(buff, strcat(path, applets_table[i]));
				}
			}
			return 0;
		}



		if (!strcmp(argv[1], "-l") || !strcmp(argv[1], "--list")) {
			for (int i = 0; i < applets_count; i++) {
				puts(applets_table[i]);
			}
			return 0;
		}



		if (!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version")) {
			puts("v1.0.0-beta");
			return 0;
		}


		argv++;
		argc--;
		applet_name = argv[0];
	}

	for (int i = 0; i < applets_count; i++) {
		if (!strcmp(applet_name, applets_table[i])) {
			return (*applets[i])(argc, argv);
		}
	}

	printf("%s: applet not found\n", applet_name);
	return 1;
}