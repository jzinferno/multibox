#include "jzinferno.h"

static void usage(void) {
	puts("usage: getenforce");
}

int getenforce_main(int argc, char **argv) {
	if (argv[1]) {
		usage();
	} else if (file_or_dir_exists(ENFORCE_FILE) == 1) {
		char selinux_status;
		FILE *selinux_file = open_file_for_read(ENFORCE_FILE);
		if (selinux_file == NULL) {
			selinux_status = '1';
		} else {
			selinux_status = fgetc(selinux_file);
			fclose(selinux_file);
		}
		if (selinux_status == '1') {
			puts("Enforcing");
		} else {
			puts("Permissive");
		}
	} else {
		puts("Disabled");
	}
	return 0;
}
