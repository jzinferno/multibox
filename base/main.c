#include "multibox.h"

static void usage(void) {
	printf("usage: multibox [function [arguments]...]\n\n");
	printf("Options:\n");
	printf("\t-h, --help\tPrint help message.\n");
	printf("\t-l, --list\tPrint list functions.\n");
	printf("\t-v, --version\tPrint version.\n\n");
	print_all_function();
}

void print_version(void) {
	printf("multibox "_VERSION"\n");
}

int main(int argc, char **argv) {
	if (strncmp(basename(argv[0]), "multibox", 8) == 0) {
		if (!argv[1]) {
			usage();
		}
		else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
			usage();
		}
		else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
			print_version();
		}
		else if (strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--list") == 0) {
			print_function_list();
		}
		else {
			argv[0] = NULL;
			argv++;
			argc--;
			return multibox(argc, argv, argv[0]);
		}
	}
	else {
		return multibox(argc, argv, basename(argv[0]));
	}
}
