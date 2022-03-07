#include "jzinferno.h"

static void usage(void) {
	puts(
		"Usage: "_PROG_NAME_" [function [arguments]...]\n\n"
		"Options:\n"
		"\t-h, --help\tPrint help message.\n"
		"\t-l, --list\tPrint list functions.\n"
		"\t-v, --version\tPrint version.\n"
	);
	print_all_function();
}

int print_version(void) {
	printf(_PROG_NAME_" "_PROG_VERSION_"\n");
	return 0;
}

int main(int argc, char **argv) {
	if (!strncmp(basename(argv[0]), _PROG_NAME_, strlen(_PROG_NAME_))) {
		if (!argv[1]) {
			usage();
		}
		else if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
			usage();
		}
		else if (!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version")) {
			print_version();
		}
		else if (!strcmp(argv[1], "-l") || !strcmp(argv[1], "--list")) {
			print_function_list();
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
