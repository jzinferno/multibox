#include "jzinferno.h"

void getenforce_usage(void) {
	puts(
		"Usage: getenforce"
	);
}

int getenforce_main(int argc, char **argv) {
	if (file_or_dir_exist(ENFORCE_FILE) == 1) {
		char selinux_status;
		FILE *selinux_file = fopen(ENFORCE_FILE, "r");
		if (selinux_file == NULL) {
			selinux_status = '1';
		}
		else {
			selinux_status = fgetc(selinux_file);
			fclose(selinux_file);
		}
		if (selinux_status == '1') {
			puts("Enforcing");
		}
		else {
			puts("Permissive");
		}
	}
	else {
		puts("Disabled");
	}
	return 0;
}