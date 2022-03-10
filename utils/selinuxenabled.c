#include "jzinferno.h"

static void usage(void) {
	puts("usage: selinuxenabled");
}

int selinuxenabled_main(int argc, char **argv) {
	if (argv[1]) {
		usage();
	}
	if (file_or_dir_exist(ENFORCE_FILE) == 1) {
		return 0;
	}
	return 1;
}
