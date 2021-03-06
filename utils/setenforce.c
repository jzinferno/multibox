#include "jzinferno.h"

void setenforce_usage(void) {
	puts(
		"Usage: setenforce [0|1]"
	);
}

int setenforce_main(int argc, char **argv) {
	char *status;
	if (!argv[1] || argv[2]) {
		setenforce_usage();
		return 1;
	} else if (argv[1][0] == '1' && argv[1][1] == '\0') {
		status = "1";
	} else if (argv[1][0] == '0' && argv[1][1] == '\0') {
		status = "0";
	} else {
		setenforce_usage();
		return 1;
	}
	if (file_or_dir_exist(ENFORCE_FILE) == 1) {
		FILE *enforce_file = fopen(ENFORCE_FILE, "w");
		if(enforce_file == NULL) {
			puts("Permission denied!");
			return 1;
		}
		fputs(status, enforce_file);
		fclose(enforce_file);
	} else {
		puts("SELinux is disabled!");
		return 1;
	}
	return 0;
}